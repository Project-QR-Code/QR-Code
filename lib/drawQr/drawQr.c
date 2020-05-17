#include "./drawQr.h"
#include <stdio.h>
int rectangle[LENGHT][LENGHT]={4};     

int insertdata(int array[]){
    
    prepareRectangle();

    //drawRectangle(array[]);



}
void prepareRectangle(){
    for(int j=0;j<3;j++){
		int sizey,sizex;
		int alternate=1;
		int startx,starty;
		if(j==0){
			starty=0;
			startx=0;
			sizex=7;
			sizey=7;
		}else if(j==1){
			starty=0;
			startx=14;
			sizex=21;
			sizey=7;
		}else if(j==2){
			starty=14;
			startx=0;
			sizey=21;
			sizex=7;
		}else{
			perror("Error: Z19");
		}
		
		
		for(int counter=1;counter<4;counter++){  			//3x positionserkennung
			for(int y=starty;y<(sizey);y++){
				for(int x=startx;x<(sizex);x++){
					rectangle[y][x]=alternate;
				}
			}
			if(alternate==1)
				alternate--;
			else
				alternate++;
			
			sizex--;
			sizey--;
			starty++;
			startx++;
		}
	}
}
void drawRectangle(int data){
    

    
}