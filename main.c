#include "model.h"
#include "./converter/QRCodeStructToRaw.h"
#include <stdio.h>
#include <string.h>

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
    return 0;
}
