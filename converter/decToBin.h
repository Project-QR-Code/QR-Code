#ifndef _DECTOBIN_H_
#define _DECTOBIN_H_

struct BinaryNumber {
    int array[256];
    int length;
};

// Converts a decimal Number into a struct with array and bits

struct BinaryNumber decToBin(int number){
    
    struct BinaryNumber binNumber;
    // In this weird aschii the highest Number is 44, so 6 bits
    int cacheBinNumber[7];
    int i;
    int a = 0;
    for(i = 0;number > 0; i++) {    
        cacheBinNumber[i] = number % 2;    
        number = number / 2;    
    }

    binNumber.length = i;

    // Reverse numbers and store in struct
    for(i = i - 1; i >= 0; i--) {
        a++;
        binNumber.array[a] = cacheBinNumber[i];
    }   

    return binNumber; 
}

#endif
