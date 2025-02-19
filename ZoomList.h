#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <vector>
#include <utility>

#include "Zoom.h"

class ZoomList{
private:
    double m_xCenter = 0;
    double m_yCenter = 0;
    double m_scale = 1;

    int m_width = 0;
    int m_height = 0;
    std::vector<Zoom> zooms;
public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    std::pair<double, double> doZoom(int x, int y);
};






#endif