#include <fstream>
#include <random>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

Bitmap::Bitmap(int width, int height, std::unique_ptr<uint8_t[]> pPixel) :
     m_width(width), m_height(height), m_pPixel(new uint8_t[width*height*3]{}){
    n_pixels = width*height*3;
    /*for(int i = 0; i < n_pixels; i+=3){
        m_pPixel[i] = (uint8_t)(rand() % 256);
        m_pPixel[i+1] = (uint8_t)(rand() % 256);
        m_pPixel[i+2] = (uint8_t)(rand() % 256);
    }*/
}

void Bitmap::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b){
    uint8_t* pPixel = m_pPixel.get();
    pPixel += 3 * y * m_width + 3 * x;

    pPixel[0] = b;
    pPixel[1] = g;
    pPixel[2] = r;

}

bool Bitmap::write(std::string fileName){
    BitmapFileHeader bfh;
    BitmapInfoHeader bih;

    bfh.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3;
    bfh.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    bih.width = m_width;
    bih.height = m_height;

    std::ofstream file;
    file.open(fileName, std::ios::out | std::ios::binary);
    if(!file){
        return false;
    }

    file.write((char*)&bfh, sizeof(BitmapFileHeader));
    file.write((char*)&bih, sizeof(BitmapInfoHeader));
    file.write((char*)m_pPixel.get(), n_pixels);

    file.close();
    if(file.is_open()){
        return false;
    }
    return true;
}

Bitmap::~Bitmap(){

}