
#include<stdio.h>
#include<stdbool.h>

#define ROWS 9
#define COLUMNS 9
#define SQUARES 9

bool isNumberAppearOnlyOnce(int arr[], int max)
{
    for(int k=0; k<max; k++)
        if(arr[k]!=1)
            return false;

    return true;
}


bool isRowConditionSatisfied(int array[ROWS][COLUMNS])
{
    int i=0;
    int j;

    while(i<ROWS) 
    {
       int temp[ROWS]={0,0,0,0,0,0,0,0,0}; 
       for(j=0; j<COLUMNS; j++) 
       {

           if(array[i][j]<1 || array[i][j]>9)
            break;

            temp[array[i][j]-1]++;
       }

       if(!isNumberAppearOnlyOnce(temp,ROWS))
       {
           printf("condition fails at row %d", ++i);
            return false;
       }
        i++;
    }
    return true;
}


bool isColumnConditionSatisfied(int array[ROWS][COLUMNS])
{
    int j=0;
    int i;

    while(j<COLUMNS) 
    {
       int temp[COLUMNS]={0,0,0,0,0,0,0,0,0}; 
       for(i=0; i<ROWS; i++)
       {
           if(array[i][j]<1 || array[i][j]>9)
            break;

            temp[array[i][j]-1]++;
       }

       if(!isNumberAppearOnlyOnce(temp,COLUMNS))
       {
           printf("condition fails at column %d", ++j);
            return false;
       }

        j++;
    }
    return true;
}

bool isSquareConditionSatisfied(int array[ROWS][COLUMNS])
{
    int s=0;
    int i;
    int j;
    int rowIndex;
    int colIndex;

    while(s<SQUARES) //s is for each square
    {
       int temp[SQUARES]={0,0,0,0,0,0,0,0,0}; //array to store the count of number from 1-9

        rowIndex=(s/3)*3;
        colIndex=(s%3)*3;

       for(i=rowIndex; i<rowIndex+3; i++) 
           for(j=colIndex; j<colIndex+3; j++) 
           {
                if(array[i][j]<1 || array[i][j]>9)
                    break;

                temp[array[i][j]-1]++;
           }

       if(!isNumberAppearOnlyOnce(temp,SQUARES))
       {
           printf("condition fails at square %d", ++s);
            return false;
       }

        s++;
    }
    return true;
}


int main()
{
int sudokuArray[ROWS][COLUMNS]={
                        {4, 1, 9, 3, 6, 8, 7, 4, 2},
                        {1, 7, 5, 2, 8, 9, 3, 5, 6},
                        {6, 3, 2, 1, 5, 4, 9, 2, 7},
                        {2, 6, 7, 4, 9, 5, 1, 9, 8},
                        {5, 8, 3, 7, 2, 1, 6, 3, 4},
                        {9, 4, 8, 6, 3, 7, 5, 8, 1},
                        {3, 2, 1, 9, 4, 6, 8, 1, 5},
                        {8, 9, 6, 5, 7, 2, 4, 7, 3},
                        {7, 5, 4, 8, 1, 3, 2, 6, 9},
                      };

//int sudokuArray[ROWS][COLUMNS]={
//                        {1, 7, 5, 2, 8, 9, 3, 4, 6},
//                        {6, 3, 2, 6, 5, 4, 9, 8, 7},
//                        {9, 4, 8, 1, 3, 7, 5, 2, 1},
//                        {3, 2, 6, 9, 4, 6, 8, 7, 5},
//                        {8, 9, 1, 5, 7, 2, 4, 1, 3},
//                        {7, 5, 4, 8, 1, 3, 2, 6, 3},
//                        {5, 8, 9, 7, 2, 1, 7, 9, 4},
//                        {4, 1, 3, 3, 6, 8, 6, 5, 2},
//                        {2, 6, 7, 4, 9, 5, 1, 3, 2},
//                      };

//int sudokuArray[ROWS][COLUMNS]={
//                        {6, 3, 2, 1, 5, 4, 9, 8, 7},
//                        {9, 4, 8, 6, 3, 7, 5, 2, 1},
//                        {1, 7, 5, 2, 8, 9, 3, 4, 6},
//                        {3, 2 ,6 ,5 ,4 ,2 ,8 ,7, 3},
//                        {8, 9, 1, 9, 7, 3, 4, 6, 5},
//                        {7, 6, 4, 8, 9, 6, 2, 1, 9},
//                        {2, 5, 7, 4, 1, 5, 1, 3, 8},
//                        {5, 8, 3, 7, 2, 1, 6, 9, 4},
//                        {4, 1, 9, 3, 6, 8, 7, 5, 2},
//                      };


//int sudokuArray[ROWS][COLUMNS]={
//                        {9, 2, 6, 5, 1, 7, 4, 8, 3},
//                        {3, 5, 1, 4, 8, 6, 2, 7, 9},
//                        {8, 7, 4, 1, 2, 3, 5, 9, 6},
//                        {5, 8, 2 ,3 ,6 ,7 ,1 ,9, 4},
//                        {1, 4, 9, 2, 5, 8, 3, 6, 7},
//                        {7, 6, 3, 9, 4, 1, 8, 2, 5},
//                        {2, 3, 8, 7, 9, 4, 6, 5, 1},
//                        {6, 1, 7, 8, 3, 5, 9, 4, 2},
//                        {4, 9, 5, 6, 7, 2, 1, 3, 8},
//                      };


//int sudokuArray[ROWS][COLUMNS]={
//                        {1, 2, 3, 4, 5, 6, 7, 8, 9},
//                        {2, 3, 4, 5, 6, 7, 8, 9, 1},
//                        {3, 4, 5, 6, 7, 8, 9, 1, 2},
//                        {4, 5, 6 ,7 ,8 ,9 ,1 ,2, 3},
//                        {5, 6, 7, 8, 9, 1, 2, 3, 4},
//                        {6, 7, 8, 9, 1, 2, 3, 4, 5},
//                        {7, 8, 9, 1, 2, 3, 4, 5, 6},
//                        {8, 9, 1, 2, 3, 4, 5, 6, 7},
//                        {9, 1, 2, 3, 4, 5, 6, 7, 8},
//                      };

//int sudokuArray[ROWS][COLUMNS]={
//                        {9, 2, 6, 5, 7, 1, 4, 8, 3},
//                        {3, 5, 1, 4, 8, 6, 2, 7, 9},
//                        {8, 7, 4, 9, 2, 3, 5, 1, 6},
//                        {5, 8, 2 ,3 ,6 ,7 ,1 ,9, 4},
//                        {1, 4, 9, 2, 5, 8, 3, 6, 7},
//                        {7, 6, 3, 1, 4, 9, 8, 2, 5},
//                        {2, 3, 8, 7, 9, 4, 6, 5, 1},
//                        {6, 1, 7, 8, 3, 5, 9, 4, 2},
//                        {4, 9, 5, 6, 1, 2, 7, 3, 8},
//                      };


    if(isColumnConditionSatisfied(sudokuArray))
        if(isRowConditionSatisfied(sudokuArray))
            if(isSquareConditionSatisfied(sudokuArray))
                printf("\nThis is a valid sudoku solution");
}
