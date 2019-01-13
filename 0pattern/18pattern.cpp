/*
1
22
333
4444
55555
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=row; col++){
			printf("%d",row);
		}
		printf("\n");
	}
	return 0;
}