//Fei - exe 5.1.2
//Create a Person tuple

#include <boost/tuple/tuple.hpp>	//Tuple class
#include <boost/tuple/tuple_io.hpp>	//I/O for tuples

#include <string>
#include <iostream>
using namespace std;
using boost::tuple;

//Create a typedef for a Person tuple that contains name, age, and height
typedef boost::tuple<string, int, double> Person;

//Create a function that prints the person tuple
void Print(const Person& ppl)
{
	string name = ppl.get<0>();
	int age = ppl.get<1>();
	double height = ppl.get<2>();

	cout << "The person's name is " << name 
		<< ", age is " << age 
		<< ", and height is " << height << endl;
}


int main()
{
	//Create a few person tuple instances and print them
	Person p1 = boost::make_tuple(string("Alex"), 20, 5.5);
	Person p2 = boost::make_tuple(string("Bety"), 15, 4.5);
	Person p3 = boost::make_tuple(string("Clair"), 30, 5.6);

	Print(p1);
	Print(p2);
	Print(p3);

	cout << endl;

	//Increment the age of Alex
	p1.get<1>() += 1;		//20+1=21

	//Now Alex is 21 years old
	Print(p1);

	return 0;

}
