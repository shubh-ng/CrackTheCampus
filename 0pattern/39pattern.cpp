/*
1
131
13531
1357531
135797531
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int oddNo=1,oddRunner;
	for(int row=1; row<=line; row++){
		oddRunner = 1;
		for(int col=1; col<=oddNo; col++)
			if(col<=row){
				printf("%d",oddRunner);
				if(col!=row)
					oddRunner += 2;
			}else{
				oddRunner -= 2;
				printf("%d",oddRunner);
			}
		oddNo += 2;
		printf("\n");
	}
	return 0;
}