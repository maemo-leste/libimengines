all: libimengines-wp.so.4.2.0

libimengines-wp.so.4.2.0: imengines-wp.c imengines-wp.h
	$(CC) -Wall -fPIC $(CFLAGS) $(shell pkg-config --cflags --libs glib-2.0) --std=gnu99 -shared -Wl,-soname=libimengines-wp.so.4 $< -o $@

clean:
	$(RM) libimengines-wp.so.4.2.0

install:
	install -d "$(DESTDIR)/usr/lib/"
	install -m 644 libimengines-wp.so.4.2.0 "$(DESTDIR)/usr/lib/"
	ln -s libimengines-wp.so.4.2.0 "$(DESTDIR)/usr/lib/libimengines-wp.so.4"
	ln -s libimengines-wp.so.4 "$(DESTDIR)/usr/lib/libimengines-wp.so"
	install -d "$(DESTDIR)/usr/include/"
	install -m 644 imengines-wp.h "$(DESTDIR)/usr/include/"
	install -d "$(DESTDIR)/usr/lib/pkgconfig"
	install -m 644 imengines-wp.pc "$(DESTDIR)/usr/lib/pkgconfig/"
