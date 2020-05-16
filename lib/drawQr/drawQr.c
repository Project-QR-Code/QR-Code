#include "./drawQr.h"
#include <stdio.h>

int x=1;
int y=1;

int insertdata(int array[]){
    for(int i=0;i<(LENGHT*LENGHT)-1;i++){
        if(x<LENGHT){
            x++;
            printf("%d ",array[i]);
        }else if(x==LENGHT){
            x=0;
            y++;
            printf("%d \n",array[i]);
        }else if(y==LENGHT)
            printf("Done!");
        else
            printf("Error!!!");
        
    }
}
void drawRectangle(int data){
    

    
}