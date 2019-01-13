/*
12345
23451
34521
45321
54321
*/
#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
	int line=5;
	int start=1,reverseRunner=5;
	for(int row=1; row<=line; row++){
		int tempStart=start;
		int tempReverseRunner=reverseRunner;
		for(int col=1; col<=line; col++)
			if(tempStart>line)
				printf("%d",tempReverseRunner--);
			else{
				printf("%d",tempStart++);
				tempReverseRunner--;
			}
		start++;
		printf("\n");
	}
	return 0;
}