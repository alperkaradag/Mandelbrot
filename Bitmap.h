#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

class Bitmap{
    int m_width;
    int m_height;
    int n_pixels;
    std::unique_ptr<uint8_t[]> m_pPixel = nullptr;

public:
    Bitmap(int width, int height, std::unique_ptr<uint8_t[]> pPixel = nullptr);
    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
    bool write(std::string filename);
    virtual ~Bitmap();
};

#endif