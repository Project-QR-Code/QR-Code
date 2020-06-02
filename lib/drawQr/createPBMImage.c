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

static int initialeFileHandler(){
    fileptr = fopen("output.pbm", "w");
    if(fileptr == NULL){
        return -1;
    }
}

static void closeFileHandler(){
    fclose(fileptr);
}

static void writeMetadata(){
    fprintf(fileptr, "%s\n", image.magicNumber);
    fprintf(fileptr, "%d %d\n", image.height, image.width);
}

static void writeArray(int rectangle[21][21]){

}


void createPBMImage(int rectangle[21][21]){
    // Fill image metadata
    strncpy(image.magicNumber, "P1", 2);
    image.height = 21;
    image.width = 21;

    if(initialeFileHandler() == -1){
        perror("File could not be opened!\n");
        return -1;
    }

    writeMetadata();

    closeFileHandler();
}