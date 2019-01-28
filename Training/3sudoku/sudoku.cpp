#include <iostream>
#include <cstdio>
#define size 9
static int matrix[size][size]={
		// row 1
		// {4 ,1 ,9 ,3 ,6 ,8 ,7 ,4 ,2},
		// {1 ,7 ,5 ,2 ,8 ,9 ,3 ,5 ,6},
		// {6 ,3 ,2 ,1 ,5 ,4 ,9 ,2 ,7},
		// {2 ,6 ,7 ,4 ,9 ,5 ,1 ,9 ,8},
		// {5 ,8 ,3 ,7 ,2 ,1 ,6 ,3 ,4},
		// {9 ,4 ,8 ,6 ,3 ,7 ,5 ,8 ,1},
		// {3 ,2 ,1 ,9 ,4 ,6 ,8 ,1 ,5},
		// {8 ,9 ,6 ,5 ,7 ,2 ,4 ,7 ,3},
		// {7 ,5 ,4 ,8 ,1 ,3 ,2 ,6 ,9}

		// col 9
		// {1 ,7 ,5 ,2 ,8 ,9 ,3 ,4 ,6},
		// {6 ,3 ,2 ,6 ,5 ,4 ,9 ,8 ,7},
		// {9 ,4 ,8 ,1 ,3 ,7 ,5 ,2 ,1}, 
		// {3 ,2 ,6 ,9 ,4 ,6 ,8 ,7 ,5}, 
		// {8 ,9 ,1 ,5 ,7 ,2 ,4 ,1 ,3}, 
		// {7 ,5 ,4 ,8 ,1 ,3 ,2 ,6 ,3}, 
		// {5 ,8 ,9 ,7 ,2 ,1 ,7 ,9 ,4}, 
		// {4 ,1 ,3 ,3 ,6 ,8 ,6 ,5 ,2}, 
		// {2 ,6 ,7 ,4 ,9 ,5 ,1 ,3 ,2} 

		// row 4
		{6 ,3 ,2 ,1 ,5 ,4 ,9 ,8 ,7},
		{9 ,4 ,8 ,6 ,3 ,7 ,5 ,2 ,1},
		{1 ,7 ,5 ,2 ,8 ,9 ,3 ,4 ,6},
		{3 ,2 ,6 ,5 ,4 ,2 ,8 ,7 ,3},
		{8 ,9 ,1 ,9 ,7 ,3 ,4 ,6 ,5}, 
 		{7 ,6 ,4 ,8 ,9 ,6 ,2 ,1 ,9},
		{2 ,5 ,7 ,4 ,1 ,5 ,1 ,3 ,8}, 
		{5 ,8 ,3 ,7 ,2 ,1 ,6 ,9 ,4}, 
		{4 ,1 ,9 ,3 ,6 ,8 ,7 ,5 ,2} 

	};
static int seenQueue[size] = {0,0,0,0,0,0,0,0,0};
static int seenQueueIndex;

bool exists(int row, int col){
	for(int qindex=0; qindex<size; qindex++)
		if(matrix[row][col]==seenQueue[qindex])
			return false;
	seenQueue[seenQueueIndex] = matrix[row][col];
	seenQueueIndex++;
	return true;
}

int checkColumn(int col){
	for(int row=0; row<size; row++){
		if(!exists(row,col))
			return row;	// sends particular index of error row
	} 	
	return 0;	// indicates that everything is good
}

int checkRow(int row){
	for(int col=0; col<size; col++){
		if(!exists(row,col))
			return col;	// sends particular index of error col
	}
	return 0;	// indicates that everything is good
}

int checkSquareMatrix(int row, int col,int matrixNumber){
	for(int rowIndex=row; rowIndex<row+3; rowIndex++){
		for(int colIndex=col; colIndex<col+3; colIndex++){
			if(!exists(rowIndex,colIndex))
				return matrixNumber; // sends error matrix number
		}
	}
	return 0;
}

void generateError(int number,char* indicator){
	printf("%s %d\n",indicator,number);
}

void resetSeenQueue(){
	for(int qindex=0; qindex<size; qindex++)
		seenQueue[qindex] = 0;
	seenQueueIndex = 0;
}
int main()
{
	bool flag = true; // checks if error generated or not
	// Checking columns
	// Any elements not seen at first
	for(int col=0; col<size; col++){
		resetSeenQueue();
		if(checkColumn(col)!=0){
			generateError(col+1,"column");
			flag = false;
			break;
		}
	}



	if(flag){
		// Checking rows
		for(int row=0; row<size; row++){
			// Any elements not seen at first
			resetSeenQueue();
			if(checkRow(row)!=0){
				generateError(row+1,"row");
				flag = false;
				break;
			}
		}
	}

	// if(flag){
		// Checking matrix
		int matrixNumber=1; // stores matrix number
		for(int row=0; row<=6; row+=3){
			// Any elements not seen at first
			for(int col=0; col<=6; col+=3){
				resetSeenQueue();
				if(checkSquareMatrix(row,col,matrixNumber)!=0){
					generateError(matrixNumber,"matrix");
					flag = false;
					break;
				}
			}
			if(!flag)	break;
			matrixNumber++;
		}
	// }

	if(flag)
		printf("Hurray! You solved the sudoku!\n");


}
 
 
 

