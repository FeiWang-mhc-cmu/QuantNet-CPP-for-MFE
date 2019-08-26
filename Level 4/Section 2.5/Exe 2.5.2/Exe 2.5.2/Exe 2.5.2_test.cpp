//Fei - 2.5.2
//Test file for creating array of pointers


#include "Point.hpp"
#include <iostream>
using namespace std;

void main()
{
	//allocate an array of 3 Point pointers on the heap
	Point ** array = new Point*[3];
	
	//create three pointers to points
	Point* p1 = new Point(0,1);
	Point* p2 = new Point(2,3);
	Point* p3 = new Point(4,5);
	
	//create for each element in the array a point on the heap
	array[0] = p1;
	array[1] = p2;
	array[2] = p3;

	//iterate the array and print each point in the array
	for (int i=0; i<3; i++){
		cout << *array[i] << endl;
	}

	//iterate the array again and delte each point in the array
	for (int i=0; i<3; i++){
		delete array[i];
	}
	
	//delete the array itself
	delete [] array;

}
