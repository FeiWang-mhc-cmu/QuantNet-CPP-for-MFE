//Fei-exe 1.9.2
//Similar to 1.9.1 but write the output into a file

#include<stdio.h>
#include<stdlib.h>

void main(){
	char str[1000];			//file name with max 100 chars+\0 
	char input;				//input character

	//input file name
	printf("Name your file, end with '.txt' and then hit 'Enter'.\n");
	gets_s(str);			//read the string
	printf("%s\n",str);		//print the string on the screen

	FILE* fp;				//fp is a pointer of file
	fp = fopen(str, "w");	//open and write a file with file name just created

	//print instruction
	printf("Type your input and end with ^A.\n");

	//when file address is not NULL
	if (fp != NULL){
	
		//if input is not ^A
		while ((input = getchar()) != 1 && input != EOF){
		
			//when input is NOT 'enter', read the entered character into the file
			//if it is 'enter', also starts a new line
			if (input != 10){
				fputc(input, fp);
			}
			else {
				fputc(10, fp);
			}
		}
	
	//print warning sign if the file addresss is null
	if(fp == NULL){
		printf("Help!\n");
		exit(1);
		}

	//close file
	fclose(fp);
	}

	//when ^A is entered, the program stops and prints the following on the screen but not in the file
	if (input == 1){
		printf("\nCTRL + A is a correct ending.\n");
		}
}
