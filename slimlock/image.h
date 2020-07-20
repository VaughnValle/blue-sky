/* SLiM - Simple Login Manager
   Copyright (C) 2004-06 Simone Rota <sip@varlock.com>
   Copyright (C) 2004-06 Johannes Winkelmann <jw@tks6.net>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   The following code has been adapted and extended from
   xplanet 1.0.1, Copyright (C) 2002-04 Hari Nair <hari@alumni.caltech.edu>
*/

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
extern "C" {
#include <Imlib2.h>
}
class Image {
public:
    Image();

    ~Image();

    int Width() const  {
        return(width);
    }
    int Height() const {
        return(height);
    }
    Imlib_Image GetImage() {
        return(image);
    }
    bool Read(const char *filename);

    void Resize(const int w, const int h);
    void Merge(Image* background, const int x, const int y);
    void Crop(const int x, const int y, const int w, const int h);
    void Tile(const int w, const int h);
    void Center(const int w, const int h, const char *hex);

    Pixmap createPixmap(Display* dpy, int scr, Window win);

private:
    int width, height;
    Imlib_Image image;
};

#endif
