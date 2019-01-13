/*
1
11
101
1001
11111
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=row; col++){
			if(col==1||row==line||row==col)
				printf("1");
			else
				printf("0");				
		}
		printf("\n");
	}
	return 0;
}