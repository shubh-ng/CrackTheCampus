/*
2
242
24642
2468642
2468108642
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int oddNo=1,evenRunner;
	for(int row=1; row<=line; row++){
		evenRunner = 2;
		for(int col=1; col<=oddNo; col++)
			if(col<=row){
				printf("%d",evenRunner);
				if(col!=row)
					evenRunner += 2;
			}else{
				evenRunner -= 2;
				printf("%d",evenRunner);
			}
		oddNo += 2;
		printf("\n");
	}
	return 0;
}