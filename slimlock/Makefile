# slimlock makefile
# © 2010-2012 Joel Burget

CXX = g++
CC  = gcc

PKGS=x11 xrandr xft fontconfig imlib2 xext
MYCFLAGS=-Wall -I. $(shell pkg-config --cflags $(PKGS)) -pthread
CXXFLAGS=$(CFLAGS) $(MYCFLAGS)
LIBS=$(shell pkg-config --libs $(PKGS)) -lrt -lpam -pthread
CUSTOM=
NAME=slimlock
VERSION=0.11
CFGDIR=/etc
MANDIR=/usr/share/man
DESTDIR=
PREFIX=/usr
DEFINES=-DPACKAGE=\"$(NAME)\" -DVERSION=\"$(VERSION)\" \
		-DPKGDATADIR=\"$(PREFIX)/share/slim\" -DSYSCONFDIR=\"$(CFGDIR)\"

OBJECTS=cfg.o image.o panel.o slimlock.o util.o

all: slimlock

slimlock: $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(NAME) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(DEFINES) $(CUSTOM) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) $(MYCFLAGS) $(DEFINES) $(CUSTOM) -c $< -o $@

clean:
	@rm -f slimlock *.o

dist:
	@rm -rf $(NAME)-$(VERSION)
	@mkdir $(NAME)-$(VERSION)
	@cp -r *.cpp *.h *.c Makefile LICENSE README.md slimlock.1 slimlock.conf $(NAME)-$(VERSION)
	@tar cvzf $(NAME)-$(VERSION).tar.gz $(NAME)-$(VERSION)
	@rm -rf $(NAME)-$(VERSION)

install: slimlock
	@install -D -m 644 slimlock.1 $(DESTDIR)$(MANDIR)/man1/slimlock.1
	@install -D -m 755 slimlock $(DESTDIR)$(PREFIX)/bin/slimlock
	@chmod u+s $(DESTDIR)$(PREFIX)/bin/slimlock
	@install -D -m 644 slimlock.conf $(DESTDIR)$(CFGDIR)/slimlock.conf
	@install -D -m 644 slimlock.pam $(DESTDIR)$(CFGDIR)/pam.d/slimlock

uninstall:
	@rm -f $(DESTDIR)$(MANDIR)/man1/slimlock.1
	@rm -f $(DESTDIR)$(PREFIX)/bin/slimlock
	@rm -f $(DESTDIR)$(CFGDIR)/slimlock.conf
	@rm -f $(DESTDIR)$(CFGDIR)/pam.d/slimlock
