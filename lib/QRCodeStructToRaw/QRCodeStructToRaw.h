#ifndef _QRCODESTRUCTTORAW_H_
#define _QRCODESTRUCTTORAW_H_


/// Processed Raw data
int QRCodeRawData[];
/// Length of Raw data
int lengthRawData;

/// Map characters to special numbers(not ascii! alphanumerical code)
const char mapAlphanumericalCharacters[45];

/// Converts struct with data to array with raw data
/// Adds hamming codes to data
void convertQrStructToRaw(struct QRCode data);

#endif
