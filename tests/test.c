#include "../lib/QRCode/model.h"
#include "../lib/QRCodeStructToRaw/QRCodeStructToRaw.h"
#include "../lib/rawToQrCodeStruct/rawToQrCodeStruct.h"
#include "../lib/reedSolomon/reedSolomon.h"
#include "../lib/drawQr/drawQr.h"
#include "../lib/drawQr/createPBMImage.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    // TESTING!
    struct QRCode test;
    test.modeIndicator[0] = 0;
    test.modeIndicator[1] = 0;
    test.modeIndicator[2] = 1;
    test.modeIndicator[3] = 0;
    test.lengthOfData = 4;
    char *test_string = "TEST";
    strncpy(test.data, test_string, test.lengthOfData);
    convertQrStructToRaw(test);
    printf("Binary Data: ");
    for (int i = 0; i < lengthRawData; i++){
        printf("%d", QRCodeRawData[i]);
    }
    printf("\n");

    // Decode Array read from QRCode
    struct QRCode finishedCode;
    finishedCode = decodeRawData(QRCodeRawData, lengthRawData);
    
    // Print decoded Struct
    printf("Mode Indicator: ");
    for(int i = 0; i < 4; i++){
        printf("%d", finishedCode.modeIndicator[i]);
    }
    printf("\n");

    printf("Length: %d\n", finishedCode.lengthOfData);

    printf("Data: ");
    for (int i = 0; i < finishedCode.lengthOfData; i++){
        printf("%c", finishedCode.data[i]);
    }
    printf("\n");
    drawQr(QRCodeRawData);
}
