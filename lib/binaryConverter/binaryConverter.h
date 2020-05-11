#ifndef _DECTOBIN_H_
#define _DECTOBIN_H_

/// Struct to store Binary Number
struct BinaryNumber {
    /// Stores binary array
    int array[11];
    /// Stores length of array
    int length;
};

/** Converts a decimal Number into a BinaryNumber struct.
 *  @param[in] number decimal number to convert
 *  @param[in] length length of desired output array (rest is filled with bits)
 *  @param[out] BinaryNumber struct with binary number
 */ 
struct BinaryNumber decToBin(int number, int length);


/** Converts binary number in decimal number
 *  @param[in] binaryNumber array with binary number
 *  @param[in] length length of binary number
 *  @param[out] number converted decimal Number
 */ 
int binToDec(int binaryNumber[], int lenght);

#endif
