#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#define true 1
#define false 0
using namespace std;

//converting string to lowercase
void toLowercase(char str[])
{
	int runner=0;
	int size = strlen(str);
	while(size--){
		if(str[runner]>=65 && str[runner]<=91)
			str[runner] = str[runner]+32;
		runner++;
	}
}

//function for checking palindrome
int isPalindrome(char str[])
{
	int first = 0;
	int last = strlen(str)-1;
	while(first<last){	
		if(str[first++]!=str[last--])
			return false;
	}
	return true;
}

int main()
{
	//making 2D array of character for storing no of strings
	char strings[20][100];
	int inputSize;	//size of input
	printf("Enter how many strings you want to check? ");
	scanf("%d",&inputSize);
	printf("Enter strings:\n");
	for(int i=0; i<inputSize; i++){ //taking input
		scanf("%s",strings[i]);
		toLowercase(strings[i]);
	}
	for(int i=0; i<inputSize; i++){ //processing each string
		if(isPalindrome(strings[i])) //checking palindrome
			printf("Indeed\n");
		else
			printf("Not at all\n");
	}
	return 0;
}
