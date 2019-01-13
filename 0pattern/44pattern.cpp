/*
1
21
123
4321
12345
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int current;
	for(int row=1; row<=line; row++){
		current = (row%2==0)?row:1;
		for(int col=1; col<=row; col++)
			if(row%2==0)
				printf("%d",current--);
			else
				printf("%d",current++);
		printf("\n");
	}
	return 0;
}