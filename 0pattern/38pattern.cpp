/*
1
24
135
2468
13579
*/
#include <iostream>
using namespace std;

int main()
{
	int line=5;
	int oddNo,evenNo;
	for(int row=1; row<=line; row++){
		oddNo = 1, evenNo=2;
		for(int col=1; col<=row; col++)
			if(row%2==0){
				printf("%d",evenNo);
				evenNo += 2;
			}else{
				printf("%d",oddNo);
				oddNo += 2;
			}
		printf("\n");
	}
	return 0;
}