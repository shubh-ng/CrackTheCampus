/*
5
45
345
2345
12345
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=5; row>=1; row--){
		for(int col=row; col<=line; col++){
			printf("%d",col);
		}
		printf("\n");
	}
	return 0;
}