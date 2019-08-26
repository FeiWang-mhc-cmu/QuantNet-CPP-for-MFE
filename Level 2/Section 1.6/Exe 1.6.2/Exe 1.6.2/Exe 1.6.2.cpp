//Fei-exe 1.6.2
//test my result of newly created macros

#include<stdio.h>
#include "Defs.h"			//call my created macro file

void main(){
	int x,y,z;				//intialize three integer inputs x,y,z
	x=10;
	y=3;
	z=49;

	printf("%d\n", MAX2(x,y));		//print results for two new macros
	printf("%d\n", MAX3(x,y,z));
}