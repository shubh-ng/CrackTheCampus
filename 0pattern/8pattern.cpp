/*
01110
10001
10001
10001
01110
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			if((row==1 && col!=1 && col!=line)||(row==line && col!=1 && col!=line)||(col==1 && row!=1 && row!=line)||(col==line && row!=1 && row!=line))
				printf("1");
			else
				printf("0");
		printf("\n");
	}
	return 0;
}