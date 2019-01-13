/*
5
54
543
5432
54321
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=line; col>=(line+1)-row; col--){
			printf("%d",col);
		}
		printf("\n");
	}
	return 0;
}