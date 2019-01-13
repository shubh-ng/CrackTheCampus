/*
1
23
4567
89123456
7891234567891234
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int line=5;
	int runner=1;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=pow(2,row-1); col++){
			if(runner>9)
				runner=1;
			printf("%d",runner++);
		}
		printf("\n");
	}
	return 0;
}