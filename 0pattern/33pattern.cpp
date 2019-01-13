/*
1
10
101
1010
10101
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=row; col++){
			if(col%2==0)
				printf("0");
			else
				printf("1");
		}
		printf("\n");
	}
	return 0;
}