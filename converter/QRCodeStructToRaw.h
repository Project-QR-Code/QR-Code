#ifndef _QRCODESTRUCTTORAW_H_
#define _QRCODESTRUCTTORAW_H_

#include "../model.h";

int QRCodeRawData[];
int lengthRawData;

// Converts struct with data to array with raw data
// Adds hamming codes to data
void convertQrStructToRaw(struct QRCode data){
    // Implement Hamming Codes
}

#endif
