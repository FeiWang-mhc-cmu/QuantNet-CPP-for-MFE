//Fei-exe 1.7.2
//Calculate the length of a string 

#include <stdio.h>

#define MAXLINE 30

// String length declaration
int Length(char str[]);

int main()
{
	char string[MAXLINE+1]; // Line of maximum 30 chars + \0
	int c; // The input character
	int i=0; // The counter

	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

	// Get the characters
	while ((c=getchar())!=EOF && c != 26 && i<MAXLINE)
	{
		// Append entered character to string
		string[i++]=(char)c;
	}
	
	// simpler way: while(str[i++]!='\0') return i-1;

	string[i]='\0'; // String must be closed with \0

	printf("String length is %d\n", Length(string));

	return 0;
}

/* Implement the Length() function here */
int Length(char str[]){
	
	//create a pointer p
	char* p;

	//let p get the address of the first element of array str
	p = str;

	//create a integer varaible to calculate the length of the array
	int length=0;
	 
	//so long the value from address p stored is not a termination input
	//count one more to the length and move to the next int size of the address p stored
	while(*p != '\0' && *p != EOF && *p != 26){
		length++;
		p++;
	}

	//return the result of length
	return length;
}
