#include "ZoomList.h"

ZoomList::ZoomList(int width, int height){
    m_width = width;
    m_height = height;
    m_xCenter = width/2;
    m_yCenter = height/2;
}

void ZoomList::add(const Zoom& zoom){
    zooms.push_back(zoom);
    m_xCenter += (zoom.x - m_width/2) * m_scale;
    m_yCenter += (zoom.y - m_height/2) * m_scale;
    m_scale *= zoom.scale;
}

std::pair<double, double> ZoomList::doZoom(int x, int y){
    double xFractal = ((x - m_width/2) * m_scale + m_xCenter) / m_width * 2 - 1;
    double yFractal = ((y - m_height/2) * m_scale + m_yCenter) / m_height * 2 - 1;
    return std::make_pair(xFractal, yFractal);
}