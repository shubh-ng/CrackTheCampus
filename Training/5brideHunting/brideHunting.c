#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int getQualityCount(int rowInput, int colInput, char brideQualities[][colInput], int x, int y)
{
	int i,j;
	int count=-1;
	for(i=x-1; i<=x+1; i++){
		for(j=y-1; j<=y+1; j++){
			if((i!=0&&j!=0)||i<0||j<0||i<rowInput-1||j<colInput-1){
				if(brideQualities[i][j]=='1')
					count++;
			}
		}
	}
	return count;
}

bool findBride(int rowInput, int colInput,char brideQualities[][colInput])
{
    int i,j;    // loop variables
	bool polygamy=false;
	int maxQuality=-1,loc=INT_MAX,x=-1,y=-1;
	for(i=0; i<rowInput; i++){
		for(j=0; j<colInput; j++){
			if(brideQualities[i][j]=='1'){
				int qualityCount = getQualityCount(rowInput, colInput, brideQualities, i, j);
				int thisLoc = i>j?i:j;
				if(qualityCount>maxQuality){
					maxQuality = qualityCount;
					loc = thisLoc;
					x=i;
					y=j;
					polygamy = false;
				}else if(qualityCount==maxQuality){
					if(thisLoc<loc){
						loc = thisLoc;
						x=i;
						y=j;
					}else if(thisLoc==loc){
                        polygamy = true;
					}
				}
			}
		}
	}
	if(!polygamy)
        printf("%d:%d:%d\n", x+1,y+1,maxQuality);
	return polygamy;
}
int main()
{
    int rowInput,colInput;
    printf("Enter row and column: ");
    scanf("%d %d", &rowInput, &colInput);   // row col input
    int i,j;
    bool present=false; // any bride is present or not
    char brideQualities[rowInput][colInput];
    for(i=0; i<rowInput; i++){
        for(j=0; j<colInput; j++){
            if(brideQualities[i][j]=='1'){
                scanf("%s", &brideQualities[i][j]);
                present=true;
            }
        }
    }

    if(brideQualities[0][0]=='0')  // if sam is not there, exit
        return 0;
    if(!present){   // no bride found, exit
        printf("Invalid input, no bride found\n");
        return 0;
    }

	brideQualities[0][0]='0';   // making sam 0
	if(!findBride(rowInput, colInput,brideQualities))
        printf("POLYGAMY EXISTS");

	return 0;
}

