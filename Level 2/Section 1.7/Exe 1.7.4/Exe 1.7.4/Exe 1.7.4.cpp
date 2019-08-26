//Fei-exe 1.7.4
//Create a function DayName() which prints the day of a given day

#include<stdio.h>

int DayName(int x){
	//create a two dimentional array of strings of days in a week
	//7 is the number of string and 10 is the max string size
	char str[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
						"Saturday", "Sunday"};

	//print the day number
	//print the corresponding day in string (with index number is one less than its day number)
	printf("Day %d is a %s.\n", x, str[x-1]);

	return 0;

}

//call the function created
int DayName(int x);


void main(){
	int i = 5;		//if we call the 5th day of the week (adjustable)
					//assuming the user correctly enters 1-7
	
	DayName(i);		//print the corresponding result
}
