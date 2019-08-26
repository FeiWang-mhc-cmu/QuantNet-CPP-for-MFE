//Fei-exe 5.1.3
//ArrayException classes header file
//Boost libraries-Variant

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef ARRAYEXCEPTION_HPP
#define ARRAYEXCEPTION_HPP

#include<iostream>
using namespace std;
#include<string>
#include<sstream>

namespace fayewang
{
	namespace Containers
	{
		class ArrayException
		{
		public:
			//create an abstract GetMessage() function that returns a string
			virtual std::string GetMessage()=0; 
		};

		class OutOfBoundsException: public ArrayException
		{
		private:
			int m_index;		//index number

		public:
			//constructor that indicates the erroneous array index
			//and store it in a data member
			OutOfBoundsException(int n);

			//override GetMessage() function
			std::string GetMessage();

		};

		class NotSameSize: public ArrayException
		{
		public:
			//override GetMessage() function
			std::string GetMessage();
		};

		class StackOverflow: public ArrayException
		{
		public:
			//override GetMessage() function
			std::string GetMessage();
		};

		class StackUnderflow: public ArrayException
		{
		public:
			//override GetMessage() function
			std::string GetMessage();
		};
	}
}



#endif
