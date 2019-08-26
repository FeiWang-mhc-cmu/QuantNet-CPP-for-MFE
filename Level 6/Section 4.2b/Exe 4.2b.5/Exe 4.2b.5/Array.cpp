//Fei-exe 4.2b.5
//Implement for constructors for the Array class
//layering exceptions

//use conditional compilation to make sure there is no multiple inclusion
#ifndef Array_CPP
#define Array_CPP

#include "Array.hpp"
#include "ArrayException.hpp"
#include<sstream>
#include <cmath>
#include<iostream>
using namespace std;

namespace fayewang
{
	namespace Containers
	{
		//Static data member initialization
		template <typename T>
		int Array<T>::d_size = 10;

		//Default constructor
		template <typename T>
		Array<T>::Array(): m_size(d_size), m_data(new T[d_size])
		{
			//cout << "Default constructor is called" << endl;
		}

		//Reset constructor
		template <typename T>
		Array<T>::Array(int new_size): m_size(new_size), m_data(new T[new_size])
		{
			//cout << "Reset constructor is called" << endl;
		}

		//Copy constructor
		template <typename T>
		Array<T>::Array(const Array<T>& arr)
		{
			//cout << "Copy constructor is called" << endl;

			m_size = arr.m_size;
			m_data = new T[arr.m_size];

			for (int i = 0; i< m_size; i++)
			{
				m_data[i] = arr.m_data[i];
			}
		}

		//Destructor
		template <typename T>
		Array<T>::~Array()
		{
			//cout << "Deconstructor is called" << endl;
			delete [] m_data;
		}
				
		//Assignment operator
		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source)
		{
			// Avoid doing assign to myself
			if (this == &source)
				return *this;

			m_size = source.m_size;
			delete [] m_data;						//delete the old C array

			T* new_data;
			new_data = new T[source.m_size];	//allocate new memory 
			for (int i = 0; i < m_size; i++)
			{
				new_data[i] = source.m_data[i];
			}

			m_data = new_data;

			return *this;
		}

		//Return the size of the array
		template <typename T>
		int Array<T>::Size() const
		{
			return m_size;
		}

		//Set an element 
		template <typename T>
		void Array<T>::SetElement(int index, const T& pt)
		{
			//check if out of bound
			if (index > (m_size-1) || index < 0)
				throw OutOfBoundsException(index);
	
			//if valid, return m_data of that index
			m_data[index] = pt;

		}

		//Get an element
		template <typename T>
		T& Array<T>::GetElement(int index) const
		{
			//check if out of bound
			if (index > (m_size-1) || index < 0)
				throw OutOfBoundsException(index);
			
			//if valid, return m_data of that index
			return m_data[index];
		}

		//square bracket operator
		//for non constant objects to set and get elements of array
		template <typename T>
		T& Array<T>::operator[] (int index)
		{
			//check if out of bound
			if (index > (m_size-1) || index < 0)
				throw OutOfBoundsException(index);

			//if valid, return m_data of that index
			return m_data[index];

		}

		//constant square bracket operator
		//const return type means that the return value should not be changed
		//const function means that the private members of the class inside the function should not be changed
		//i.e. this operator will be used by constant objects to only get elements of array
		template <typename T>
		const T& Array<T>::operator[] (int index) const
		{
			//check if out of bound
			if (index > (m_size-1) || index < 0)
				throw OutOfBoundsException(index);

			//if valid, return m_data of that index
			return m_data[index];
		}

		//get default size
		template <typename T>
		int Array<T>::DefaultSize()
		{
			return d_size;
		}


		//set default size
		template <typename T>
		void Array<T>::DefaultSize(int n)
		{
			d_size = n;
		}
		

	}

}

#endif



