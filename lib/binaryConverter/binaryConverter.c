#include <stdio.h>
#include "./binaryConverter.h"


/// Converts a decimal Number into a struct with array and bits
struct BinaryNumber decToBin(int number, int length){
    
    struct BinaryNumber binNumber;
    /// In this weird aschii the highest Number is 44, so 6 bits
    int cacheBinNumber[11] = {0};
    int i;
    int a = 0;
    for(i = 0;number > 0; i++) {    
        cacheBinNumber[i] = number % 2;    
        number = number / 2;    
    }

    binNumber.length = length;

    /// Reverse numbers and store in struct
    for(int b = 0; b < length; b++){
        binNumber.array[b] = 0; 
    }
    for(int b = length-1; b >= 0; b--){
        binNumber.array[a] = cacheBinNumber[b];
        a++;
    }

    return binNumber; 
}

/// Converts binary number in decimal number
int binToDec(int binaryNumber[], int length){
    int indexValue = 1;
    int number = 0;

    // Test if number is correct
    for(int i = 0; i < length; i++){
        if(binaryNumber[i] != 1 && binaryNumber[i] != 0){
            fprintf(stderr, "Number is not a binary Number!\n");
            return -1;
        }
    }

    /// Calculate decimal Number
    for(int i = length-1; i >= 0; i--){
        if(binaryNumber[i] == 1){
            number += indexValue;
        }

        if(i == length){
            indexValue++;
        }else{
            indexValue *= 2;
        }
    }
    return number;
}
