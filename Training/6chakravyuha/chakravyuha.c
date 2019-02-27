#include <stdio.h>
#include <stdlib.h>
#define ROW_IN 0
#define COL_IN 1

void print(int N, int array[][N])
{
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++)
            printf("%d\t", array[i][j]);
        printf("\n");
    }
}

void solveChakravyuha(int N, int array[][N], int result[N*N/11+1][2], int *powerPoints)
{
    int result_index=1; // maintains index of results
    int runner=0;   // for numbering the block
    int iteration=(N+1)/2;  // no. of square iterations
    int start=0, end=N-1;   // boundary of squares
    int i,j;    // loop variables
    for(i=0; i<iteration; i++){ // going through squares
        // moving right
        for(j=start; j<=end; j++){
            array[i][j] = ++runner;
            if(runner%11==0){
                (*powerPoints)++;
                result[result_index][ROW_IN] = i;
                result[result_index][COL_IN] = j;
                result_index++;
            }
        }
        // moving bottom
        for(j=start+1; j<=end; j++){
            array[j][end] = ++runner;
            if(runner%11==0){
                (*powerPoints)++;
                result[result_index][ROW_IN] = j;
                result[result_index][COL_IN] = end;
                result_index++;
            }
        }
        // moving left
        for(j=end-1; j>=start; j--){
            array[end][j] = ++runner;
            if(runner%11==0){
                (*powerPoints)++;
                result[result_index][ROW_IN] = end;
                result[result_index][COL_IN] = j;
                result_index++;
            }
        }
        // moving up
        for(j=end-1; j>=start+1; j--){
           array[j][start] = ++runner;
           if(runner%11==0){
                (*powerPoints)++;
                result[result_index][ROW_IN] = j;
                result[result_index][COL_IN] = start;
                result_index++;
            }
        }
        // going to next internal square
        start++;
        end--;
    }
}
int main()
{
    static int N;
    int powerPoints=1;
    printf("Enter size:");
    scanf("%d", &N);

    // Base case
    if(N==1){
        printf("1\n");
        printf("Total Power points: 1\n");
        printf("(0,0)");
        return 0;
    }

    // array for storing values
    int array[N][N];
    int expectedPoints = N*N/11+1;
    int result[expectedPoints][2];
    // initially 1 power point at 0,0
    result[0][ROW_IN] = 0;
    result[0][COL_IN] = 0;

    // solving chakravyuha
    solveChakravyuha(N, array, result, &powerPoints);
    print(N, array);
    printf("Total Power points: %d\n",powerPoints);

    // printing result locations
    int i;
    for(i=0; i<expectedPoints; i++){
        printf("(%d, %d)",result[i][ROW_IN], result[i][COL_IN]);
    }
    return 0;
}

/*
Time complexity: O(N^2)
Space complexity: O(N*N)
*/
