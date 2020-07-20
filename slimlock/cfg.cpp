/* SLiM - Simple Login Manager
   Copyright (C) 2004-06 Simone Rota <sip@varlock.com>
   Copyright (C) 2004-06 Johannes Winkelmann <jw@tks6.net>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include "cfg.h"

using namespace std;

typedef pair<string,string> option;

Cfg::Cfg()
{
    // Configuration options
    options.insert(option("screenshot_cmd", "import -window root /slim.png"));
    options.insert(option("welcome_msg", "Welcome to %host"));
    options.insert(option("current_theme", "default"));
    options.insert(option("hidecursor", "false"));

    // Theme stuff
    options.insert(option("input_panel_x", "50%"));
    options.insert(option("input_panel_y", "40%"));
    options.insert(option("input_name_x", "200"));
    options.insert(option("input_name_y", "154"));
    options.insert(option("input_pass_x", "-1")); // default is single inputbox
    options.insert(option("input_pass_y", "-1"));
    options.insert(option("input_font", "Verdana:size=11"));
    options.insert(option("input_color", "#000000"));
    options.insert(option("input_cursor_height", "20"));
    options.insert(option("input_maxlength_name", "20"));
    options.insert(option("input_maxlength_passwd", "20"));
    options.insert(option("input_shadow_xoffset", "0"));
    options.insert(option("input_shadow_yoffset", "0"));
    options.insert(option("input_shadow_color", "#FFFFFF"));

    options.insert(option("welcome_font", "Verdana:size=14"));
    options.insert(option("welcome_color", "#FFFFFF"));
    options.insert(option("welcome_x", "-1"));
    options.insert(option("welcome_y", "-1"));
    options.insert(option("welcome_shadow_xoffset", "0"));
    options.insert(option("welcome_shadow_yoffset", "0"));
    options.insert(option("welcome_shadow_color", "#FFFFFF"));

    options.insert(option("intro_msg", ""));
    options.insert(option("intro_font", "Verdana:size=14"));
    options.insert(option("intro_color", "#FFFFFF"));
    options.insert(option("intro_x", "-1"));
    options.insert(option("intro_y", "-1"));

    options.insert(option("background_style", "stretch"));
    options.insert(option("background_color", "#CCCCCC"));

    options.insert(option("username_font", "Verdana:size=12"));
    options.insert(option("username_color", "#FFFFFF"));
    options.insert(option("username_x", "-1"));
    options.insert(option("username_y", "-1"));
    options.insert(option("username_msg", "Please enter your username"));
    options.insert(option("username_shadow_xoffset", "0"));
    options.insert(option("username_shadow_yoffset", "0"));
    options.insert(option("username_shadow_color", "#FFFFFF"));

    options.insert(option("password_x", "-1"));
    options.insert(option("password_y", "-1"));
    options.insert(option("password_msg", "Please enter your password"));

    options.insert(option("msg_color", "#FFFFFF"));
    options.insert(option("msg_font", "Verdana:size=16:bold"));
    options.insert(option("msg_x", "40"));
    options.insert(option("msg_y", "40"));
    options.insert(option("msg_shadow_xoffset", "0"));
    options.insert(option("msg_shadow_yoffset", "0"));
    options.insert(option("msg_shadow_color", "#FFFFFF"));

    // slimlock-specific options
    options.insert(option("dpms_standby_timeout", "60"));
    options.insert(option("dpms_off_timeout", "600"));
    options.insert(option("wrong_passwd_timeout", "2"));
    options.insert(option("passwd_feedback_x", "50%"));
    options.insert(option("passwd_feedback_y", "10%"));
    options.insert(option("passwd_feedback_msg", "Authentication failed"));
    options.insert(option("passwd_feedback_capslock", "Authentication failed (CapsLock is on)"));
    options.insert(option("show_username", "1"));
    options.insert(option("show_welcome_msg", "0"));
    options.insert(option("tty_lock", "1"));
    options.insert(option("bell", "1"));
    options.insert(option("passwd_char", "*"));

    error = "";
}

Cfg::~Cfg() {
    options.clear();
}
/*
 * Creates the Cfg object and parses
 * known options from the given configfile / themefile
 */
bool Cfg::readConf(string configfile) {
    int n = -1;
    string line, fn(configfile);
    map<string,string>::iterator it;
    string op;
    ifstream cfgfile(fn.c_str());
    if (cfgfile) {
        while (getline(cfgfile, line)) {
            it = options.begin();
            while (it != options.end()) {
                op = it->first;
                n = line.find(op);
                if (n == 0)
                    options[op] = parseOption(line, op);
                it++;
            }
        }
        cfgfile.close();

        return true;
    } else {
        error = "Cannot read configuration file: " + configfile;
        return false;
    }
}

/* Returns the option value, trimmed */
string Cfg::parseOption(string line, string option ) {
    return trim(line.substr(option.size(), line.size() - option.size()));
}


const string& Cfg::getError() const {
    return error;
}

string& Cfg::getOption(string option) {
    return options[option];
}

/* return a trimmed string */
string Cfg::trim( const string& s ) {
    if ( s.empty() )
        return s;
    int pos = 0;
    string line = s;
    int len = line.length();
    while (pos < len && isspace(line[pos]))
        ++pos;
    line.erase( 0, pos );
    pos = line.length() - 1;
    while (pos > -1 && isspace(line[pos]))
        --pos;
    if ( pos != -1 )
        line.erase( pos+1 );
    return line;
}

/* Return the welcome message with replaced vars */
string Cfg::getWelcomeMessage() {
    string s = getOption("welcome_msg");
    int n = -1;
    n = s.find("%host");
    if (n >= 0) {
        string tmp = s.substr(0, n);
        char host[40];
        gethostname(host,40);
        tmp = tmp + host;
        tmp = tmp + s.substr(n+5, s.size() - n);
        s = tmp;
    }
    n = s.find("%domain");
    if (n >= 0) {
        string tmp = s.substr(0, n);;
        char domain[40];
        getdomainname(domain,40);
        tmp = tmp + domain;
        tmp = tmp + s.substr(n+7, s.size() - n);
        s = tmp;
    }
    return s;
}

int Cfg::string2int(const char* string, bool* ok) {
    char* err = 0;
    int l = (int)strtol(string, &err, 10);
    if (ok)
        *ok = (*err == 0);
    return (*err == 0) ? l : 0;
}

// Get absolute position
int Cfg::absolutepos(const string& position, int max, int width) {
    int n = -1;
    n = position.find("%");
    if (n>0) { // X Position expressed in percentage
        int result = (max*string2int(position.substr(0, n).c_str())/100) - (width / 2);
        return result < 0 ? 0 : result ;
    } else // Absolute X position
        return string2int(position.c_str());
}

// split a comma separated string into a vector of strings
void Cfg::split(vector<string>& v, const string& str, char c, bool useEmpty) {
    v.clear();
    string::const_iterator s = str.begin();
    string tmp;
    while (true) {
        string::const_iterator begin = s;
        while (*s != c && s != str.end())
            ++s;
        tmp = string(begin, s);
        if (useEmpty || tmp.size() > 0)
            v.push_back(tmp);
        if (s == str.end())
            break;
        if (++s == str.end()) {
            if (useEmpty)
                v.push_back("");
            break;
        }
    }
}
