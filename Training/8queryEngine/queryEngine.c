#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLLEGE_ATTR_SIZE 4
#define USER_ATTR_SIZE 5

#define FIELD_CAPACITY 100

#define MAX_ROWS 100

#define MAX_DATA_TO_BE_PRINTED 5

typedef struct COLLEGE_MASTER{
    char collegeId[FIELD_CAPACITY];
    char collegeName[FIELD_CAPACITY];
    char cityId[FIELD_CAPACITY];
    char stateId[FIELD_CAPACITY];
}COLLEGE;

typedef struct USER_MASTER{
    int userId;
    char userName[FIELD_CAPACITY];
    char email[FIELD_CAPACITY];
    char CTReference[FIELD_CAPACITY];
    char collegeId[FIELD_CAPACITY];
}USER;

int userDataSize = 0;
int collegeDataSize = 0;

void swap(USER *first, USER *second)
{
    USER temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void _sort(USER fetchedArray[], int size){
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (fetchedArray[j].userId < fetchedArray[min_idx].userId)
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&fetchedArray[min_idx], &fetchedArray[i]);
    }
}

void printUser(USER user[], int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d,%s,%s,%s\n",user[i].userId, user[i].userName, user[i].email, user[i].CTReference);
    }
}

void printCollege(COLLEGE college[], int size){
    int i;
    for(i=0; i<size; i++){
        printf("%s,%s,%s\n",college[i].collegeName, college[i].cityId, college[i].stateId);
    }
}


void retriveFromUserUsingCollege(USER userMaster[], COLLEGE collegeMaster[]){
    char attributeName[100];
    char attributeValue[100];
    fflush(stdin);
    gets(attributeName);
    gets(attributeValue);

    USER fetchedArray[MAX_DATA_TO_BE_PRINTED];
    int fetchedArrayIndex = 0;

    int i=0;
    char collegeId[FIELD_CAPACITY];
    if(!strcmp(attributeName, "CollegeName")){
        // take collegeId
        for(i=0; i<collegeDataSize; i++){
            if(!strcmp(collegeMaster[i].collegeName, attributeValue)){
                strcpy(collegeId, collegeMaster[i].collegeId);
                break;
            }
        }
        if(strcmp(collegeId,"")){
            // search using collegeId
            for(i=0; i<userDataSize && fetchedArrayIndex < MAX_DATA_TO_BE_PRINTED; i++){
                if(!strcmp(userMaster[i].collegeId, collegeId)){
                    fetchedArray[fetchedArrayIndex++] = userMaster[i];
                }
            }
        }
    }else if(!strcmp(attributeName, "CollegeId")){
        // take collegeId
        for(i=0; i<collegeDataSize; i++){
            if(!strcmp(collegeMaster[i].collegeId, attributeValue)){
                strcpy(collegeId, collegeMaster[i].collegeId);
                break;
            }
        }
        if(strcmp(collegeId,"")){
            // search using collegeId
            for(i=0; i<userDataSize && fetchedArrayIndex < MAX_DATA_TO_BE_PRINTED; i++){
                if(!strcmp(userMaster[i].collegeId, collegeId)){
                    fetchedArray[fetchedArrayIndex++] = userMaster[i];
                }
            }
        }
    }else if(!strcmp(attributeName, "CityId")){
        // take collegeId
        for(i=0; i<collegeDataSize; i++){
            if(!strcmp(collegeMaster[i].cityId, attributeValue)){
                strcpy(collegeId, collegeMaster[i].collegeId);
                break;
            }
        }
        if(strcmp(collegeId,"")){
            // search using collegeId
            for(i=0; i<userDataSize && fetchedArrayIndex < MAX_DATA_TO_BE_PRINTED; i++){
                if(!strcmp(userMaster[i].collegeId, collegeId)){
                    fetchedArray[fetchedArrayIndex++] = userMaster[i];
                }
            }
        }
    }else if(!strcmp(attributeName, "StateId")){
        // take collegeId
        for(i=0; i<collegeDataSize; i++){
            if(!strcmp(collegeMaster[i].stateId, attributeValue)){
                strcpy(collegeId, collegeMaster[i].collegeId);
                break;
            }
        }
        if(strcmp(collegeId,"")){
            // search using collegeId
            for(i=0; i<userDataSize && fetchedArrayIndex < MAX_DATA_TO_BE_PRINTED; i++){
                if(!strcmp(userMaster[i].collegeId, collegeId)){
                    fetchedArray[fetchedArrayIndex++] = userMaster[i];
                }
            }
        }
    }else{
        printf("Invalid Attribute");
    }
    if(fetchedArrayIndex == 0){
        printf("Data unavailable");
        return;
    }
    _sort(fetchedArray, fetchedArrayIndex);
    printUser(fetchedArray, fetchedArrayIndex);
}


void retriveFromCollegeUsingUser(USER userMaster[], COLLEGE collegeMaster[]){
    char attributeName[100];
    char attributeValue[100];
    fflush(stdin);
    gets(attributeName);
    gets(attributeValue);

    COLLEGE fetchedArray[MAX_DATA_TO_BE_PRINTED];
    int fetchedArrayIndex = 0;

    int i=0;
    char collegeId[FIELD_CAPACITY];
    if(!strcmp(attributeName, "UserId")){
        // take collegeId
        for(i=0; i<collegeDataSize; i++){
            if(userMaster[i].userId == atoi(attributeValue)){
                strcpy(collegeId, userMaster[i].collegeId);
                break;
            }
        }
        if(strcmp(collegeId,"")){
            // search using collegeId
            for(i=0; i<userDataSize && fetchedArrayIndex < MAX_DATA_TO_BE_PRINTED; i++){
                if(!strcmp(collegeMaster[i].collegeId, collegeId)){
                    fetchedArray[fetchedArrayIndex++] = collegeMaster[i];
                }
            }
        }
    }else if(!strcmp(attributeName, "UserName")){
        // take collegeId
        for(i=0; i<collegeDataSize; i++){
            if(!strcmp(userMaster[i].userName, attributeValue)){
                strcpy(collegeId, userMaster[i].collegeId);
                break;
            }
        }
        if(strcmp(collegeId,"")){
            // search using collegeId
            for(i=0; i<userDataSize && fetchedArrayIndex < MAX_DATA_TO_BE_PRINTED; i++){
                if(!strcmp(collegeMaster[i].collegeId, collegeId)){
                    fetchedArray[fetchedArrayIndex++] = collegeMaster[i];
                }
            }
        }
    }else if(!strcmp(attributeName, "Email")){
        // take collegeId
        for(i=0; i<collegeDataSize; i++){
            if(!strcmp(userMaster[i].email, attributeValue)){
                strcpy(collegeId, userMaster[i].collegeId);
                break;
            }
        }
        if(strcmp(collegeId,"")){
            // search using collegeId
            for(i=0; i<userDataSize && fetchedArrayIndex < MAX_DATA_TO_BE_PRINTED; i++){
                if(!strcmp(collegeMaster[i].collegeId, collegeId)){
                    fetchedArray[fetchedArrayIndex++] = collegeMaster[i];
                }
            }
        }
    }else if(!strcmp(attributeName,"CTReference")){
        // take collegeId
        for(i=0; i<collegeDataSize; i++){
            if(!strcmp(userMaster[i].CTReference, attributeValue)){
                strcpy(collegeId, userMaster[i].collegeId);
                break;
            }
        }
        if(strcmp(collegeId,"")){
            // search using collegeId
            for(i=0; i<userDataSize && fetchedArrayIndex < MAX_DATA_TO_BE_PRINTED; i++){
                if(!strcmp(collegeMaster[i].collegeId, collegeId)){
                    fetchedArray[fetchedArrayIndex++] = collegeMaster[i];
                }
            }
        }
    }else if(!strcmp(attributeName, "CollegeId")){
        // take collegeId
        for(i=0; i<collegeDataSize; i++){
            if(!strcmp(userMaster[i].collegeId, attributeValue)){
                strcpy(collegeId, userMaster[i].collegeId);
                break;
            }
        }
        if(strcmp(collegeId,"")){
            // search using collegeId
            for(i=0; i<userDataSize && fetchedArrayIndex < MAX_DATA_TO_BE_PRINTED; i++){
                if(!strcmp(collegeMaster[i].collegeId, collegeId)){
                    fetchedArray[fetchedArrayIndex++] = collegeMaster[i];
                }
            }
        }
    }else{
        printf("Invalid Attribute");
    }
    if(fetchedArrayIndex == 0){
        printf("Data unavailable");
        return;
    }
    printCollege(fetchedArray, fetchedArrayIndex);
}

void split(char c, char source[], char target[][FIELD_CAPACITY]){
    int i=0,row=0,j=0;
    while(source[i] != '\0'){
        if(source[i] != c){
            target[row][j++] = source[i];
        }else{
            target[row][j] = '\0';
            row++;
            j=0;
        }
        i++;
    }
    target[row][j] = '\0';
}

void readCollegeMaster(char collegeURL[], COLLEGE collegeMaster[]){
    FILE* fptr = fopen(collegeURL, "r");
    char data[FIELD_CAPACITY];
    char splitedResult[COLLEGE_ATTR_SIZE][FIELD_CAPACITY];
    int collegeMasterIndex = 0;
    if(fptr != NULL){
        while(fgets(data,FIELD_CAPACITY, fptr) != NULL){
            split(',', data, splitedResult);
            strcpy(collegeMaster[collegeMasterIndex].collegeId, splitedResult[0]);
            strcpy(collegeMaster[collegeMasterIndex].collegeName, splitedResult[1]);
            strcpy(collegeMaster[collegeMasterIndex].cityId, splitedResult[2]);
            strcpy(collegeMaster[collegeMasterIndex].stateId, splitedResult[3]);
            ++collegeMasterIndex;
        }
    }else{
        printf("File Not found");
    }
    collegeDataSize = collegeMasterIndex;
    fclose(fptr);
}

void readUserMaster(char userURL[], USER userMaster[]){
    FILE* fptr = fopen(userURL, "r");
    char data[FIELD_CAPACITY];
    char splitedResult[USER_ATTR_SIZE][FIELD_CAPACITY];
    int userMasterIndex = 0;
    int i;
    if(fptr != NULL){
        while(fgets(data,FIELD_CAPACITY, fptr) != NULL){
            for(i=0; data[i]!='\0'; i++)
                if(data[i] == '\n')
                    data[i] = '\0';
            split(',', data, splitedResult);
            userMaster[userMasterIndex].userId = atoi(splitedResult[0]);
            strcpy(userMaster[userMasterIndex].userName, splitedResult[1]);
            strcpy(userMaster[userMasterIndex].email, splitedResult[2]);
            strcpy(userMaster[userMasterIndex].CTReference, splitedResult[3]);
            strcpy(userMaster[userMasterIndex].collegeId, splitedResult[4]);
            ++userMasterIndex;
        }
    }else{
        printf("File Not found");
    }
    userDataSize = userMasterIndex;
    fclose(fptr);
}

void readFile(char collegeURL[], char userURL[], USER userMaster[MAX_ROWS], COLLEGE collegeMaster[MAX_ROWS]){

    readCollegeMaster(collegeURL, collegeMaster);
    readUserMaster(userURL, userMaster);

    // print data
/*
    int i=0;
    for(i=0; i<userDataSize; i++){
        printf("%s\n", userMaster[i].email);
    }
*/
}

int main()
{
    char collegeURL[100];
    char userURL[100];
    char table;

    USER userMaster[MAX_ROWS];
    COLLEGE collegeMaster[MAX_ROWS];

    scanf("%s", collegeURL);
    scanf("%s", userURL);
    scanf(" %c", &table);

    readFile(collegeURL, userURL, userMaster, collegeMaster);

    if(table == 'C'){
        retriveFromUserUsingCollege(userMaster, collegeMaster);
    }else if(table == 'U'){
        retriveFromCollegeUsingUser(userMaster, collegeMaster);
    }else{
        printf("Invalid Input");
    }

    return 0;
}
