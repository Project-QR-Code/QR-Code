#include "../QRCode/model.h"
#include "../binaryConverter/binaryConverter.h"
#include "./QRCodeStructToRaw.h"
#include "../reedSolomon/reedSolomon.h"
#include <stdio.h>
#include <stdlib.h>

const char mapAlphanumericalCharacters[45] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                              'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '$', '%', '*', '+', '-', '.', '/', ':'};

/// Returns index of searched char in mapCharacters
static int getIndexInMapCharacters(char query){
    for (int i = 0; i < 45; i++){
        if (mapAlphanumericalCharacters[i] == query){
            return i;
        }
    }
    return -1;
}

/**
 * Searches for character in alphanumeric characters.
 * @param[in] query Char query to search in alphanumericalCharacter
 * @return status returns 0 if char has been found -1 if not
*/
static int isInMapCharacters(char query){
    for (int i = 0; i < 45; i++){
        if (query == mapAlphanumericalCharacters[i]){
            return 0;
        }
    }
    return -1;
}


/** 
 * Checks if Array has only character present in alphanumericalCharacters.
 * @param[in] data QrStruct data to check integrity
 * @return status returns 0 if data is correct, -1 if not 
*/
static int integrityCheckDataArray(struct QRCode data) {
    for (int i = 0; i < data.lengthOfData; i++){
        if (isInMapCharacters(data.data[i]) == -1){
            fprintf(stderr, "Input data is not valid!\n");
            return -1;
        }
    }
    return 0;
}


/** 
 * Adds Error Correction blocks from Reed solomon code to QRCodeRawData
*/
static void addErrorCorrectionBlocks() {
    // Convert Blocks into decimal data
    // 9 For the data and then 17 for the correction blocks
    int decimalNumbers[9 + 17];

    for (int i = 0; i < lengthRawData; i += 8){
        int tmp[8];
        for (int b = 0; b < 8; b++){
            tmp[b] = QRCodeRawData[i + b];
        }
        decimalNumbers[i / 8] = binToDec(tmp, 8);
    }

    /// Stores correction blocks returned by createReedSolomon
    int *decimalCorrectionBlocks = malloc(sizeof(int) * 17);

    // ECC Blocks is 17
    // Call reed Solomon wrapper function, returns 17 error codes 
    decimalCorrectionBlocks = createReedSolomon(decimalNumbers);



    // Add correction Blocks to decimal Numbers
    for (int i = 0; i < 17; i++){
        decimalNumbers[9 + i] = decimalCorrectionBlocks[i];
    }

    // Convert Decimal Numbers with correction back to binary
    int counter = 0;
    for (int i = 0; i < 26; i++){
        struct BinaryNumber number = decToBin(decimalNumbers[i], 8);
        for (int a = 0; a < 8; a++){
            QRCodeRawData[counter] = number.array[a];
            counter++;
        }
    }
    // Adjust Lenght variable to new length
    lengthRawData = 26 * 8;
}



void convertQrStructToRaw(struct QRCode data){
    // Character Data of QRCode in binary (without id and length)
    int dataBlocksBinary[256];
    int lengthDataBlocksBinary = 0;

    integrityCheckDataArray(data);

    // Create Blocks of 2 Characters and calculate binary Number
    for (int i = 0; i < data.lengthOfData; i += 2){

        // Calculate Block Value
        int blockDecValue = getIndexInMapCharacters((char)data.data[i]) * 45;
        blockDecValue += getIndexInMapCharacters((char)data.data[i + 1]);
        // Convert block value to binary number
        struct BinaryNumber tempBinNumber = decToBin(blockDecValue, 11);
        // Extend binary number into length of 11 Bits (attach 0)

        int missingZeroes = 11 - tempBinNumber.length;
        for (int a = lengthDataBlocksBinary; a < (lengthDataBlocksBinary + missingZeroes); a++){
            dataBlocksBinary[a] = 0;
        }
        int b = 0;
        for (int a = lengthDataBlocksBinary + missingZeroes; a < lengthDataBlocksBinary + 11; a++){
            dataBlocksBinary[a] = tempBinNumber.array[b];
            b++;
        }
        lengthDataBlocksBinary += 11;
    }

    // Write Type of Data (codification id)
    for (int i = 0; i < 4; i++){
        QRCodeRawData[i] = data.codificationId[i];
    }
    lengthRawData += 4;

    // Write length of data
    struct BinaryNumber tmpBinNumber = decToBin(data.lengthOfData, 9);
    for (int i = 0; i < 9; i++){
        QRCodeRawData[i + lengthRawData] = tmpBinNumber.array[i];
    }
    lengthRawData += 9;

    // Write processed payload to raw array
    for (int i = 0; i < (data.lengthOfData / 2) * 11; i++){
        QRCodeRawData[i + lengthRawData] = dataBlocksBinary[i];
    }
    lengthRawData += (data.lengthOfData / 2) * 11;

    // Add terminator (4 zeroes)
    for (int i = 0; i < 4; i++){
        QRCodeRawData[lengthRawData + i] = 0;
    }
    lengthRawData += 4;

    // Create blocks of eight out of QRCodeRawData
    // If zeroes are to add
    while (lengthRawData % 8 != 0){
        QRCodeRawData[lengthRawData + 1] = 0;
        lengthRawData++;
    }

    // We use the small version 1 Qr-Code so max bits are 72
    int specialBlock1[] = {1, 1, 1, 0, 1, 1, 0, 0};
    int specialBlock2[] = {0, 0, 0, 1, 0, 0, 0, 1};
    int counter = 0;
    // Fill up raw data with special blocks until max bits reached
    while (lengthRawData < 72){
        if (counter % 2 == 0){
            for (int i = 0; i < 8; i++){
                QRCodeRawData[lengthRawData + i] = specialBlock1[i];
            }
        }else{
            for (int i = 0; i < 8; i++){
                QRCodeRawData[lengthRawData + i] = specialBlock2[i];
            }
        }
        counter++;
        lengthRawData += 8;
    }

    addErrorCorrectionBlocks();

    printf("Binary Data: ");
    for (int i = 0; i < lengthRawData; i++){
        printf("%d", QRCodeRawData[i]);
    }
    printf("\n");
}
