/*
55555
4444
333
22
1
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=line; row>=1; row--){
		for(int col=1; col<=row; col++){
			printf("%d",row);
		}
		printf("\n");
	}
	return 0;
}