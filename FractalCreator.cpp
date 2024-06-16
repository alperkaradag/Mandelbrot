#include <utility>
#include <math.h>
#include <iostream>

#include "FractalCreator.h"
#include "Mandelbrot.h"
#include "Color.h"

FractalCreator::FractalCreator()
{
    width = 600;
    height = 600;
    histogram.resize(Mandelbrot::MAX_ITERATIONS + 1, 0);
    iterations.resize(width * height, 0);
    zoomList = new ZoomList(width, height);
}

FractalCreator::FractalCreator(int width, int height)
{
    this->width = width;
    this->height = height;
    histogram.resize(Mandelbrot::MAX_ITERATIONS + 1, 0);
    iterations.resize(width * height, 0);

    zoomList = new ZoomList(width, height);
}

void FractalCreator::calculateIterations()
{
    totalIterations = 0;
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            
            std::pair<double, double> coords = zoomList->doZoom(x, y);
            int it = Mandelbrot::getIterations(coords.first, coords.second);

            iterations[y*width+x] = it;
            if(it != Mandelbrot::MAX_ITERATIONS){
                histogram[it]++;
                totalIterations++;            
            }
        }
    }
}

void FractalCreator::drawFractal(Bitmap& bitmap)
{
    Color start(0, 0, 0);
    Color end(255, 128, 64);
    Color diff = end - start;
    
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            uint8_t r = 0, g = 0, b = 0;
            int it  = iterations[y*width+x];
            if(it != Mandelbrot::MAX_ITERATIONS){
                double hue = 0;
                for(int i = 0; i < it; i++){
                    hue += (double)histogram[i] / totalIterations;
                }
                r = start.r + diff.r*hue;
                g = start.g + diff.g*hue;
                b = start.b + diff.b*hue;
            }
            bitmap.setPixel(x, y, r, g, b);
        }
    }
}

void FractalCreator::addZoom(const Zoom& zoom)
{
    zoomList->add(zoom);
}


void FractalCreator::writeBitmap(Bitmap& bitmap, std::string name)
{
    std::cout << "Writing..." << std::endl;
    if(!bitmap.write(name)){
        std::cout << "Could not write to bitmap!" << std::endl;
    }
}


FractalCreator::~FractalCreator()
{
    delete zoomList;
}