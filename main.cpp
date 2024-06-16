#include <iostream>
#include <vector>
#include <math.h>

#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "FractalCreator.h"

using namespace std;
/*
double xScaled = (double)(x-150)/WIDTH * 2 - 1;
double yScaled = (double)y/HEIGHT * 2 - 1;
*/
int main(){
    int WIDTH = 600, HEIGHT = 600;
    Bitmap bm(WIDTH, HEIGHT);

    FractalCreator fc(WIDTH, HEIGHT);

    fc.addZoom(Zoom(111, 436, 100));

    fc.calculateIterations();
    fc.drawFractal(bm);
    fc.writeBitmap(bm, "test.bmp");

    return 0;
}