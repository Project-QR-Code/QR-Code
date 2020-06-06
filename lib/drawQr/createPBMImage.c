#include "createPBMImage.h"
#include <string.h>
#include <stdio.h>

/**
 * Struct holds image metadata.
 */ 
struct PBMImageMetadata{
    /// Magic Number: P1, P2 etc. defines type of image (black&white, colors ...)
    char magicNumber[2];
    /// Height of image
    int height;
    /// Width of image
    int width;

};

/// Create Image struct
struct PBMImageMetadata image;

/// File pointer to output file
FILE *fileptr;


/**
 * Opens file handler stored in a global pointer.
 */ 
static int initialeFileHandler(){
    fileptr = fopen("output.pbm", "w");
    if(fileptr == NULL){
        return -1;
    }
    return 0;
}

/**
 * Closes file handler.
 */ 
static void closeFileHandler(){
    fclose(fileptr);
}

/**
 * Writes Metadata to bitmap image.
 * Metadata consists of magic number and size
 */ 
static void writeMetadata(){
    fprintf(fileptr, "%s\n", image.magicNumber);
    fprintf(fileptr, "%d %d\n", image.height, image.width);
}

/**
 * Writes 2d Array in .pbm file.
 */ 
static void writeArray(int rectangle[21*2][21*2]){
    for (int i = 0; i < 21*2; i++){
        for(int j = 0; j < 21*2; j++){
            fprintf(fileptr, "%d ", rectangle[i][j]);
        }
        fprintf(fileptr, "\n");
    }
}


int createPBMImage(int rectangle[21*2][21*2]){
    // Fill image metadata
    strcpy(image.magicNumber, "P1");
    image.height = 21*2;
    image.width = 21*2;

    // Create File handler, return -1 if something is wrong
    if(initialeFileHandler() == -1){
        perror("File could not be opened!\n");
        return -1;
    }

    // Write metadata to file
    writeMetadata();

    // Writes array rectangle to file
    writeArray(rectangle);

    // Closes File Handler
    closeFileHandler();
    return 0;
}