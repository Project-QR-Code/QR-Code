#include<stdio.h>
   unsigned char bitmap[1300];
int data[] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0};


void BMPmake()
{
    int i,noColor=256,end_color=54+4*noColor;
    static unsigned char temp=0;
    // -- FILE HEADER -- //

    // bitmap signature
    bitmap[0] = 'B';
    bitmap[1] = 'M';

    // file size
    bitmap[2] = 0xc6; // 40 + 14 + 256*4+400
    bitmap[3] = 0x05;
    bitmap[4] = 0;
    bitmap[5] = 0;

    // reserved field (in hex. 00 00 00 00)
    for( i = 6; i < 10; i++) bitmap[i] = 0;

    // offset of pixel data inside the image
    //The offset, i.e. starting address, of the byte where the bitmap image data (pixel array) can be found.
    //here 1078
    bitmap[10]=0x36;
    bitmap[11]=0x04;
    for( i = 12; i < 14; i++) bitmap[i] = 0;


    // -- BITMAP HEADER -- //

    // header size
    bitmap[14] = 40;
    for( i = 15; i < 18; i++) bitmap[i] = 0;

    // width of the image
    bitmap[18] = 21;
    for( i = 19; i < 22; i++) bitmap[i] = 0;

    // height of the image
    bitmap[22] = 21;
    for( i = 23; i < 26; i++) bitmap[i] = 0;

    // no of color planes, must be 1
    bitmap[26] = 1;
    bitmap[27] = 0;

    // number of bits per pixel
    bitmap[28] = 8; // 1 byte
    bitmap[29] = 0;

    // compression method (no compression here)
    for( i = 30; i < 34; i++) bitmap[i] = 0;

    // size of pixel data
    bitmap[34] = 0x90; // 400 bytes => 400 pixels ,,,, 20x20x1
    bitmap[35] = 0x01;//0x190
    bitmap[36] = 0;
    bitmap[37] = 0;

    // horizontal resolution of the image - pixels per meter (2835)
    bitmap[38] = 0;
    bitmap[39] = 0;
    bitmap[40] = 0;
    bitmap[41] = 0;

    // vertical resolution of the image - pixels per meter (2835)
    bitmap[42] = 0;
    bitmap[43] = 0;
    bitmap[44] = 0;
    bitmap[45] = 0;

    // color palette information here 256
    bitmap[46]=0;
    bitmap[47]=1;
    for( i = 48; i < 50; i++) bitmap[i] = 0;

    // number of important colors
    // if 0 then all colors are important
    for( i = 50; i < 54; i++) bitmap[i] = 0;

    //Color Palette
    //for less then or equal to 8 bit BMP Image we have to create a 4*noofcolor size color palette which is nothing but
    //[BLUE][GREEN][RED][ZERO] values
    //for 8 bit we have the following code
    for (i=54;i<end_color;i+=4)
    {
        bitmap[i]=temp;
        bitmap[i+1]=temp;
        bitmap[i+2]=temp;
        bitmap[i+3]=0;
        temp++;
    }

    // -- PIXEL DATA -- //
    for( i = end_color; i < end_color+400; i++) bitmap[i] = data[i];
}

void BMPwrite()
{
    FILE *file;
    int i;

    //use wb+ when writing to binary file .i.e. in binary form whereas w+ for txt file.
    file = fopen("b.bmp", "wb+");
    for( i = 0; i < 1478; i++)
    {
        fputc(bitmap[i], file);
    }
    fclose(file);
}
void main()
{

    BMPmake();
    BMPwrite();
    printf("Done!!");
}