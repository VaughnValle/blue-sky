Once Again Maintained
====================
Maintenance of this project has been picked up by me (danny noest).  Please 
feel free to toss any bugs my way (dnoest@gmail.com). 

slimlock - unholy screen locker
===============================
This is the Frankenstein's monster of screen lockers. I had the horrible
idea to graft SLiM and slock together to create the screen locker that should
have never been.

Slimlock reads your SLiM config files and uses the same interface. If you use
SLiM already, then it should work for you automatically.

Requirements and Building
-------------------------
Requires X11, imlib2, freetype, pam. Change CFGDIR in the makefile to the
directory containing you `slim.conf`. As root, install with `make` then `make
install`.

Running slimlock
----------------
Run with `slimlock`.

Configuration
-------------
Slimlock reads SLiM's `slim.conf` and `slimlock.conf`, which should be at
`$CFGDIR/etc/slimlock.conf`. The currently available settings and their defaults
are:

-	`dpms_standby_timeout`: number of seconds of inactivity before the screen
	blanks.
	-	Default: 60
-	`dpms_off_timeout`: same as above, but the screen turns off.
	-	Default: 600
-	`wrong_passwd_timeout`: number of seconds after entering an incorrect password
	before slimlock will accept another attempt.
	-	Default: 2
-	`passwd_feedback_msg`: message to display after a failed authentication
	attempt.
	-	Default: "Authentication failed"
-	`passwd_feedback_capslock`: message to display after a failed authentication
	attempt if the CapsLock is on.
	-	Default: "Authentication failed (CapsLock is on)"
-	`show_username`: whether or not to display the username on themes with only a
	single input box. 1 to show, 0 to disable.
	-	Default: 1
-	`show_welcome_msg`: whether or not to display SLiM's welcome message. 1 to
	show, 0 to disable.
	-	Default: 0
-	`tty_lock`: whether or not to allow virtual terminals switching. 1 to
	disallow, 0 to allow.
	-	Default: 1
-	`bell`: whether to ring the bell on authentication failure. 1 to
	enable, 0 to disable.
	-	Default: 1
-	`passwd_char`: character to display when masking password. Only the first
	character is used.
	-	Default: *

Copyright
---------
slimlock copyright (c) 2010-2012 Joel Burget

Image handling code revamped, PAM authentication, and other miscellaneous tweaks
by (c) 2011 Kevin Sullivan

SLiM is copyright (c) 2004-06 by Simone Rota, Johannes Winkelmann
and is available under the GNU General Public License.
See the COPYING file for the complete license.

Image handling code adapted and extended from xplanet 1.0.1,
copyright (c) 2002-04 by Hari Nair

Login.app is copyright (c) 1997, 1998 by Per Liden and is 
licensed through the GNU General Public License. 

Multi-monitor support adapted from xscreensaver, copyright (c) 1993-2006 by Jamie 
Zawinski <jwz@jwz.org>

CapsLock handling adapted from xlockmore, copyright (c) 1998-1991 by Patrick J. Naughton
