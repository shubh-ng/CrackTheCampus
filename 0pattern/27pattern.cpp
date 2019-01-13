/*
54321
5432
543
54
5
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=line; col>=row; col--){
			printf("%d",col);
		}
		printf("\n");
	}
	return 0;
}