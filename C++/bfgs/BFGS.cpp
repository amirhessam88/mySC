//*******************************************************************//
// A.T. 24-October-2016
// BFGS.cpp
// A program to Make Line Search through 2d Rosenbrock function
// Copyright 2016 Amirhessam Tahmassebi <amirhessam@linux-9ofa.site>
//*******************************************************************//
//************************ Header Files *****************************//

#include <iostream>
#include <math.h>
#include <fstream>
#include <armadillo>

using namespace std ;
using namespace arma;

//*******************************************************************//
//************************ Compiling Notes **************************//
// You need to have Armadillo installed on your computer. It uses some
// packages like Lapack, Blas, gFortran, g++,... . You need to have all
// of them. There is a Bash script in the folder. You need run it like:
//                      bash Compiling_Script
//*******************************************************************//
//*******************************************************************//
//************************ Calling Functions ************************//

int main () ;
mat Function(mat X) ;
mat Jacobian(mat X) ;
mat Hessian(mat X) ;
mat B_New(mat B, mat S, mat Y) ;
double StepSize(vec x, vec Gradient, vec P) ;


//*******************************************************************//
//************************ Main Function ****************************//

int main ()
{
	int MaxIter = 1000 ;	    // Maximum number of Iterations
	double Alpha = 1.0 ;		// Constant Alpha
	int Counter = 0 ;			// Counter of the iterations
	double Tolerance = 0.000001 ; // Tolerance
	mat X_New , Gradient , Hess , P , S  , Y ; // Initializing Matrices
	
	// Initializing Matrix X = [-3 , -4]
	mat X ; 
	X << -3.0 << endr
	  << -4.0 << endr ;
	// Initializing Matrix B to identitiy
	mat B ;
	B << 1.0 << 0.0 << endr
	  << 0.0 << 1.0 << endr ;
	
	  
	Gradient = Jacobian(X) ; // Making Gradinet Vector of X
	Hess = Hessian(X) ;		 // Making Hessian Matrix of X
	
	// Stream for writing to a file to use in Python for Plotting
	ofstream myFile;
	// Writing the sampled data to a file 
	myFile.open("Data3.data");
	// Printing out the points 


	// Main Calculations with Stopping Criteria
	while(Counter < MaxIter && norm(Gradient)/(1+Function(X)(0)) >= Tolerance )
	{
		
		// Priniting X to a File for tracking on plot
		myFile << X.t() << endl ;
		
		Counter = Counter + 1 ;		// Increasing the Counter
		Gradient = Jacobian(X) ;	// Making Gradinet Vector of X
		Hess = Hessian(X) ;			// Making Hessian Matrix of X
		P = solve (B , -Gradient) ; // Solve B P = -G
		Alpha = StepSize ( X , Gradient , P ) ; // Finding Alpha
		X_New = X + Alpha * P ;					// Making X_New
		S = Alpha * P ;							// Making S
		Y = Jacobian(X_New) - Jacobian(X) ;		// Making Y	
		B = B_New(B , S , Y) ;					// Updating Matrix B
		X = X_New ;								// Updating X
		
		
	}
	

	//// Printing out the Results 
	cout << "*****************************************"<<endl ;
	cout << "*********** BGFS Method Results *********"<<endl ;
	cout << "*****************************************"<<endl ;
	cout << "Number of Iterations = " <<Counter<< endl ;
	cout << "*****************************************"<<endl ;
	cout << "The Solution X = " <<endl ;
	cout << X << endl;
	cout << "*****************************************"<<endl ;
	cout << "The Value of F(X) = " << Function(X)(0) << endl ;
	cout << "*****************************************\n"<<endl ;
	

	myFile.close() ; 
	return 0 ;
	
	
} 


//*******************************************************************//
//*********************** Defining Functions ************************//

// Defining Rosenbrock Function

mat Function(mat x) 
{
    mat Temp ;
    Temp << 100*(x(1) - x(0)*x(0))* (x(1) - x(0)*x(0)) + (1 - x(0)) * (1 - x(0))<<endr;
    return Temp;
}

// DefiningJacobian of Rosenbrock Function

mat Jacobian(mat x)
{
    mat Temp;
    Temp << -400 * (x(1) - (x(0))*(x(0)))*x(0) - 2*(1 - x(0)) << endr
        << 200*(x(1) - (x(0))*(x(0)))<< endr;
    return Temp;
}

// Defining Hessian of Rosenbrock Function
mat Hessian(mat x)
{
    mat Temp ;
    Temp << -400 * (x(1) - 3*x(0)*x(0)) + 2 << -400*x(0) << endr
         << -400*x(0) << 200 << endr;
    return Temp;
}


// Defining the Alpha which is he step size
double StepSize(vec x, vec Gradient, vec P)
{
	double Alpha = 1.0 ;
	double Rho = 0.5 ;
	double Coeff = 0.5 ;
	mat Temp1 = Function (x + Alpha * P );
	mat Temp2 = Function (x) +  Coeff * Alpha * Gradient.t() * P ;
	
	while ( Temp1(0) >= Temp2 (0) )
	{
		Alpha = Rho * Alpha ;
		Temp1 = Function (x + Alpha * P );
		Temp2 = Function (x) +  Coeff * Alpha * Gradient.t() * P ;
	}
	
	return Alpha ; 
}

// Defining a function to find a update for B instead of Ones with BGFS
mat B_New(mat B, mat S, mat Y)
{
	mat Temp1, Temp2, Temp3, Prod1, Prod2;
    Prod1 = Y.t() * S ;
    Temp1 = ( Y * Y.t() ) / Prod1(0);

    Prod2 = S.t() * B * S ;
    Temp2 = ( B * S * S.t() * B ) / Prod2(0);

    Temp3 = B + Temp1 - Temp2;
    
    return Temp3;
}







