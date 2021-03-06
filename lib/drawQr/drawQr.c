#include "./drawQr.h"
#include <stdio.h>
#include "./createPBMImage.h"

int rectangle[LENGHT][LENGHT] = {{4}};

void drawQr(int *data){
	insertData(data);
	
	//Scale .pbm image
	int rectangleScaled[LENGHT*2][LENGHT*2] = {0};
	int counteri = 0;
	int counterx = 0;
	for(int i = 0; i < LENGHT*2; i+=2){
		for(int x = 0; x < LENGHT*2; x+=2){
			int cache = rectangle[counteri][counterx];
			rectangleScaled[i][x] = cache;
			rectangleScaled[i+1][x] = cache;
			rectangleScaled[i+1][x+1] = cache;
			rectangleScaled[i][x+1] = cache;
			counterx++;
		}
		counteri++;
		counterx = 0;
	}

	createPBMImage(rectangleScaled);
}

void insertData(int *data){
	prepareRectangle();
	drawRectangle(data);
	
	// Convert 4 and 5s of position detecting field to 1 and 0
	for(int i = 0; i < LENGHT; i++){
		for(int x = 0; x < LENGHT; x++){
			if(rectangle[i][x] == 5){
				rectangle[i][x] = 1;
			}else if (rectangle[i][x] == 4){
				rectangle[i][x] = 0;
			}
		}
	}
}

void prepareRectangle(){
	//Typinformation für unseres QR-Code LVL-H Mask 0 :  001011010001001
	int typeinformation[15] = {4, 4, 5, 4, 5, 5, 4, 5, 4, 4, 4, 5, 4, 4, 5};
	int backwardscounter = 0;

	for (int j = 0; j < 3; j++){
		int sizey, sizex;
		(void)sizex;
		(void)sizey;
		int alternate = 5;
		int startx, starty;
		int county, countx;
		(void)countx;
		(void)county;
		if (j == 0){
			starty = 0;
			startx = 0;
			sizex = 7;
			sizey = 7;
		}else if (j == 1){
			starty = 0;
			startx = 14;
			sizex = 21;
			sizey = 7;
		}else if (j == 2){
			starty = 14;
			startx = 0;
			sizey = 21;
			sizex = 7;
		}else{
			perror("Error: Z19");
		}

		for (int counter = 1; counter < 4; counter++){ 
			//3x positionserkennungsfeld
			for (int y = starty; y < (sizey); y++){
				for (int x = startx; x < (sizex); x++){
					rectangle[y][x] = alternate;
				}
			}
			if (alternate == 5)
				alternate--;
			else if (alternate == 4)
				alternate++;
			else
				perror("Error");

			sizex--;
			sizey--;
			starty++;
			startx++;
		}
	}

	for (int times = 0; times < 3; times++){
		int sizey, sizex;
		int county, countx;
		if (times == 0){
			county = 0;
			countx = 0;
			sizey = 8;
			sizex = 8;
		}else if (times == 1){
			county = 0;
			countx = 13;
			sizey = 8;
			sizex = 21;
		}else if (times == 2){
			county = 13;
			countx = 0;
			sizey = 21;
			sizex = 8;
		}

		for (int y = county; y < sizey; y++){ 
			//weiße "rahmen" der felder
			for (int x = countx; x < sizex; x++){
				if (rectangle[y][x] == 0)
					rectangle[y][x] = 4;
			}
		}
	}
	rectangle[6][8] = 5; //linien, die die felder(oben) verbinden
	rectangle[6][10] = 5;
	rectangle[6][12] = 5;
	rectangle[6][9] = 4;
	rectangle[6][11] = 4;

	rectangle[8][6] = 5;
	rectangle[10][6] = 5;
	rectangle[12][6] = 5;
	rectangle[9][6] = 4;
	rectangle[11][6] = 4;

	rectangle[13][8] = 5; //punkt links unten
	for (int y = LENGHT - 1; y >= 0; y--){ 
		//vertikal  typinformation eingeben...
		if (y == 8 || (rectangle[y][8] == 0 && (rectangle[y][7] == 4 || rectangle[y + 1][8] == 4))){
			rectangle[y][8] = typeinformation[backwardscounter];
			backwardscounter++;
		}
	}
	backwardscounter = (sizeof(typeinformation) / 4) - 1;
	for (int y = LENGHT - 1; y >= 0; y--){ 
		//vertikal  typinformation eingeben...
		if ((rectangle[8][y] == 0 && (rectangle[7][y] == 4 || rectangle[8][y + 1] == 4))){
			rectangle[8][y] = typeinformation[backwardscounter];
			backwardscounter--;
		}
	}
}


void drawRectangle(int *data){
	// Input-Mask == (x+y)%2 , if result is zero, bit gets flipped

	
	int counter = 0;
	int currHeightEnd = 12;
	int currHeightStart = 1;
	int changeDirectionFlag = 0;
	// columns and rows are here the coordinates according to the qr-code, not the 2d array
	for(int columns = 21; columns > 0; columns-=2){
		if(changeDirectionFlag == 0){
			for(int rows = currHeightStart; rows <= currHeightEnd; rows++){
				// Skip info line in top middle
				if(currHeightEnd == 21 && rows == 15){
					rows++;
				}

				int cache = data[counter];
				
				// Apply mask 0
				if(( columns + rows ) % 2 == 0){
					cache = 1 - cache;
				}
				rectangle[21-rows][columns-1] = cache;
				
				counter++;
				cache = data[counter];
				if(( (columns-1) + rows ) % 2 == 0){
					cache = 1 - cache;
				}
				rectangle[21-rows][columns-2] = cache;
				counter++;
			}
		}else{
			for(int rows = currHeightEnd; rows >= currHeightStart; rows--){
				// Skip info line in top middle
				if(currHeightEnd == 21 && rows == 15){
					rows--;
				}
				
				int cache = data[counter];
				// Apply mask 0
				if(( columns + rows ) % 2 == 0){
					cache = 1 - cache;
				}
				rectangle[21-rows][columns-1] = cache;
				
				counter++;
				cache = data[counter];
				if(( (columns-1) + rows ) % 2 == 0){
					cache = 1 - cache;
				}
				rectangle[21-rows][columns-2] = cache;
				counter++;
			}
		}
		if(columns == 15){
			currHeightEnd = 21;
		}
		if(columns == 11){
			currHeightEnd = 12;
			currHeightStart = 9;
		}

		
		if(columns == 9){
			columns -= 1;
		}

		changeDirectionFlag = 1 - changeDirectionFlag;
	}
}