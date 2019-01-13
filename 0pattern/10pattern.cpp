/*
12345
12345
12345
12345
12345
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			printf("%d",col);
		printf("\n");
	}
	return 0;
}