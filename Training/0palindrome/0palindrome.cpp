#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
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
bool isPalindrome(char str[])
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
	int maxSize=0,maxIndex=-1;
	for(int i=0; i<inputSize; i++){ //taking input
		scanf("%s",strings[i]);
		toLowercase(strings[i]);
		if(isPalindrome(strings[i])){ //checking palindrome
			printf("Indeed\n");
			int size = strlen(strings[i]);
			if(size>maxSize){
				maxSize = size;
				maxIndex = i;
			}
		}
		else
			printf("Not at all\n");
	}
	if(maxIndex==-1)
		printf("No Palindrome number found.");
	else
		printf("%s is palindrome of longest length %d.",strings[maxIndex],maxSize);
	return 0;
}
