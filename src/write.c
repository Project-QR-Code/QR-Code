#include "../lib/QRCode/model.h"
#include "../lib/QRCode/model.h"
#include "../lib/QRCodeStructToRaw/QRCodeStructToRaw.h"
#include "../lib/rawToQrCodeStruct/rawToQrCodeStruct.h"
#include "../lib/drawQr/drawQr.h"
#include "../lib/drawQr/createPBMImage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    printf("QR-Code Generator\n");
    printf("by Gabriel Valentin, Silas Demez, Gabriel Goller\n\n\n");

    printf("Input Message: (Only Upper-case and alphanumeric character)\n");
    char *input = malloc(20 * sizeof(char));
    scanf("%s", input);
    printf("\n");

    struct QRCode newInput;
    // Write Mode code (alphanumerical) to struct
    newInput.modeIndicator[0] = 0;
    newInput.modeIndicator[1] = 0;
    newInput.modeIndicator[2] = 1;
    newInput.modeIndicator[3] = 0;
    // Get length of message
    newInput.lengthOfData = strlen(input);
    // Copy message to Qr struct
    strncpy(newInput.data, input, newInput.lengthOfData);
    // Convert data and metadata struct to raw bits
    convertQrStructToRaw(newInput);
    // Draw Qr-Code in 2d Array then in bitmap image
    drawQr(QRCodeRawData);

    printf("The bitmap file is in the root folder!\n");

    return 0;
}
