#include "Mandelbrot.h"
#include <complex>

Mandelbrot::Mandelbrot(/* args */)
{
}

Mandelbrot::~Mandelbrot()
{
}

int Mandelbrot::getIterations(double x, double y){
    std::complex<double> z = 0;
    std::complex<double> c(x, y);
    int it = 0;

    while(it < MAX_ITERATIONS){
        z = z*z + c;

        if(norm(z) > 4) break;
        it++;
    }
    return it;
}