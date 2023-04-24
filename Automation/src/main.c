#include <gtk/gtk.h>
#include <glib/gi18n.h>

#include "sat-module.h"
#include "gtk-rot-ctrl.h"
#include "sat-cfg.h"
#include "sat-log.h"
#include "time-tools.h"
#include "tle-update.h"

/** Copy satellite from hash table to singly linked list. */
static void print_sats(gpointer key, gpointer value, gpointer user_data)
{
    if (user_data == NULL) {
        return;
    }
    GtkRotCtrl *ctrl = user_data;
    sat_t          *sat = SAT(value);
}

static          gpointer update_tle_thread(gpointer data)
{
    (void)data;

    tle_update_from_network(TRUE);

    return NULL;
}

static gboolean tle_mon_task(gpointer data)
{
    /*GtkWidget *selector; */
    glong           last, thrld;
    gint64          now;
    GtkWidget      *dialog;
    GError         *err = NULL;

    if (data != NULL)
    {
        sat_log_log(SAT_LOG_LEVEL_ERROR,
                    _
                    ("%s: Passed a non-null pointer which should never happen.\n"),
                    __func__);
    }

    /* get time of last update */
    last = sat_cfg_get_int(SAT_CFG_INT_TLE_LAST_UPDATE);

    /* get current time */
    now = g_get_real_time() / G_USEC_PER_SEC;

    /* threshold */
    switch (sat_cfg_get_int(SAT_CFG_INT_TLE_AUTO_UPD_FREQ))
    {
    case TLE_AUTO_UPDATE_MONTHLY:
        thrld = 2592000;
        break;

    case TLE_AUTO_UPDATE_WEEKLY:
        thrld = 604800;
        break;

    case TLE_AUTO_UPDATE_DAILY:
        thrld = 86400;
        break;

        /* set default to "infinite" */
    default:
        thrld = G_MAXLONG;
        break;
    }

    if ((now - last) < thrld)
    {
        /* too early */
        /*           sat_log_log (SAT_LOG_LEVEL_DEBUG, */
        /*                           _("%s: Threshold has not been passed yet."), */
        /*                           __func__, last, now, thrld); */
    }
    else
    {
        /* time to update */
        sat_log_log(SAT_LOG_LEVEL_DEBUG,
                    _("%s: Time threshold has been passed."), __func__);

        /* find out what to do */
        if (sat_cfg_get_int(SAT_CFG_INT_TLE_AUTO_UPD_ACTION) ==
            TLE_AUTO_UPDATE_GOAHEAD)
        {

            /* start update process in separate thread */
            sat_log_log(SAT_LOG_LEVEL_DEBUG,
                        _("%s: Starting new update thread."), __func__);

            /** FIXME: store thread and destroy on exit? **/
            g_thread_try_new(_("gpredict_tle_update"), update_tle_thread, NULL,
                             &err);

            if (err != NULL)
                sat_log_log(SAT_LOG_LEVEL_ERROR,
                            _("%s: Failed to create TLE update thread (%s)"),
                            __func__, err->message);

        }
        // else if (!tle_upd_note_sent)
        // {
        //     /* notify user */
        //     dialog = gtk_message_dialog_new_with_markup(GTK_WINDOW(app),
        //                                                 GTK_DIALOG_DESTROY_WITH_PARENT,
        //                                                 GTK_MESSAGE_INFO,
        //                                                 GTK_BUTTONS_OK,
        //                                                 _
        //                                                 ("Your TLE files are getting out of date.\n"
        //                                                  "You can update them by selecting\n"
        //                                                  "<b>Edit -> Update TLE</b>\n"
        //                                                  "in the menubar."));

        //     /* Destroy the dialog when the user responds to it (e.g. clicks a button) */
        //     g_signal_connect_swapped(dialog, "response",
        //                              G_CALLBACK(gtk_widget_destroy), dialog);

        //     gtk_widget_show_all(dialog);

        //     tle_upd_note_sent = TRUE;
        // }
    }

    return TRUE;
}

static guint    tle_mon_id = 0;

int main() {

    sat_cfg_load();
    
    tle_update_from_network(TRUE);
    
    gchar * cfgfile = "./temp/modules/Amateur.mod";
    GtkSatModule * module = gtk_sat_module_new(cfgfile);
    gtk_sat_module_timeout_cb(module);

    GMainLoop * loop = g_main_loop_new (NULL, TRUE);
    module->timerid = g_timeout_add(module->timeout, gtk_sat_module_timeout_cb,
                                    module);
    GtkRotCtrl * rot_ctrl = gtk_rot_ctrl_new(module);
    module->rotctrl = rot_ctrl;
    rot_locked_cb(rot_ctrl);
    rot_ctrl->timerid = g_timeout_add(rot_ctrl->delay,
                                      rot_ctrl_timeout_cb, rot_ctrl);
    
    tle_mon_id = g_timeout_add(60000, tle_mon_task, NULL);

    g_main_loop_run (loop);

    return 0;
}