/*
5
44
333
2222
11111
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=5; row>=1; row--){
		for(int col=1; col<=(line+1)-row; col++){
			printf("%d",row);
		}
		printf("\n");
	}
	return 0;
}