

		// A.T. 10-October-2015
		// ArrayClass_Header.h
		// Header file for class Array
		// Copyright 2015 Amirhessam <amirhessam@linux-9ofa.site>

		#ifndef ARRAY_H
		#define ARRAY_H

		
		
		// Defining Class Array
		
		class Array
		{


		public:
			
			Array () ; // A default constructor, create an empty vector
			Array (const Array &AA) ; // A copy construct.
			int * Set_Array () ; // Assignment operator
			void push_back (int i) ; // Member Function: add an integer to the end of the array
			void pop_back () ; // Member Function: which remove the last element
			void remove (int i) ;// Member Function: which remove the integer with index i from the array
			void insert (int num, int i) ; // Member Function: insert an integer “num” at the position “i”
			int capacity () ; // Member Function: return the capacity of the vector
			int size () ; // Member Function: return the size of the vector
			void clear () ; // Member Function: remove all the elements from the array
			
			~Array() ; // Destructor, free the memory
			
			
		private :
		
			int num ; // store the number of integers in this array
			int cap ; // the size of the memory block
			int *data ; // pointer to memory block store the integers
		

		
		};
		

		#endif // ARRAY_H 
