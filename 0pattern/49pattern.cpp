/*
1
3  2
4  5  6
10 9  8  7
11 12 13 14 15
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int line=7;
	int prevRowFirstEle,prevRowLastEle,currentEle;
	prevRowLastEle=0,prevRowFirstEle=0;
	for(int row=1; row<=line; row++){
		if(row%2==0)
			currentEle = prevRowLastEle+row;
		else
			currentEle = prevRowFirstEle+1;
		for(int col=1; col<=row; col++){
			if(col==1)
				prevRowFirstEle = currentEle;
			if(col==row)
				prevRowLastEle = currentEle;
			if(row%2==0)
				printf("%d",currentEle--);
			else
				printf("%d",currentEle++);
		}
		printf("\n");
	}
	return 0;
}