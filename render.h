#ifndef render_h
#define render_h

#include <SFML/Graphics.h>
#include <complex.h>
#include "mandelbrot.h"
sfImage* RenderMandelbrot(unsigned int iter, sfVector2f bound, sfVector2i size) {
    sfImage* img = sfImage_create(size.x,size.y);
    double inc = (double)(bound.y - bound.x) / size.x;
    double cbound = inc * size.y / 2;
    for (double y = 0; y < size.y; y++) {
        for (double x = 0; x < size.x; x++) {
            sfImage_setPixel(img,(int)x,(int)y,sfColor_fromInteger(0xffffffff * IsMandelbrot(iter,(double complex)((inc * x + bound.x) + I * (inc * y - cbound)))));
        }
    }
    return img;
}

#endif