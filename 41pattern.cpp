/*
1
121
12321
1234321
123454321	
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int oddNo=1;
	for(int row=1; row<=line; row++){
		int runner = 1;
		for(int col=1; col<=oddNo; col++)
			if(col<=row){
				printf("%d",runner);
				if(col!=row)
					runner++;
			}else{
				printf("%d",--runner);
			}
		oddNo += 2;
		printf("\n");
	}
	return 0;
}