/*
1
21
321
4321
54321
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=row; col>=1; col--){
			printf("%d",col);
		}
		printf("\n");
	}
	return 0;
}