#ifndef _QRCODESTRUCTTORAW_H_
#define _QRCODESTRUCTTORAW_H_


/// Processed Raw data
int QRCodeRawData[2064];
/// Length of Raw data
int lengthRawData;

/// Map characters to special numbers(not ascii! alphanumerical code)
const char mapAlphanumericalCharacters[45];

/** Converts struct with data to array with raw data.
  * Adds correction codes to data
  * @param[in] data QRCode struct that holds information about qr-code about to be created
  * @param[out] QRCodeRawData array with binary data for QRCode
  * @param[out] lengthRawData integer that stores length of array
  * @return void
  */
void convertQrStructToRaw(struct QRCode data);

#endif
