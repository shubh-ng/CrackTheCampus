#include <stdio.h>
#include <string.h>
#define ROWS 8
#define COLS 8
void fillChessBoard(char [], char [][COLS]);
void moveBishop(char [ROWS][COLS]);
void move(char [ROWS][COLS],int, int);
void quickSort(char [], int, int); 
int partition (char [], int, int); 
void swap(char*, char*); 
char turn;

char outputFile[50];
char outputLoc[50];
int in=0;

void swap(char* a, char* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (char arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] >= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]);
            swap(&outputFile[i], &outputFile[j]);              
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    swap(&outputFile[i+1], &outputFile[high]);                  
    return (i + 1); 
} 

void quickSort(char arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

void move(char chess_board[ROWS][COLS],int itr_i, int itr_j)
{
    while(itr_i>=0 && itr_i<ROWS && itr_j>=0 && itr_j<ROWS){
        if(chess_board[itr_i][itr_j]=='s'){
            outputFile[in]=97+itr_j;
            outputLoc[in]=(turn=='w')?(8-itr_i):(itr_i+1);
            ++in;
        }else
            return;
		--itr_i;
        --itr_j;                        
    }
}

void moveBishop(char chess_board[ROWS][COLS])
{
    int i,j;
    printf("[");
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            if(chess_board[i][j]=='B'||chess_board[i][j]=='b'){
                //move up left
               	move(chess_board, i-1, j-1);
                //move up right
                move(chess_board, i-1, j+1);
                //move down left
                move(chess_board, i+1, j-1);
                //move down right
                move(chess_board, i+1, j+1);

                //sorting
                quickSort(outputLoc,0,in-1);
                for (int it = 0; it < in; ++it)
                {
                	printf("%c%d%c%d, ",97+j,(turn=='w')?(8-i):(i+1),outputFile[it], outputLoc[it]);
                }
                in=0;
            }
        }
    }
    if(outputLoc[0]>0)
    	printf("\b\b]");
    else
    	printf("]");
}

void fillChessBoard(char input[], char chess_board[ROWS][COLS])
{
    int i=0,row=0,col=0;
    while(input[i]!='\0'){
        if(input[i]=='/'){
            i++;
            row++;
            col=0;
            continue;
        }
        if(input[i]>='1' && input[i]<='8'){
            int counter = input[i]-48;
            int itr;
            for(itr=0; itr<counter; itr++,col++){
                chess_board[row][col]='s';
            }
        }else{
            chess_board[row][col]=input[i];
            col++;
        }
        i++;
    }
}

int main()
{
    char chess_board[ROWS][COLS];
    // char input[100]="3k4/8/8/2P1P3/3B4/2R1R3/8/4K3 w";
    char input[100]="3k4/8/8/8/3B4/8/8/1B2K3 w";
    
    //scanf("%s",input);
    turn = input[strlen(input)-1];
    input[strlen(input)]='\0';
    fillChessBoard(input,chess_board);
	
	//print chessboard
	int i=0,j=0;
	for(i=0; i<ROWS; i++){
	    for(j=0; j<COLS; j++)
	        printf("%c ",chess_board[i][j]);
	    printf("\n");
	}
	moveBishop(chess_board);
    return 0;
}
