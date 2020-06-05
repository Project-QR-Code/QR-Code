#ifndef _DRAWQR_H_
#define _DRAWQR_H_
// Our version has 21x21 size
#define LENGHT 21 


/**
 * Wrapper function around prepareRectangle and drawRectangle.
 * @param[in] data Array of data that has to be written in qr-code
*/
void insertData(int *data);

/**
 * Draws Information and position detection fields about QrCode in 2d array.
 * Information is ECC Level, Mask and the three position detection fields
 */ 
void prepareRectangle();

/**
 * Writes actual data in 2d array.
 * @param[in] data Array of data that has to be written in qr-code
 */ 
void drawRectangle(int *data);

/**
 * Wrapper function around all above.
 * @param[in] data Array of data that has to be written in qr-code
 */ 
void drawQr(int *data);

#endif
