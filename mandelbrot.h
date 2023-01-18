#ifndef complex_h
#define complex_h

#include <complex.h>
char IsMandelbrot(unsigned int iter, double complex c) {
    double complex n = c;
    for (unsigned int i = 0; i < iter; i++) {
        if (creal(n) > 2) return 0;
        n = n*n + c;
    }
    return 1;
}

#endif