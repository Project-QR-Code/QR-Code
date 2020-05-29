#include "../QRCode/model.h"
#include "rawToQrCodeStruct.h"
#include "../binaryConverter/binaryConverter.h"
#include <stdio.h>
#include <stdlib.h>

/** 
 * QRCode Struct with the decoded Data
*/
struct QRCode decodedRawData;

/// Raw data to Process
static int *QRCodeRawData;
/// Length of Raw data
static int lengthQRCodeRawData;

/// Processed Data gets cached here, delimits sections with space
static int processedRawData[];


/** 
 * Get the mode (alphanumeric, ...) from rawData.
 * @return binaryMode Returns the mode (alphanumeric, kanji ...) of the raw data
 */ 
static int* extractModeIndicator() {
    int binaryMode[4];
    // First 4 Bits in the Raw Data are the mode indicator
    for(int i = 0; i < 4; i++) {
        binaryMode[i] = QRCodeRawData[i];
    }

    return binaryMode;
}



/**
 *  Get message Length from rawData
 * @return decimalLength Returns length of string as a decimal 
 */ 
static int extractMessageLength() {
    // Length is 11 bits long and directly after mode
    int binaryLength[9];
    for(int i = 0; i < 9; i++){
        binaryLength[i] = QRCodeRawData[4+i];
    }

    // Convert binary to decimal
    int decimalLength = binToDec(binaryLength, 9);

    return decimalLength;
}

/// Encode in Binary (to chart convertable) representation 
static void encodeInBinary() {

}

/// Adds a terminator to the end of the rawdata
static void addTerminator() {

}

/// Convert binary number to String
static void convertToString() {

}

struct QRCode decodeRawData(int *rawData, int lenghtRawData){
    // Write parameters to local variable
    QRCodeRawData = malloc(lenghtRawData * sizeof(int));
    for(int i = 0; i < lenghtRawData; i++){
        QRCodeRawData[i] = rawData[i];
    }
    lengthQRCodeRawData = lenghtRawData;
    
    struct QRCode decodedRawData;

    // Call extract Mode Function and write result to struct
    int *modeIndicator = extractModeIndicator();
    for(int i = 0; i < 4; i++){
        decodedRawData.modeIndicator[i] = modeIndicator;
    }
    free(modeIndicator);


    decodedRawData.lengthOfData = extractMessageLength();
    printf("Length: %d \n", decodedRawData.lengthOfData);
    encodeInBinary();
    addTerminator();
    convertToString();
    
    /*
    for (int i = 0; i < lengthQRCodeRawData; i++){
        printf("%d", QRCodeRawData[i]);
    }
    printf("\n");
    */
    
    //return finishedCode
}
