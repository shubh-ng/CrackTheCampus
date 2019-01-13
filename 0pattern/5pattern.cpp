/*
10101
01010
10101
01010
10101
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			if((row+col)%2==0)
				printf("1");
			else
				printf("0");
		printf("\n");
	}
	return 0;
}