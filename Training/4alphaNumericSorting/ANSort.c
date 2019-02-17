/* Emensches CTC Program - Copyrights reserved */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CHARACTER_IN_WORD 25

/* Function declarations */
void sortWordArray(char[][MAX_CHARACTER_IN_WORD],int);
void sortNumberArray(int[],int);
void printSortedList(char[][MAX_CHARACTER_IN_WORD],int[],int);


int main()
{
    int studentCount;

    printf("How many students have wrongly allotted seats ?\n");
    scanf("%d", &studentCount);

    if(studentCount<1)
    {
        printf("No seats are wrongly allotted");
        return 0;
    }

    int numArray[studentCount];
    char wordsArray[studentCount][MAX_CHARACTER_IN_WORD];

    printf("Enter %d students name and their current seat numbers\n",studentCount);
    for(int i=0; i<studentCount; i++)
    {
        scanf("%s", wordsArray[i]);
        scanf("%d", &numArray[i]);
    }

    sortWordArray(wordsArray,studentCount);
    sortNumberArray(numArray,studentCount);
    printSortedList(wordsArray,numArray,studentCount);
}
/* end of main */

/* Function to sort student names in ascending order using selection sort*/
void sortWordArray(char words[][MAX_CHARACTER_IN_WORD], int count)
{
    char temp[MAX_CHARACTER_IN_WORD];

    for(int i=0;i<count-1;i++)
        for(int j=i+1;j<count;j++)
        {
            if(strcmp(strlwr(words[i]),strlwr(words[j]))>0)
            {
                strcpy(temp,words[i]);
                strcpy(words[i],words[j]);
                strcpy(words[j],temp);
            }
        }
}
/* end of sortWordArray */

/* Function to sort seat numbers in ascending order using selection sort*/
void sortNumberArray(int numbers[],int count)
{
    int temp;

    for(int i=0;i<count-1;i++)
        for(int j=i+1;j<count;j++)
        {
             if(numbers[i] > numbers[j])
             {
                temp=numbers[i];
                numbers[i]=numbers[j];
                numbers[j]=temp;

            }
        }
}
/* end of sortNumberArray */

/* Function to display the sorted list*/
void printSortedList(char words[][MAX_CHARACTER_IN_WORD],int numbers[],int count)
{
    printf("\nCorrect alloted seats are :\n");

    for(int i = 0; i < count; i++)
    {
        printf("%s\t",words[i]);
        printf("%d\n",numbers[i]);
    }
}
/* end of printSortedList */
