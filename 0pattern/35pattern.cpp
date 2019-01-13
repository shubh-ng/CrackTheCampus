/*
1
01
010
1010
10101
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int runner = 1;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=row; col++){
			printf("%d",runner);
			runner = runner==1?0:1;			
		}
		printf("\n");
	}
	return 0;
}