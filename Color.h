#pragma once

class Color
{
private:
public:
    double r, g, b;
    Color(double r, double g, double b){
        this->r = r;
        this->g = g;
        this->b = b;
    };
    Color operator-(const Color& c2){
        return Color(r - c2.r, g - c2.g, b - c2.b);
    }
    ~Color(){};
};
