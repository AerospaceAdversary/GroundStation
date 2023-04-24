CC = gcc
CFLAGS = -g -O2 -Wall -Wextra -std=c11 -pedantic -I/usr/include/x86_64-linux-gnu -pthread -I/usr/include/goocanvas-2.0 -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/harfbuzz -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/x86_64-linux-gnu -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16
LDFLAGS = -lm  -lcurl -lgoocanvas-2.0 -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -latk-1.0 -lcairo-gobject -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lcairo

all : sgp_in.o sgp_time.o sgp_math.o sgp4sdp4.o sgp_obs.o

sgp4sdp4.o: sgp4sdp4.c sgp4sdp4.h
	gcc -c $(CFLAGS) $(LDFLAGS) sgp4sdp4.c

sgp_math.o: sgp_math.c sgp4sdp4.h
	gcc -c $(CFLAGS) $(LDFLAGS) sgp_math.c

sgp_time.o: sgp_time.c sgp4sdp4.h
	gcc -c $(CFLAGS) $(LDFLAGS) sgp_time.c

sgp_in.o: sgp_in.c sgp4sdp4.h
	gcc -c $(CFLAGS) $(LDFLAGS) sgp_in.c

sgp_obs.o: sgp_obs.c sgp4sdp4.h
	gcc -c $(CFLAGS) $(LDFLAGS) sgp_obs.c