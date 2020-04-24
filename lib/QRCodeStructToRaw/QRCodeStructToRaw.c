#include "../model.h"
#include "../binaryConverter/binaryConverter.h"
#include "./QRCodeStructToRaw.h"
#include <stdio.h>


int getIndexInMapCharacters(char query){
    for(int i = 0; i < 45; i++){
        if(mapAlphanumericalCharacters[i] == query){
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
    for(int i = 0; i < data.lengthOfData; i+=2){
        
        // Calculate Block Value
        int blockDecValue = getIndexInMapCharacters((char)data.data[i]) * 45;
        blockDecValue += getIndexInMapCharacters((char)data.data[i+1]);
        // Convert block value to binary number
        struct BinaryNumber tempBinNumber = decToBin(blockDecValue, 11);
        // Extend binary number into length of 11 Bits (attach 0)

        int missingZeroes = 11 - tempBinNumber.length;
        for(int a = lengthDataBlocksBinary; a < (lengthDataBlocksBinary + missingZeroes); a++){
            dataBlocksBinary[a] = 0;
        }
        int b = 0; 
        for(int a = lengthDataBlocksBinary + missingZeroes; a < lengthDataBlocksBinary + 11; a++){
            dataBlocksBinary[a] = tempBinNumber.array[b];
            b++;
        }
        lengthDataBlocksBinary += 11;
    }

    // Write Type of Data (codification id)
    for(int i = 0; i < 4; i++){
        QRCodeRawData[i] = data.codificationId[i];
    }
    lengthRawData += 4;
    
    // Write length of data
    struct BinaryNumber tmpBinNumber = decToBin(data.lengthOfData, 9);
    for(int i = 0; i < 9; i++){
        QRCodeRawData[i+lengthRawData] = tmpBinNumber.array[i];
    }  
    lengthRawData += 9;

    // Write processed payload to raw array
    for(int i = 0; i < (data.lengthOfData/2)*11; i++){
        QRCodeRawData[i+lengthRawData] = dataBlocksBinary[i];
    }
    lengthRawData += (data.lengthOfData/2)*11;

    // Add terminator (4 zeroes)
    for(int i = 0; i < 4; i++){
        QRCodeRawData[lengthRawData + i] = 0;
    }
    lengthRawData += 4;

    
    // Create blocks of eight out of QRCodeRawData
    // If zeroes are to add 
    while(lengthRawData % 8 != 0){
        QRCodeRawData[lengthRawData + 1] = 0;
        lengthRawData++;
    }

    // We use the small version 1 Qr-Code so max bits are 72
    //TODO: maybe scale Qr-Code so different versions are used
    int specialBlock1[] = {1, 1, 1, 0, 1, 1, 0, 0};
    int specialBlock2[] = {0, 0, 0, 1, 0, 0, 0 ,1};
    int counter = 0;
    // Fill up raw data with special blocks until max bits reached
    while(lengthRawData < 72){
        if(counter % 2 == 0){
            for(int i = 0; i < 8; i++){
                QRCodeRawData[lengthRawData + i] = specialBlock1[i];
            }
        }else{
            for(int i = 0; i < 8; i++){
                QRCodeRawData[lengthRawData + i] = specialBlock2[i];
            }
        }
        counter++;
        lengthRawData += 8;
    }
    
    
    printf("Binary Data: ");
    for(int i = 0; i < lengthRawData; i++){
        printf("%d", QRCodeRawData[i]);
    }
    printf("\n");
    
}
