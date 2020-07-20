/* SLiM - Simple Login Manager
   Copyright (C) 1997, 1998 Per Liden
   Copyright (C) 2004-06 Simone Rota <sip@varlock.com>
   Copyright (C) 2004-06 Johannes Winkelmann <jw@tks6.net>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
*/

#ifndef _CONST_H_
#define _CONST_H_


#define APPNAME    "slimlock"

#define DISPLAY    ":0.0"

#define HIDE        0
#define SHOW        1

#define OK_EXIT     0
#define ERR_EXIT    1

// duration for showing error messages, as "login command failed", in seconds
#define ERROR_DURATION  5

// variables replaced in login_cmd
#define THEME_VAR       "%theme"

// variables replaced in pre-session_cmd and post-session_cmd
#define USER_VAR       "%user"

// max height/width for images
#define MAX_DIMENSION 10000

#endif
