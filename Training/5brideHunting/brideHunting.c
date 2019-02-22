#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define INT_MAX 32767
#define ROWS 6
#define COLS 6

int getQualityCount(int rowInput, int colInput, char brideQualities[][colInput], int x, int y)
{
	int i,j;
	int count=-1;
	for(i=x-1; i<=x+1; i++){
		for(j=y-1; j<=y+1; j++){
			if((i!=0&&j!=0)||i<0||j<0||i<rowInput||j<colInput){
				if(brideQualities[i][j]=='1')
					count++;
			}
		}
	}
	return count;
}

int main()
{
	int rowInput,colInput;
	printf("Enter row and column: ");
	scanf("%d %d", &rowInput, &colInput);

	// user input
	// char brideQualities[rowInput][colInput];
	int i,j;
	// bool present = false;
	// for(i=0; i<rowInput; i++){
	// 	for(j=0; j<colInput; j++){
	// 		scanf("%c",&brideQualities[i][j]);
	// 		if((i!=0&&j!=0)&&brideQualities[i][j]=='1')
	// 			present = true;
	// 	}
	// }
	// if(!present){
	// 	printf("Invalid input, no brides present\n");
	// 	return 0;
	// }
	// user input

	char brideQualities[ROWS][COLS]={

	// 1:7:3
	
		// {'1', '0', '1', '1', '0', '1', '1', '1', '1'},
		// {'0', '0', '0', '1', '0', '1', '0', '0', '1'}
	
 	// 4:4:8
		// {'1', '0', '0', '0', '0', '0'},
		// {'0', '0', '0', '0', '0', '0'},
		// {'0', '0', '1', '1', '1', '0'},
		// {'0', '0', '1', '1', '1', '0'},
		// {'0', '0', '1', '1', '1', '0'},
		// {'0', '0', '0', '0', '0', '0'}

	// polygamy
		// {'1', '0', '0', '0', '0', '0'},
		// {'0', '0', '0', '0', '0', '0'},
		// {'0', '0', '1', '0', '1', '0'},
		// {'0', '0', '0', '0', '0', '0'},
		// {'0', '0', '1', '0', '1', '0'},
		// {'0', '0', '0', '0', '0', '0'}	
	

	};
	int qualities[ROWS][COLS]={0};

	brideQualities[0][0]='0';
	int maxQuality=-1,loc=INT_MAX,x=-1,y=-1;
	for(i=0; i<rowInput; i++){
		for(j=0; j<colInput; j++){
			if(brideQualities[i][j]=='1'){
				int qualityCount = getQualityCount(rowInput, colInput, brideQualities, i, j);
				qualities[i][j] = qualityCount;
				int thisLoc = i>j?i:j;
				if(qualityCount>maxQuality){
					maxQuality = qualityCount;
					loc = thisLoc;
					x=i;
					y=j;
				}else if(qualityCount==maxQuality){
					if(thisLoc<loc){
						loc = thisLoc;
						x=i;
						y=j;
					}
				}
			}
		}
	}
	qualities[x][y]=0;

	// Polygamy check
	for(i=0; i<rowInput; i++){
		for(j=0; j<colInput; j++){
			if(qualities[i][j]==maxQuality){
				int thisLoc = i>j?i:j;
				if(thisLoc==loc){
					printf("POLYGAMY EXISTS\n");
					return 0;
				}
			}
		}
	}
	printf("%d:%d:%d\n", x+1,y+1,maxQuality);

	return 0;
}
