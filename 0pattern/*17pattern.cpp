/*
1	2	3	4	5
16	17	18	19	6
15	24	25	20	7
14	23	22	21	8
13	12	11	10	9
*/
#include <iostream>
using namespace std;

void printPattern(int arr[6][6])
{
	for(int row=1; row<=5; row++){
		for(int col=1; col<=5; col++)
			printf("%4d",arr[row][col]);
		printf("\n");
	}
}

int main()
{
	int line=5;
	int runner=2;
	int arr[6][6];
	arr[1][1] = 1;
	int rowRunner=1,colRunner=2;
	int row=1,col=1;
	int i=1,j=1;
	while(runner<=25){
		int k=0;
		for(k=i; k<=line-1; k++){
			printf("Runner:%d\n",runner);
			if(runner>25)	break;
			arr[rowRunner][colRunner++] = runner++;
		}
			if(runner>25)	break;
		--colRunner;
		for(k=j; k<=line-1; k++){
			printf("Runner:%d\n",runner);
			if(runner>25)	break;
			arr[rowRunner++][colRunner] = runner++;
		}
			if(runner>25)	break;

		--rowRunner;
		i = k-1;
		j = i-1;
	}

	printPattern(arr);
	return 0;
}