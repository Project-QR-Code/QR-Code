#ifndef _DECTOBIN_H_
#define _DECTOBIN_H_

#include <stdio.h>

struct BinaryNumber {
    int array[11];
    int length;
};

// Converts a decimal Number into a struct with array and bits

struct BinaryNumber decToBin(int number, int length){
    
    struct BinaryNumber binNumber;
    // In this weird aschii the highest Number is 44, so 6 bits
    int cacheBinNumber[11] = {0};
    int i;
    int a = 0;
    for(i = 0;number > 0; i++) {    
        cacheBinNumber[i] = number % 2;    
        number = number / 2;    
    }
    /*
    for(int c = i+1; c < 11; c++){
        cacheBinNumber[a] = 0;
    }
    */

    binNumber.length = length;

    // Reverse numbers and store in struct
    for(int b = 0; b < length; b++){
        binNumber.array[b] = 0; 
    }
    for(int b = length-1; b >= 0; b--){
        binNumber.array[a] = cacheBinNumber[b];
        a++;
    }

    return binNumber; 
}

int binToDec(int binaryNumber[], int lenght){
    // Create Binary to Decimal Converter
}

#endif
