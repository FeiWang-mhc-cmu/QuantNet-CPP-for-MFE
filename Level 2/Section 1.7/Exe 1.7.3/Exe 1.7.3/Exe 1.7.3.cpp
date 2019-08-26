//Fei-exe 1.7.3
// Predict what will be printed on the screen

#include <stdio.h>
#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line

// Create and initialse array
int a[]={0, 1, 2, 3, 4};

int main()
{
	int i;
	int* p;

	//print the first to the 5th element of array a
	//i.e. 01234
	for (i=0; i<=4; i++) PRD(a[i]); // 1
	NL;
	
	//let p point to the addresses of the first to the 5th element of array a
	//and get the integer value from each address
	//i.e. 01234
	for (p=&a[0]; p<=&a[4]; p++) PRD(*p); // 2
	NL;
	NL;

	//let p point to the addresses of the first element of array a
	//start from the first element of array a, add one int size to the address stored in p
	//i.e. get the values of the first to the 5th in array a
	//i.e. 01234
	for (p=&a[0], i=0; i<=4; i++) PRD(p[i]); // 3
	NL;
	
	//let p be the value of the first elemenet of array a
	//start from i=0, print the integer value of the address of i more int size of the address stored in p
	//1st output: *(p+0)=*p=a[0]=0 --> print 0, and p=p+1, i=0+1=1
	//2nd output: *(p+1+1)=*(p+2)=a[2]=2 --> print 2, and p=p+1+1=p+2, i=1+1=2
	//3rd output: *(p+2+2)=*(p+4)=a[4]=4 --> print 4, and p=p+2+1=p+3, i=2+1=3
	//since p+3+3=p+6>a+4, end the iteration
	//final output: 024
	for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); // 4
	NL;
	NL;
	
	//let p point to the address of the 5th element (a+4) of array a
	//for address stored in p greater than the address of the first element of array a,
	//print the value stored at the current address store in p,
	//and p minus one int size to the address stored in itself,
	//i.e. 5th to the 1st of element of array a
	//i.e. 43210
	for (p=a+4; p>=a; p--) PRD(*p); // 5
	NL;
	

	//let p point to the address of the 5th element (a+4) of array a, and i starts from zero
	//print the value of the address stored in p from the back, and then i+1
	//i.e. first output p[-0] is the value of the current address --> *(a+4)=4
	//second output p[-1] is one int size less to the address stored in p --> *(a+3)=3
	//stop when p[-4] --> *(a+0)=0
	//final output: 43210
	for (p=a+4, i=0; i<=4; i++) PRD(p[-i]); // 6
	NL;
	

	//let p point to the address of the 5th element (a+4) of array a
	//print the (p-a)th element of array a, i.e. a[4-0]=4 for the first output, and then p-1
	//i.e. print the 5th to the first element of array a
	//final output: 43210
	for (p=a+4; p>=a; p--) PRD(a[p-a]); // 7
	NL;
	
	return 0;
}