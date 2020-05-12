#ifndef _MODEL_H_
#define _MODEL_H_

/** Array that Stores data and all ids and markings in order.
    Max Number is calculated with basic data(redundance not included!) */
int QRCodeRawData[2064];

/** Struct that holds information about QR-Code */ 
struct QRCode {

    /** Identification Number is to set type of data (Characters, Numbers etc) (4 Bit).
     *  Character = 0010 */
    int codificationId[4];

    /// Gives length of Data(9 Bit)
    int lengthOfData;

    /** Maximum Character of QR-Code is 256. But we process only that much data as lengthOfData holds.
     *  data[character] */
    char data[256];
};

#endif
