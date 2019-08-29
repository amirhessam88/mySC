		// A.T. 10-October-2015
		// ArrayClass_Main.cpp
		// A program to Test out Class
		// Copyright 2015 Amirhessam <amirhessam@linux-9ofa.site>



		#include <iostream>
		#include <string.h>
		#include <fstream>
		#include "ArrayClass_Header.h"
		#include "ArrayClass_Member.cpp"

		using namespace std;
		
		int main ()
		
		{
			
			// In this main program, I have made the READ-Me file 
			// Which contains the output too.
			// Read-Me.txt is the aforementioend file
			
			ofstream myfile;
			// Opening the file 
			myfile.open("Read-Me.txt");
			
		    myfile<<"\n**********************************************************************\n";
			myfile<< "A.T. 10-October-2015"<<endl ;
			myfile<<"Read-Me.txt"<<endl ;
		    myfile<<"Copyright 2015 Amirhessam Tahmassebi <amirhessam@linux-9ofa.site>"<<endl ;
			myfile<<"\n**********************************************************************\n";
			myfile << "This folder contains 3 different files:\n"
			<<"*Array.h* which is the header file for class\n"
			<<"*Array.cpp* which is member functions for class Array\n"
			<<"*Main.cpp* which is the main program to test out this class.\n"
			<<"Here is the way we test out the class Array.\n" 
			<<"\n**********************************************************************\n";
			
			
			int i ; //Counter
			
			// Testing out Push_back with adding 5 integers one by one
			
			Array A1; // Defining class A1
			
			A1.push_back(1) ;
			A1.push_back(2) ;
			A1.push_back(3) ;
			A1.push_back(4) ;
			A1.push_back(5) ;
			myfile <<"\nUsing Push_Back we add an integer to the end of array."<<endl ;
			cout << "\nBy adding 5 integers one by one: "<< endl ;
			myfile << "\nBy adding 5 integers one by one: "<< endl ;
			int * AA = A1.Set_Array () ; // Defining pointer AA for new array
			
			for ( i = 0; i < A1.size() ; i++)
			{
				cout << AA[i] << endl ; // Printing out the Pointer AA
				myfile <<AA[i] << endl ; // Printing to file
			}
			myfile<<"\n**********************************************************************\n";
			// Testing out Pop_back with removing the last element
			cout << "\nAfter removing the last element of the array we have:" << endl ;
			myfile << "\nAfter removing the last element of the array using Pop_Back we have:" << endl ;
			A1.pop_back () ;
			
			int * AApop = A1.Set_Array () ; // defining new pointer for pop array
			
			for ( i = 0 ; i < A1.size() ; i++)
			{
				cout << AApop[i] << endl ; // Prining out the array after calling pop_back
				myfile << AApop[i] << endl ; // Printing to file
			}
			
			myfile<<"\n**********************************************************************\n";
			// Testing out Remove
			
			cout << "\nRemoving element at position i = 1" << endl ;
			myfile << "\nRemoving element at position i = 1 using Remove." << endl ;
			A1.remove(1) ; 
			
			int * AAremove = A1.Set_Array () ; // pointer for removing from Array
			
			for ( i = 0; i < A1.size () ; i++)
			{
				cout << AAremove[i] << endl ; // Printing the array after removing at i =3
				myfile << AAremove[i] << endl ; // Printing to file
				
			}
			myfile<<"\n**********************************************************************\n";
			
			// Testing out Insert
			
			cout << "\nAfter inserting 24 to position i = 1 " << endl ;
			myfile << "\nAfter inserting 24 to position i = 1 Using Insert." << endl ;
			A1.insert(24,1) ;
			
			int * AAinsert = A1.Set_Array () ;
			
			for ( i = 0; i < A1.size() ; i++)
			{
				cout << AAinsert [i] <<endl; // Printing the array insert
				myfile << AAinsert [i] <<endl; // Printing to file
			}
			myfile<<"\n**********************************************************************\n";
			
			// Testing out the Capacity
			A1.push_back(72) ;
			cout << "\nWe added one more integer, So the capacity should be doubled"<< endl ;		
			cout << "Capacity = " <<A1.capacity() << endl ;
			//Printing to file
			myfile << "\nWe added one more integer, So the capacity should be DOUBLED.\n"<< endl ;
			myfile << "Capacity = " <<A1.capacity() << endl ;
			
	
			// Testing out the Size 

			cout << "Size = " << A1.size() << endl;
			myfile << "Size = " << A1.size() << endl;
			myfile<<"\n**********************************************************************\n";
			

			// Testing out Clear
			
			A1.clear();
			cout << "\nArray has been cleared\n" << endl ;
			cout << "Capacity = "<< A1.capacity() << endl ;
			cout << "Size = " << A1.size() << endl;
			
			myfile << "\nArray has been CLEARED." << endl ;
			myfile << "Capacity = "<< A1.capacity() << endl ;
			myfile << "Size = " << A1.size() << endl;
			
			myfile<<"\n**********************************************************************\n";
			
			
			
			
			
			
			
			myfile.close();
			
			return (0) ;
		}
		
		
