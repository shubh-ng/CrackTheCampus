/*
1
23
345
4567
56789
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int runner=1;
	for(int row=1; row<=line; row++){
		int tempRunner = runner;
		for(int col=1; col<=row; col++){
			printf("%d",tempRunner++);
		}
		runner++;
		printf("\n");
	}
	return 0;
}