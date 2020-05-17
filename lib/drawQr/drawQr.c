#include "./drawQr.h"
#include <stdio.h>
int rectangle[][]={4};     

int insertdata(int array[]){
    
   
    
    prepareRectangle();

    drawRectangle(array[i])



    /*for(int i=0;i<(LENGHT*LENGHT)-1;i++){
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
        
    }*/
}
void prepareRectangle(){
   /* for(int i=0;i<LENGHT;i++){
        for(int j=0;j<LENGHT;j++){
            if(rectangle[])
        }
    }*/
    int size=7
    int start=0
    for(int counter=0;counter<4;counter++){
        
        for(int y=start;y<size+start;y++){
            for(int x=start;x<size+start,x++){
                rectangle[y][x]=1;
            }
        }
        size--;
        start++;    
    }
}
void drawRectangle(int data){
    

    
}