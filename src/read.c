#include "../lib/QRCode/model.h"
#include "../lib/rawToQrCodeStruct/rawToQrCodeStruct.h"
#include <stdio.h>
#include <string.h>

int main(){
    // Read from bitmap image
    // Currently developed in branch readQr
    //TODO

    int bitstream[208];
    int bitstream_length = 208;
    struct QRCode output;
    output = decodeRawData(bitstream, bitstream_length);
    printf("String: %s\n", output.data);
    return 0;
}
