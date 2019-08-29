

		// A.T. 10-October-2015
		// ArrayClass_Member.cpp
		// Member functions file for Header "ArrayClass_header.h"
		// Copyright 2015 Amirhessam <amirhessam@linux-9ofa.site>

		#include "ArrayClass_Header.h"
		#include <string.h>



		
		
		Array :: Array () // Default Constructor
		{
			num = 0 ;// initilizing the number of integers in array
			cap = 1 ; // initializing the capacity
			data = new int[cap] ; // Dynamic allocating memory with capacity =1
			
		}
	
		
		Array :: Array (const Array &AA) // A copy construct
		{
			num = AA.num ;  // assigning 
			cap = AA.cap ; // assigning 
			data = new int[cap] ; // Dynamic allocating memory with new capacity AA.cap
			memcpy ( data, AA.data, num * sizeof (int) ) ; // copying using memcpy function
			
		} 
		
		int * Array :: Set_Array () // Assignment operator
		{
			return data ; 
			
		} 
		
		void Array :: push_back (int i) // Member Function: add an integer to the end of the array
		{
			num ++ ; // num = num +1
			
			// A convenient strategy is to double the capacity when it is not sufficient.
			
			if ( num <= cap)
			{
				data[ num-1 ] = i;
				
			}
			
			else
			{
				cap *= 2 ; // Cap = 2 * Cap make the capacity double
				int * LocalMem = new int[ cap ] ; // defining new pointer dynamically
				memcpy ( LocalMem, data, num * sizeof(int) ) ; // copying data to the new LocalMem
				delete [] data ; // free memory for data
				data = LocalMem ; // assinging LocalMem to data again

			}
			
			data [num -1] = i ;
			

		} 
		
		void Array :: pop_back () //  Member Function: which remove the last element
		{
			num-- ; // num = num -1 
			cap = num ; // assigning the capacity with the number of integers
			int * LocalMem = new int [ num ] ; // defining a new pointer dynamically
			memcpy ( LocalMem, data , num * sizeof (int) ) ; // copying data to the new LocalMem
			delete [] data ; // free memory for data
			data = LocalMem ; // Assigning LocalMem to data again
	
		} 
		
		void Array :: remove (int i) // Member Function: which remove the integer with index i from the array
		{
			num-- ; // num = num -1
			int j = 0 ; // Counter
			for ( j = i; j< cap-1 ; j++)
			{
				data [j] = data [j+1] ; 
				
			} 
			
			data [ cap - 1 ] = 0 ;
			
		} 
		
		void Array :: insert (int num2, int i) // Member Function: insert an integer “num” at the position “i”
		{
			num++ ; // num = num + 1
			if ( num <= cap )
			{
				int j = 0 ; // Counter
				for ( j = cap ; j > i; j--)
				{
					data[j] = data[j-1] ;
					
				}
				data[i] = num2 ; // inserting num2 at position i
		
			}
			
			// A convenient strategy is to double the capacity when it is not sufficient.
			else
			{
				cap++ ; // cap = cap +1
				int * LocalMem = new int [cap] ; //new pointer with dynamic allocation
				memcpy ( LocalMem, data, num * sizeof (int) ) ; // copying data to new pointer
				delete [] data ; // free the memory
				data = LocalMem ; // assingning new pointer to data array
				
				int j = 0 ; // Counter
				for (j = cap ; j > i ; j--)
				{
					data[j] = data[ j - 1] ;
					
				}
				data [i] = num ; // inserting integer at position i
			}
			
		} 
		
		int Array :: capacity () // Member Function: return the capacity of the vector
		{
			return cap ;
			
		} 
		
		
		int Array :: size ()  // Member Function: return the size of the vector
		{
			return num ; // number of integer stored in Array
		
		} 
		
		void Array :: clear () // Member Function: remove all the elements from the array
		{
			int j = 0 ; // Counter
			for ( j = 0; j < num ; j++)
			{
				data [j] = '\0' ; // make the elements ZERO
				
			} 
			
			num = 0 ;
			
		} 
		
		Array :: ~Array () // Destructor
		{
			delete[] data ; // free the memory block
			
		} 
		
		
		
		
		
		
		
		
		
		
		
		
		
