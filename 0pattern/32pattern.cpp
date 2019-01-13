/*
13479
3579
579	
79
9
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int runner=1;
	for(int row=1; row<=line; row++){
		int tempRunner =  runner;
		for(int col=1; col<=(line+1)-row; col++){
			printf("%d",tempRunner);
			tempRunner += 2;
		}
		runner += 2;
		printf("\n");
	}
	return 0;
}