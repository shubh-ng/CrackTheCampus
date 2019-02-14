#include <stdio.h>

// getting index of bride with maximum quality and nearer to sam
int getMaximumQualityIndex(int row[], int col[], int qualityCount[], int index){
	int maxIndex=0;
	int maxQuality=qualityCount[0];
	for(int i=1; i<index; i++){
		if(qualityCount[i]>maxQuality){
			maxQuality = qualityCount[i];
			maxIndex=i;
		}else if(qualityCount[i]==maxQuality){
			if(row[maxIndex]+col[maxIndex]>row[i]+col[i])
				maxIndex=i;
		}
	}
	return maxIndex;
}

// counting qualities of brides
void countQualities(int r, int c,char brideWithQualities[][c], int row[],int col[],int qualityCount[]){
	int rowIndex=0,colIndex=1,index=0;
	for(int i=rowIndex; i<r; i++){
		for(int j=colIndex; j<c; j++){
			if(brideWithQualities[i][j]=='0'){			
				continue;
			}
			else{
				row[index] = i;
				col[index] = j;
						if(brideWithQualities[i][j-1]=='1'){
							qualityCount[index]++;
						}
						if(brideWithQualities[i][j+1]=='1'){
							qualityCount[index]++;
						}
						if(brideWithQualities[i+1][j]=='1'){
							qualityCount[index]++;
						}
						if(brideWithQualities[i+1][j-1]=='1'){
							qualityCount[index]++;
						}
						if(brideWithQualities[i+1][j+1]=='1'){
							qualityCount[index]++;
						}
						if(brideWithQualities[i-1][j]=='1'){
							qualityCount[index]++;
						}
						if(brideWithQualities[i-1][j-1]=='1'){
							qualityCount[index]++;
						}
						if(brideWithQualities[i-1][j+1]=='1'){
							qualityCount[index]++;
						}
				index++;
			}
		}
	}
	int maxQualityBride = getMaximumQualityIndex(row, col, qualityCount, index);
	printf("%d:%d:%d\n", row[maxQualityBride]+1,col[maxQualityBride]+1,qualityCount[maxQualityBride]);
}

int main()
{
	int rowInput,colInput;
	printf("Enter row and column: ");
	scanf("%d %d", &rowInput, &colInput);
	char brideWithQualities[rowInput][colInput]={

	// 1:7:3
		{'1', '0', '1', '1', '0', '1', '1', '1', '1'},
		{'0', '0', '0', '1', '0', '1', '0', '0', '1'}

	// 4:4:8
	// {'1', '0', '0', '0', '0', '0'},
	// {'0', '0', '0', '0', '0', '0'},
	// {'0', '0', '1', '1', '1', '0'},
	// {'0', '0', '1', '1', '1', '0'},
	// {'0', '0', '1', '1', '1', '0'},
	// {'0', '0', '0', '0', '0', '0'}
	

	};
	int row[10],col[10],qualityCount[10]={0};
	countQualities(rowInput, colInput, brideWithQualities,row, col,qualityCount);
}
