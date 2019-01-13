/*
1
123
12345
1234567
123456789
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int oddNo=1;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=oddNo; col++)
			printf("%d",col);
		oddNo += 2;
		printf("\n");
	}
	return 0;
}