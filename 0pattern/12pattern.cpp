/*
55555
54444
54333
54322
54321
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int limit=6;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=line; col++)
			if(col>row)
				printf("%d",limit-row);
			else
				printf("%d",limit-col);
		printf("\n");
	}
	return 0;
}