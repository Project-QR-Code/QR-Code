#ifndef _CREATEPBMIMAGE_H_
#define _CREATEPBMIMAGE_H_


/**
 * Wrapper function, creates .pbm image from 2d array with data.
 * @param[in] rectangle[][] 2d array with data to write
 * @return status Returns status (-1)=something is wrong
 */ 
int createPBMImage(int rectangle[21][21]);

#endif