#include "./drawQr.h"
#include <stdio.h>

int x=1;
int y=1;

int insertdata(int array[]){
    for(int i=0;i<SIZE-1;i++){
        drawRectangle(array[i]);
    }
}
void drawRectangle(int data){
    

    if(x<21)
        x++;
        printf("%d ",data);
    else if(x==21){
        x=0;
        y++;
        printf("%d \n",data);
    }else  
        printf("Error!!!");
}