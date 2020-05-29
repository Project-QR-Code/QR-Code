#include "../QRCode/model.h"
#include "rawToQrCodeStruct.h"
#include "../binaryConverter/binaryConverter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * QRCode Struct with the decoded Data
*/
struct QRCode decodedRawData;

/// Raw data to Process
static int *QRCodeRawData;
/// Length of Raw data
static int lengthQRCodeRawData;




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

/** 
 * Gets two chars out of 11 Bit number.
 * @return string char[] with final decoded string
 */ 
static char* decodeToString() {
    //TODO: get exact number of length
    char *string = malloc(20 * sizeof(int));
    int counter = 0;
    // Go trough whole array
    for(int i = 13; i < lengthQRCodeRawData; i+=11){
        // So that there is no overflow
        if(i+11 > lengthQRCodeRawData){
            break;
        }
        // There are two chars stored in one 11 Bit number
        int twoCharsBinary[11];
        // Get 11 bits to get two chars
        for(int a = 0; a < 11; a++){
            twoCharsBinary[a] = QRCodeRawData[a+i];
        }
        int nextTwoCharsBits = binToDec(twoCharsBinary, 11);

        // Encode : (first_char * 45) + second_char
        // So this is the reversed
        string[counter] = mapAlphanumericalCharacters[nextTwoCharsBits / 45];
        counter++;
        string[counter] = mapAlphanumericalCharacters[nextTwoCharsBits % 45];
        counter++;
    }
    return string;
}


struct QRCode decodeRawData(int *rawData, int lenghtRawData){
    // Write parameters to local variable
    QRCodeRawData = malloc(lenghtRawData * sizeof(int));
    for(int i = 0; i < lenghtRawData; i++){
        QRCodeRawData[i] = rawData[i];
    }
    lengthQRCodeRawData = lenghtRawData;
    
    // Call extract Mode Function and write result to struct
    int *modeIndicator = extractModeIndicator();
    for(int i = 0; i < 4; i++){
        decodedRawData.modeIndicator[i] = modeIndicator;
    }
    free(modeIndicator);

    // Copy length to return struct
    decodedRawData.lengthOfData = extractMessageLength();

    printf("Length: %d\n", decodedRawData.lengthOfData);
    // Copy only the data and not the ECC Blocks in the struct data
    strncpy(decodedRawData.data, decodeToString(), decodedRawData.lengthOfData);

    printf("String: ");
    for (int i = 0; i < decodedRawData.lengthOfData; i++){
        printf("%c", decodedRawData.data[i]);
    }
    printf("\n");
    
    
    return decodedRawData;
}
