/*
1  2  3  4  5
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int runner=1;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			printf("%4d",runner++);
		printf("\n");
	}
	return 0;
}