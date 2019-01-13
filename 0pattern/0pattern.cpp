/*
11111
11111
11111
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
			printf("1");
		printf("\n");
	}
	return 0;
}