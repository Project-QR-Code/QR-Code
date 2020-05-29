#ifndef _MODEL_H_
#define _MODEL_H_

/// Map characters to special numbers(not ascii! alphanumerical code)
extern const char mapAlphanumericalCharacters[45];



/** Struct that holds information about QR-Code */ 
struct QRCode {

    /** Mode Number is to set type of data (Characters, Numbers etc) (4 Bit).
     *  Character = 0010 */
    int modeIndicator[4];

    /// Gives length of Data(9 Bit)
    int lengthOfData;

    /** Holds the data string we want to write into the qrcode.
     * Data gets only processed to lengthOfData
     *  data[character] 
     * */
    char data[256];
};

#endif
