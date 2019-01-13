/*
1
22
333
2222
11111
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int line=5;
	int rowEle;
	for(int row=1; row<=line; row++){
		if(row>(line/2)+1)
			rowEle--;
		else
			rowEle=row;
		for(int col=1; col<=row; col++){
			printf("%d",rowEle);
		}
		printf("\n");
	}
	return 0;
}