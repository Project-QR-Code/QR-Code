#ifndef _DECTOBIN_H_
#define _DECTOBIN_H_

struct BinaryNumber {
    int array[11];
    int length;
};

// Converts a decimal Number into a struct with array and bits
struct BinaryNumber decToBin(int number, int length);

// Converts binary number in decimal number
int binToDec(int binaryNumber[], int lenght);

#endif
