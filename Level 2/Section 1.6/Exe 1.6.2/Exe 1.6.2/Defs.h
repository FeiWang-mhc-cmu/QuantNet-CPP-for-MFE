//Fei-exe 1.6.2
//Define two new macros in the include-file that print max value

#include<stdio.h>
#include<stdlib.h>

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef DEFS_H
#define DEFS_H

//define macro call PRINT1 that prints variable a
#define PRINT1(a) printf("The variable a is %d\n", a)

//define macro call PRINT2 that prints variable a and b
#define PRINT2(a,b) printf("The varaibles a and b are %d and %d\n", a, b) 

//define macro call MAX2 that return the max value between x and y
#define MAX2(x,y) (x)>=(y)? (x):(y)

//define macro call MAX2 that return the max value among x,y,z
#define MAX3(x,y,z) (MAX2(x,y))>=(z)? (MAX2(x,y)):(z)

#endif

