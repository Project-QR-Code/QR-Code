#ifndef _MODEL_H_
#define _MODEL_H_

// Array that Stores data and all ids and markings in order
// Max Number is calculated with basic data(redundance not included!)
int QRCodeRawData[2064];

struct QRCode {
    // Identification Number is to set type of data (Characters, Numbers etc) (4 Bit)
    // Example: Character = 0010
    int codificationId[4];

    // Gives length of Data (Amount of Characters or amount of digits in number) (9 Bit)
    int lengthOfData[8];

    // Maximum Character of QR-Code is 256. But we process only that much data as lengthOfData holds
    // (8 Bits)
    // data[character][character bits]
    int data[256][8];

    // Is a constant, is always the end of the data
    const int endmarking[4] = {0, 0, 0, 0};
};

#endif
