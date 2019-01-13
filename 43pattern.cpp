/*
1
2  3
4  5  6
7  8  9  10
11 12 13 14 15
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int prevLastEle = 0;
	for(int row=1; row<=line; row++){
		int current = prevLastEle+1;
		for(int col=1; col<=row; col++){
			if(col==row)
				prevLastEle = current;
			printf("%4d",current++);
		}
		printf("\n");
	}
	return 0;
}