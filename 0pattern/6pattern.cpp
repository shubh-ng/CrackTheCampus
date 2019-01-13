/*
11011
11011
00000
11011
11011
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			if(row==3 || col==3)
				printf("0");
			else
				printf("1");
		printf("\n");
	}
	return 0;
}	