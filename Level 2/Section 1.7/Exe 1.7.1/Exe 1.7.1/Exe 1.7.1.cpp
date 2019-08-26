//Fei-exe 1.7.1
//Create a function Swap() that can be called using pointers

#include<stdio.h>
#include<stdlib.h>

//create a function Swap()
void Swap(int x, int y);

//use pointers as arguments to switch input values
void Swap(int* x, int* y){
	
	int temp = (*x);		//create a temperary varaible to store the value from the address of x
	(*x) = (*y);			//let the value from the address of x be the same as the value from address y
	(*y) = temp;			//let the value from the address of y be the same as temperary variable
}


int main(){
	//initialize two integers i, j
	int i,j;					
	i=123;
	j=456;

	//print original values of i and j
	printf("Original: i=%d, j=%d\n", i, j);

	//call Swap() function with i and j as inputs
	Swap(&i, &j);	

	//new values of i and j
	printf("New: i=%d, j=%d\n", i, j);

	exit(0);

}


