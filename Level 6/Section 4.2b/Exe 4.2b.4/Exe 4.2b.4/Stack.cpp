//Fei-Exe 4.2b.4
//Implement for constructors for the Stack class
//stack class (composition)

//use conditional compilation to make sure there is no multiple inclusion
#ifndef Stack_CPP
#define Stack_CPP

#include "Stack.hpp"
#include<sstream>
#include <cmath>
#include<iostream>
using namespace std;

namespace fayewang
{
	namespace Containers
	{
		//Default constructor
		template <typename T>
		Stack<T>::Stack(): m_arr(), m_current(0) {}

		//Reset constructor
		template <typename T>
		Stack<T>::Stack(int new_size): m_arr(new_size), m_current(0) {}

		//Copy constructor
		template <typename T>
		Stack<T>::Stack(const Stack<T>& sta):
			m_arr(sta.m_arr), m_current(sta.m_current) {}

		//Destructor
		template <typename T>
		Stack<T>::~Stack() {}
	
		//Assignment operator
		template <typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& source)
		{
			// Avoid doing assign to myself
			if (this == &source)
				return *this;

			m_arr = source.m_arr;
			m_current = source.m_current;

			return *this;
		}

		//store element at the current position in the embedded array
		//increment the current position afterwards
		template <typename T>
		void Stack<T>::Push(T input)
		{
			//m_current == 0 when the stack is empty
			//the first parameter of SetElement refers to the index of array
			//i.e. index 0 is the first element of array
			m_arr.SetElement(m_current, input);
				
			//increment the current position afterwards
			++m_current;
		}

		//decrements the current position and then returns the element at that position
		template <typename T>
		T Stack<T>::Pop()
		{
			//if m_current == 0, the following will return error message and stop proceeding
			//"index -1 is out of bound" (i.e. -1 is the input in GetElement())
			//but m_current will remain at 0
			T pop = m_arr.GetElement(m_current-1);

			//if the above proceeds, decrement current position and returns the element
			m_current--;

			return m_arr.GetElement(m_current);
		}

		//get current index
		template <typename T>
		int Stack<T>::GetCurrentIndex()
		{
			return m_current;
		}


	}

}

#endif



