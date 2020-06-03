#include "../lib/QRCode/model.h"
#include "../lib/QRCodeStructToRaw/QRCodeStructToRaw.h"
#include "../lib/reedSolomon/reedSolomon.h"
#include "../lib/drawQr/drawQr.h"
#include "../lib/drawQr/createPBMImage.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int data[] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0};

int main(){
    // TESTING!
    struct QRCode test;
    test.codificationId[0] = 0;
    test.codificationId[1] = 0;
    test.codificationId[2] = 1;
    test.codificationId[3] = 0;
    test.lengthOfData = 4;
    char *test_string = "TEST";
    strcpy(test.data, test_string);
    convertQrStructToRaw(test);
    printf("\n");
    drawQr(QRCodeRawData);
}
