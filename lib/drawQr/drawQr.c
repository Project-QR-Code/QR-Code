//#include "./drawQr.h"
#include <stdio.h>
#define LENGHT 21


int insertData(int array[]);
void prepareRectangle();
void drawRectangle(int data);
int rectangle[LENGHT][LENGHT]={4};     

int main(){
	int data[]={};
	insertData(data);
	for(int i=0;i<LENGHT;i++){
		for(int j=0;j<LENGHT;j++){
			if(rectangle[i][j]==4)
				printf("- ");
			else if (rectangle[i][j]==5)
				printf("# ");
			else if(rectangle[i][j]==1)
				printf("# ");
			else
				printf("- ");
			
		}
		printf("\n");
	}
	return 0;
}
int insertData(int array[]){
    
    prepareRectangle();

    //drawRectangle(array[]);



}
void prepareRectangle(){
	//Typinformation für unseres QR-Code LVL-H Mask 0 :  001011010001001
	int typeinformation[15]={4,4,5,4,5,5,4,5,4,4,4,5,4,4,5};
	int backwardscounter=0;
	
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
	for(int y=LENGHT-1;y>=0;y--){		//vertikal  typinformation eingeben... 
		if(y==8||(rectangle[y][8]==0&&(rectangle[y][7]==4||rectangle[y+1][8]==4))){
			rectangle[y][8]=typeinformation[backwardscounter];
			backwardscounter++;
		}

	}
	for(int y=0;y<15;y++){
		//if(rectangle[])
	}
}
void drawRectangle(int data){
    
}
