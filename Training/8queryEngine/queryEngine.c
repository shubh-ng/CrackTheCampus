#include <stdio.h>
#include <stdlib.h>

typedef struct COLLEGE_MASTER{
    int collegeId;
    int collegeName[100];
    int cityId;
    int stateId;
}COLLEGE;

typedef struct USER_MASTER{
    int userId;
    char userName[100];
    char email[100];
    char CTReference[100];
    int collegeId;
}USER;

void readFile(){

}

int main()
{
    char collegeURL[100];
    char userURL[100];
    char table;
    char attributeName[100];
    char attributeValue[100];
    return 0;
}
