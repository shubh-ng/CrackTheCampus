/*
1
2  4
7  11  16
22 29  37  46
56 67  79  92  106
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int line=5;
	int ele=2,adder=2;
	for(int row=2; row<=line; row++){
		for(int col=1; col<=row; col++){
			printf("%4d",ele);
			ele += adder;
			adder++;
		}
		printf("\n");
	}
	return 0;
}