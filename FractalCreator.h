#pragma once

#include <string>
#include <vector>

#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"

class FractalCreator
{
private:
    int width, height;
    std::vector<int> histogram;
    std::vector<int> iterations;
    ZoomList* zoomList;

    int totalIterations;

public:
    FractalCreator();
    FractalCreator(int width, int height);

    void calculateIterations();
    void drawFractal(Bitmap& bitmap);
    void addZoom(const Zoom& zoom);
    void writeBitmap(Bitmap& bitmap, std::string name);

    ~FractalCreator();
};


