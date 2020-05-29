#include "../lib/QRCode/model.h"
#include "../lib/QRCodeStructToRaw/QRCodeStructToRaw.h"
#include "../lib/rawToQrCodeStruct/rawToQrCodeStruct.h"
#include "../lib/reedSolomon/reedSolomon.h"
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
    strcpy(test.data, test_string);
    convertQrStructToRaw(test);
    printf("Binary Data: ");
    for (int i = 0; i < lengthRawData; i++){
        printf("%d", QRCodeRawData[i]);
    }
    printf("\n");
    struct QRCode finishedCode;
    finishedCode = decodeRawData(QRCodeRawData, lengthRawData);

}
