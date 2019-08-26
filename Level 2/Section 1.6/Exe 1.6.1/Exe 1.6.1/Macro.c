//Fei-exe 1.6.1
//Define two macros in the include-file that print variables a and b

#include<stdio.h>
#include<stdlib.h>
#include "Defs.h"		//call my header file Defs.h


void main(){
	int a=50;			//give values to varaibles a and b
	int b=30;

	PRINT1(a);			//run two macros
	PRINT2(a,b);
}