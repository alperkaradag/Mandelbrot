#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot
{
private:
    /* data */
public:
    static const int MAX_ITERATIONS = 1000;

    static int getIterations(double x, double y);

    Mandelbrot(/* args */);
    ~Mandelbrot();
};

#endif