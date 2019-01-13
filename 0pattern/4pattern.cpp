/*
11111
11111
11011
11111
11111
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			if(row==(line/2+1) && col==(line/2+1))
				printf("0");
			else
				printf("1");
		printf("\n");
	}
	return 0;
}