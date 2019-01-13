/*
1
2  6
3  7  10
4  8  11  13
5  9  12  14  15
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int line=5;
	int whatToAdd=line-1;
	for(int row=1; row<=line; row++){
		int printer = row;
		int tempWhatToAdd = whatToAdd;
		for(int col=1; col<=row; col++){
			printf("%4d",printer);
			printer += tempWhatToAdd;
			tempWhatToAdd--;
		}
		printf("\n");
	}
	return 0;
}