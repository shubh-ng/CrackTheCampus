/*
11111
22222
33333
44444
55555
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			printf("%d",row);
		printf("\n");
	}
	return 0;
}