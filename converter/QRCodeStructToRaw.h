#ifndef _QRCODESTRUCTTORAW_H_
#define _QRCODESTRUCTTORAW_H_


// Processed Raw data
int QRCodeRawData[];
// Length of Raw data
int lengthRawData;

// Map characters to special numbers(not ascii! alphanumerical code)
static const char mapCharacters[45] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', \
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '$', '%', '*', '+', '-', '.', '/', ':'};

int getIndexInMapCharacters(char query);


// Converts struct with data to array with raw data
// Adds hamming codes to data
void convertQrStructToRaw(struct QRCode data);

#endif
