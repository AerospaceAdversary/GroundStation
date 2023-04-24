CC = gcc
CFLAGS = -g -O2 -Wall -Wextra -std=c11 -pedantic -I/usr/include/x86_64-linux-gnu -pthread -I/usr/include/goocanvas-2.0 -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/harfbuzz -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/x86_64-linux-gnu -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16
LDFLAGS = -lm  -lcurl -lgoocanvas-2.0 -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -latk-1.0 -lcairo-gobject -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lcairo
AM_CPPFLAGS = \
	 -I.. \
	-DPACKAGE_DATA_DIR=\""$(datadir)/gpredict"\" \
	-DPACKAGE_PIXMAPS_DIR=\""$(datadir)/pixmaps/gpredict"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/share/locale"\" \
	-DGTK_DISABLE_SINGLE_INCLUDES \
	-DG_DISABLE_DEPRECATED \
	-DGDK_DISABLE_DEPRECATED \
	-DGSEAL_ENABLE

SUBDIRS := ./sgpsdp

all: $(SUBDIRS) main
$(SUBDIRS):
	$(MAKE) -C $@

main : main.o sat-module.o gtk-rot-ctrl.o rotor-conf.o gtk-sat-data.o orbit-tools.o predict-tools.o mod-cfg.o mod-cfg-get-param.o qth-data.o locator.o time-tools.o sat-cfg.o compat.o sat-log.o gpredict-utils.o strnatcmp.o tle-update.o $(SUBDIRS)
	gcc main.o sat-module.o gtk-rot-ctrl.o rotor-conf.o gtk-sat-data.o mod-cfg.o orbit-tools.o predict-tools.o mod-cfg-get-param.o qth-data.o locator.o time-tools.o sat-cfg.o compat.o sat-log.o gpredict-utils.o strnatcmp.o tle-update.o sgpsdp/sgp4sdp4.o sgpsdp/sgp_math.o sgpsdp/sgp_time.o sgpsdp/sgp_in.o sgpsdp/sgp_obs.o $(LDFLAGS) -o main
	
main.o : main.c 
	gcc -c $(CFLAGS) $(LDFLAGS) main.c 

gtk-sat-module.o: gtk-sat-module.c gtk-sat-module.h
	gcc -c $(CFLAGS) $(LDFLAGS) gtk-sat-module.c 

time-tools.o: time-tools.c time-tools.h
	gcc -c $(CFLAGS) $(LDFLAGS) time-tools.c 

sat-cfg.o: sat-cfg.c sat-cfg.h
	gcc -c $(CFLAGS) $(AM_CPPFLAGS) $(LDFLAGS) sat-cfg.c 

gpredict-utils.o: gpredict-utils.c gpredict-utils.h
	gcc -c $(CFLAGS) gpredict-utils.c 

compat.o: compat.c compat.h
	gcc -c $(CFLAGS) $(AM_CPPFLAGS) $(LDFLAGS) compat.c 

strnatcmp.o: strnatcmp.c strnatcmp.h
	gcc -c $(CFLAGS) $(AM_CPPFLAGS) $(LDFLAGS) strnatcmp.c 

sat-log.o: sat-log.c sat-log.h 
	gcc -c $(CFLAGS) $(AM_CPPFLAGS) $(LDFLAGS) sat-log.c 

orbit-tools.o: orbit-tools.c orbit-tools.h
	gcc -c $(CFLAGS) $(LDFLAGS) orbit-tools.c 

predict-tools.o: predict-tools.c predict-tools.h
	gcc -c $(CFLAGS) $(LDFLAGS) predict-tools.c

sat-vis.o: sat-vis.c sat-vis.h
	gcc -c $(CFLAGS) $(LDFLAGS) sat-vis.c

tle-tools.o: tle-tools.c tle-tools.h
	gcc -c $(CFLAGS) $(LDFLAGS) tle-tools.c

tle-update.o: tle-update.c tle-update.h
	gcc -c $(CFLAGS) $(LDFLAGS) tle-update.c

gtk-sat-data.o: gtk-sat-data.c gtk-sat-data.h 
	gcc -c $(CFLAGS) $(LDFLAGS) gtk-sat-data.c

sat-module.o: sat-module.c sat-module.h 
	gcc -c $(CFLAGS) $(AM_CPPFLAGS) $(LDFLAGS) sat-module.c

gtk-sat-module.o: gtk-sat-module.c gtk-sat-module.h 
	gcc -c $(CFLAGS) $(AM_CPPFLAGS) $(LDFLAGS) gtk-sat-module.c

mod-cfg.o: mod-cfg.c mod-cfg.h 
	gcc -c $(CFLAGS) $(LDFLAGS) mod-cfg.c

mod-cfg-get-param.o: mod-cfg-get-param.c mod-cfg-get-param.h 
	gcc -c $(CFLAGS) $(LDFLAGS) mod-cfg-get-param.c

gtk-sat-selector.o: gtk-sat-selector.c gtk-sat-selector.h 
	gcc -c $(CFLAGS) $(LDFLAGS) gtk-sat-selector.c

qth-data.o: qth-data.c qth-data.h 
	gcc -c $(CFLAGS) $(LDFLAGS) qth-data.c

locator.o: locator.c locator.h
	gcc -c $(CFLAGS) $(LDFLAGS) locator.c

rotor-conf.o: rotor-conf.c rotor-conf.h
	gcc -c $(CFLAGS) $(LDFLAGS) rotor-conf.c

gtk-rot-ctrl.o: gtk-rot-ctrl.c gtk-rot-ctrl.h
	gcc -c $(CFLAGS) $(LDFLAGS) gtk-rot-ctrl.c

clean:
	rm *.o main

.PHONY: all $(SUBDIRS)

