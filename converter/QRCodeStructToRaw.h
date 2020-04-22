#ifndef _QRCODESTRUCTTORAW_H_
#define _QRCODESTRUCTTORAW_H_

#include "../model.h"
#include "./decToBin.h"

// Processed Raw data
int QRCodeRawData[];
// Length of Raw data
int lengthRawData;

// Map characters to special numbers(not ascii! some weird stripped down ascii)
const char mapCharacters[45] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', \
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '$', '%', '*', '+', '-', '.', '/', ':'};

int getIndexInMapCharacters(char query){
    for(int i = 0; i < 45; i++){
        if(mapCharacters[i] == query){
            return i;
        }
    }
    return -1;
}


// Converts struct with data to array with raw data
// Adds hamming codes to data
void convertQrStructToRaw(struct QRCode data){
    // TODO: calculate Number of size or reallocate on every iteration
    // Character Data of QRCode in binary (without id and length)
    int dataBlocksBinary[256];
    int lengthDataBlocksBinary = 0;

    //TODO: check if char array in struct data is correct

    // Create Blocks of 2 Characters and calculate binary Number
    for(int i = 0; i < data.lengthOfData/2; i++){
        // Calculate Block Value
        int blockDecValue = getIndexInMapCharacters(data.data[i]) * 45;
        blockDecValue += getIndexInMapCharacters(data.data[i+1]);
        // Convert block value to binary number
        struct BinaryNumber tempBinNumber = decToBin(blockDecValue);
        // Extend binary number into length of 11 Bits (attach 0)
        // Add binary Number to dataBlocksBinary
    }
}

#endif
