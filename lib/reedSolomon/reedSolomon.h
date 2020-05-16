#ifndef _REEDSOLOMON_H_
#define _REEDSOLOMON_H_

/// Base of MessagePolynom gets provided
int messagePolynomBase[256];
/// Exponents of MessagePolynom get generated
int messagePolynomExpo[256];

/// GeneratorPolynom Exponents of alpha
int generatorPolynomExpoA[256];
/// GeneratorPolynom Exponents of x
int generatorPolynomExpoX[256];

/// Copy of GeneratorPolynom Exponents of alpha
int generatorPolynomExpoACopy[256];
/// Copy of GeneratorPolynom Exponents of x
int generatorPolynomExpoXCopy[256];



/** 
 * Wrapper function that calles the other functions. 
 * @param[in] messagePolynom Original messagepolynom
 * @return finishedPolynom Processed generatorpolynom
*/
int* createReedSolomon(int messagePolynom[]);

/**
 * Prepares Messagepolynom and Generatorpolynom.
 * Filles up messagepolynom and geneatorpolynom
 * @param[in] messagePolynom Original messagepolynom
*/
void preparePolynoms(int messagePolynom[]);

/** 
 * XORs generatorPolynom with previous generatorPolynom. 
*/
void xorResult();

/** 
 * Multiplies generatorPolynom with lead of previous generatorPolynom.
*/
void multiplyPolynom();

#endif