#ifndef _RAWTOQRCODESTRUCT_H_
#define _RAWTOQRCODESTRUCT_H_

#include "../QRCode/model.h"

/** 
 * QRCode Struct with the decoded Data
*/
struct QRCode decodedRawData;

/// Raw data to Process
int QRCodeRawData[];
/// Length of Raw data
int lengthRawData;

/// Processed Data gets cached here, delimits sections with space
int processedRawData[];


/// Get the mode (alphanumeric, ...) from rawData
void extractModeIndicator();

/// Get message Length from rawData
void extractMessageLength();

/// Encode in Binary (to chart convertable) representation 
void encodeInBinary();

/// Adds a terminator to the end of the rawdata
void addTerminator();

/// Convert binary number to String
void convertToString();

/** 
 * Wrapper for above functions.
 * @param[in] *rawData RawData read from QR-Code
 * @param[in] lengthRawData integer which stores length of rawData
 * @return *finishedCode QRCode struct with readable string in it
*/
struct QRCode decodeRawData(int *rawData, int lenghtRawData);

#endif