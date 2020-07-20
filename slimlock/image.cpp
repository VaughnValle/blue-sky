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

#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#include "image.h"

Image::Image() {
}

Image::~Image() {
    imlib_context_set_image(image);
    imlib_free_image();
}

bool
Image::Read(const char *filename) {
    image = imlib_load_image(filename);
    imlib_context_set_image(image);
    if (image) {
        width = imlib_image_get_width();
        height = imlib_image_get_height();
    }
    return(image != NULL);
}

void
Image::Resize(const int w, const int h) {
    imlib_context_set_image(image);
    image = imlib_create_cropped_scaled_image(0, 0, width, height, w, h);

    imlib_free_image();
    width = w;
    height = h;
}

/* Merge the image with a background, taking care of the
 * image Alpha transparency. (background alpha is ignored).
 * The images is merged on position (x, y) on the
 * background, the background must contain the image.
 */
void Image::Merge(Image* background, const int x, const int y) {
    if (x + width > background->Width()|| y + height > background->Height())
        return;

    Imlib_Image bg_image, new_image;
    bg_image = background->GetImage();
    imlib_context_set_image(bg_image);
    new_image = imlib_clone_image();

    imlib_context_set_image(new_image);
    imlib_blend_image_onto_image(image, 0, 0, 0, width, height, x, y, width, height);

    imlib_context_set_image(image);
    imlib_free_image();

    image = new_image;
}

/* Tile the image growing its size to the minimum entire
 * multiple of w * h.
 * The new dimensions should be > of the current ones.
 */
void Image::Tile(const int w, const int h) {
    int tiles_x, tiles_y;

    Imlib_Image new_image = imlib_create_image(w, h);
    imlib_context_set_image(new_image);

    tiles_x = w / width;
    tiles_y = h / height;
    for(int i=0; i <= tiles_x; i++) {
        for(int j=0; j <= tiles_y; j++)
            imlib_blend_image_onto_image(image, 0, 0, 0, width, height,
                                         i * width, j * height, width, height);
    }

    width = w;
    height = h;

    imlib_context_set_image(image);
    imlib_free_image();

    image = new_image;
}

/* Crop the image
 */
void Image::Crop(const int x, const int y, const int w, const int h) {
    imlib_context_set_image(image);
    image = imlib_create_cropped_image(x, y, w, h);

    imlib_free_image();

    width = w;
    height = h;
}

/* Center the image in a rectangle of given width and height.
 * Fills the remaining space (if any) with the hex color
 */
void Image::Center(const int w, const int h, const char *hex) {
    int pos_x, pos_y;
    unsigned long packed_rgb;
    Imlib_Image bg = imlib_create_image(w, h);

    sscanf(hex, "%lx", &packed_rgb);

    unsigned long r = packed_rgb >> 16;
    unsigned long g = packed_rgb >> 8 & 0xff;
    unsigned long b = packed_rgb & 0xff;

    imlib_context_set_image(bg);
    imlib_context_set_color(r, g, b, 255);
    imlib_image_fill_rectangle(0, 0, w, h);

    pos_x = (w - width) / 2;
    pos_y = (h - height) / 2;

    imlib_blend_image_onto_image(image, 0, 0, 0, width, height, pos_x, pos_y,
                                 width, height);

    imlib_context_set_image(image);
    imlib_free_image();

    image = bg;
}

Pixmap
Image::createPixmap(Display* dpy, int scr, Window win) {
	imlib_context_set_display(dpy);
	imlib_context_set_visual(DefaultVisual(dpy, scr));
	imlib_context_set_colormap(DefaultColormap(dpy, scr));

    const int depth = DefaultDepth(dpy, scr);
    Pixmap tmp = XCreatePixmap(dpy, win, XWidthOfScreen(ScreenOfDisplay(dpy, scr)),
                               XHeightOfScreen(ScreenOfDisplay(dpy, scr)),
                               depth);

    imlib_context_set_image(image);

    imlib_context_set_drawable(tmp);
    imlib_render_image_on_drawable(0, 0);

    return tmp;
}

