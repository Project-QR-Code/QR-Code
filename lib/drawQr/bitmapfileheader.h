#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

//#include <cstdint>

//using namespace std; c++

struct BitmapFileHeader{
    char header[2]={'B','M'};
    int fileSize;
    int reserved{0};
    int data
};


#endif