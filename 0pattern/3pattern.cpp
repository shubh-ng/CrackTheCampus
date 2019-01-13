/*
11111
10001
10001
10001
11111
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			if(row==1 || col==1 || row==line || col==line)
				printf("1");
			else
				printf("0");
		printf("\n");
	}
	return 0;
}