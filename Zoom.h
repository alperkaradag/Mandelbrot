#ifndef ZOOM_H
#define ZOOM_H

struct Zoom{
    int x = 0;
    int y = 0;
    double scale = 0;
    Zoom(int x, int y, double scale) : x(x), y(y), scale(1.0/scale){};
};

#endif