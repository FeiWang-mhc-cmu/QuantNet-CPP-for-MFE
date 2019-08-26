//Fei-exe 1.9.1
//Create a program that reads characters from keyborad and show them on screen
//only displayed when user hits 'enter'
//end with ^A

#include<stdio.h>
#include<stdlib.h>

void main(){
	//print instruction
	printf("Type your input, hit 'Enter' to display and end with ^A.\n");

	char input;				//input character

	//when input is not ^A
	while ((input = getchar()) != 1 && input != EOF){		
		//when input is NOT 'enter', display the entered character
		//if it is 'enter', also starts a new line
		if (input != 10){
			putchar(input);
		}
		else {
			putchar('\n');
		}
	}

	//when ^A is entered, the program stops and prints the following
	if (input == 1){
		printf("\nCTRL + A is a correct ending.\n");
		}

		
}
