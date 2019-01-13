/*
12345
21234
32123
43212
54321
*/
#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
	int line=5;
	int start=1;
	for(int row=1; row<=line; row++){
		int tempStart=start;
		int forwardRunner=2;
		for(int col=1; col<=line; col++)
			if(tempStart<1)
				printf("%d",forwardRunner++);
			else
				printf("%d",tempStart--);
		start++;
		printf("\n");
	}
	return 0;
}