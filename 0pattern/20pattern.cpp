/*
11111
2222
333
44
5
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=(line+1)-row; col>=1; col--){
			printf("%d",row);
		}
		printf("\n");
	}
	return 0;
}