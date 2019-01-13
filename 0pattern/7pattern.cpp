/*
10001
01010
00100
01010
10001
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			if(row==col || (row+col)==line+1)
				printf("1");
			else
				printf("0");
		printf("\n");
	}
	return 0;
}