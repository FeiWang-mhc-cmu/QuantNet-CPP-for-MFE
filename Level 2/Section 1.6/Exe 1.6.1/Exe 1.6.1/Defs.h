//Fei-exe 1.6.1
//Define two macros in the include-file that print variables a and b

#include<stdio.h>
#include<stdlib.h>

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef DEFS_H
#define DEFS_H

//define macro call PRINT1 that prints variable a
#define PRINT1(a) printf("The variable a is %d\n", a)

//define macro call PRINT2 that prints variable a and b
#define PRINT2(a,b) printf("The varaibles a and b are %d and %d\n", a, b) 

#endif

