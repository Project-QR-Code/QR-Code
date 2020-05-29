#ifndef _RAWTOQRCODESTRUCT_H_
#define _RAWTOQRCODESTRUCT_H_

#include "../QRCode/model.h"


/** 
 * Wrapper for above functions.
 * @param[in] *rawData RawData read from QR-Code
 * @param[in] lengthRawData integer which stores length of rawData
 * @return decodedRawData QRCode struct with readable string in it
*/
struct QRCode decodeRawData(int *rawData, int lenghtRawData);

#endif