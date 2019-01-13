/*
54321
4321
321
21
1
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=5; row>=1; row--){
		for(int col=row; col>=1; col--){
			printf("%d",col);
		}
		printf("\n");
	}
	return 0;
}