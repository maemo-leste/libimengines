all: libimengines.so.4.2.0 libimengines-wp.so.4.2.0 libim_wp_plugin_dummy.so

libimengines.so.4.2.0: imengines.c imengines.h
	$(CC) -Wall -fPIC $(CFLAGS) --std=gnu99 -shared -Wl,-soname=libimengines.so.4 $< -o $@

libim_wp_plugin_dummy.so: wp-plugin-dummy.c
	$(CC) -Wall -fPIC $(CFLAGS) --std=gnu99 -shared -Wl,-soname=libim_wp_plugin_dummy.so $< -o $@

libimengines-wp.so.4.2.0: imengines-wp.c imengines-wp.h
	$(CC) -Wall -fPIC $(CFLAGS) $(shell pkg-config --cflags --libs glib-2.0) -ldl --std=gnu99 -shared -Wl,-soname=libimengines-wp.so.4 $< -o $@

clean:
	$(RM) libimengines.so.4.2.0 libimengines-wp.so.4.2.0 libim_wp_plugin_dummy.so

install:
	install -d "$(DESTDIR)/usr/lib/"
	install -m 644 libimengines.so.4.2.0 "$(DESTDIR)/usr/lib/"
	ln -s libimengines.so.4.2.0 "$(DESTDIR)/usr/lib/libimengines.so.4"
	ln -s libimengines.so.4 "$(DESTDIR)/usr/lib/libimengines.so"
	install -m 644 libimengines-wp.so.4.2.0 "$(DESTDIR)/usr/lib/"
	ln -s libimengines-wp.so.4.2.0 "$(DESTDIR)/usr/lib/libimengines-wp.so.4"
	ln -s libimengines-wp.so.4 "$(DESTDIR)/usr/lib/libimengines-wp.so"
	install -d "$(DESTDIR)/usr/lib/libimengines/"
	install -m 644 libim_wp_plugin_dummy.so "$(DESTDIR)/usr/lib/libimengines/"
	install -d "$(DESTDIR)/usr/include/"
	install -m 644 imengines.h "$(DESTDIR)/usr/include/"
	install -m 644 imengines-wp.h "$(DESTDIR)/usr/include/"
	install -d "$(DESTDIR)/usr/lib/pkgconfig"
	install -m 644 imengines.pc "$(DESTDIR)/usr/lib/pkgconfig/"
	install -m 644 imengines-wp.pc "$(DESTDIR)/usr/lib/pkgconfig/"
