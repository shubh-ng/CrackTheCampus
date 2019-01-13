/*
12345
1234
123
12
1
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=line; row>=1; row--){
		for(int col=1; col<=row; col++){
			printf("%d",col);
		}
		printf("\n");
	}
	return 0;
}