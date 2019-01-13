/*
12345
2345
345
45
5
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=row; col<=line; col++){
			printf("%d",col);
		}
		printf("\n");
	}
	return 0;
}