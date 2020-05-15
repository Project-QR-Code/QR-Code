#ifndef _REEDSOLOMON_H_
#define _REEDSOLOMON_H_

int messagePolynomBase[256];
int messagePolynomExpo[256];

int generatorPolynomExpoA[256];
int generatorPolynomExpoX[256];

int generatorPolynomExpoACopy[256];
int generatorPolynomExpoXCopy[256];




int* createReedSolomon(int messagePolynom[]);

/**
 * Prepares Messagepolynom and Generatorpolynom
*/
void preparePolynoms(int messagePolynom[]);

void xorResult();

void multiplyPolynom();

#endif