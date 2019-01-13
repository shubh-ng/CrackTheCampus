/*
56789
4567
345
23
1
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int runner=5;
	for(int row=5; row>=1; row--){
		int tempRunner =  runner;
		for(int col=1; col<=row; col++){
			printf("%d",tempRunner++);
		}
		runner--;
		printf("\n");
	}
	return 0;
}