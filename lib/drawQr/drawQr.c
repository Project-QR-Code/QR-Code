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
		int alternate=5;
		int startx,starty;
		int county,countx;
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
		
		
		for(int counter=1;counter<4;counter++){  			//3x positionserkennungsfeld
			for(int y=starty;y<(sizey);y++){
				for(int x=startx;x<(sizex);x++){
					rectangle[y][x]=alternate;
				}
			}
			if(alternate==5)
				alternate--;
			else if(alternate==4)
				alternate++;
			else
				printf("Error");

			sizex--;
			sizey--;
			starty++;
			startx++;
		}
	}
	for(int times=0;times<3;times++){
		int sizey,sizex;
		int county,countx;
		if(times==0){
			county=0;
			countx=0;
			sizey=8;
			sizex=8;
		}else if(times==1){
			county=0;
			countx=13;
			sizey=8;
			sizex=21;
		}else if(times==2){
			county=13;
			countx=0;
			sizey=21;
			sizex=8;
		}
		
		for(int y=county;y<sizey;y++){			//weiße "rahmen" der felder
			for(int x=countx;x<sizex;x++){
				if(rectangle[y][x]==0)
					rectangle[y][x]=4;
			}
		}
		
		
	}
	rectangle[6][8]=5;			//linien, die die felder(oben) verbinden
	rectangle[6][10]=5;
	rectangle[6][12]=5;
	rectangle[6][9]=4;
	rectangle[6][11]=4;
	
	rectangle[8][6]=5;
	rectangle[10][6]=5;
	rectangle[12][6]=5;
	rectangle[9][6]=4;
	rectangle[11][6]=4;
	
	rectangle[13][8]=5;			//punkt links unten
}
void drawRectangle(int data){
    

    
}