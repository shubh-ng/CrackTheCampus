/*
12345
23455
34555
45555
55555
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int start=1;
	for(int row=1; row<=line; row++){
		int temp = start;
		for(int col=1; col<=line; col++){
			if(temp>=line)
				printf("%d",line);
			else
				printf("%d",temp++);
		}
		start++;
		printf("\n");
	}
	return 0;
}