/*
1        1
12      21
123	   321
1234  4321
1234554321
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int line=5;
	int runner=1;
	int spacePrinter=line+3;
	for(int row=1; row<=line; row++){
		for(int col=1; col<=row; col++){
			printf("%d",col);
		}
		for(int col=1; col<=spacePrinter; col++){
			printf(" ");
		}
		for(int col=row; col>=1; col--){
			printf("%d",col);
		}
		spacePrinter -= 2;
		printf("\n");
	}
	return 0;
}