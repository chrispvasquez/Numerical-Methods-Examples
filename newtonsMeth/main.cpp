using namespace std;

#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <iomanip>

double calcXo(double, double);
double function(double);
double functionDerivative(double);
double newtonsMethod(int, int, double, double, double);
void printHeader();
void show(int, double, double, double, double);
// Prototypes


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


int main(){

        int maxIterations = 5;						//Set max iterations
	double alpha = 0.7390851332151606416553;			//Set alpha
        double xo = calcXo(0.0, M_PI/2.0);				//Calculate the first x for Newton's Method
	printHeader();							//Print Table Header

	double root = newtonsMethod(0, maxIterations, xo, xo, alpha);   //Recursively calculate the roots using Newton's Method
									//and produce a table with the results
	return 0;
}

/*
* This program computes the root up to n = 5 for the function
* cos(x) - x using Newton's Method. It will produce a table with
* thee results.
*
* CSC 2262 Programming Project 3
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

double calcXo(double lowerBound, double upperBound){
	return (upperBound + lowerBound)/2;
}

/*
* This function calculates the first x (Xo) for Newton's Method
*
* function: calcXo
*
* return type: double
*
* parameters:
*	lowerBound	[double]	Lower bound for interval
*
*	upperBound	[double]	Upper bound for interval
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

double function(double x){

	return cos(x) - x;
}

/*
* This function calculates the function cos(x) - x for a given x
*
* function: function
*
* return type: double
*
* parameters:
*	x	[double]	Calculated x for Newton's Method
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

double functionDerivative(double x){

	return -sin(x) - 1;
}

/*
* This function calculates the result for a given X within the first order
* derivative of the equation cos(x) - x
*
* function: functionDerivative
*
* return type: double
*
* parameters:
*	x	[double]	Given calculated x from Newton's Method
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

double newtonsMethod(int itr, int maxItr, double x, double priorX, double alpha){


	if(itr <= maxItr){

	   priorX = x;

	   double functionX = function(priorX);				//Calculate f(x(n))
	   double derivativeX = functionDerivative(priorX);		//Calculate f(x(n-1))

	   if(itr == 0){

	     show(itr, x, functionX, 0.0, 0.0);				// Print data for 0th iteration

	     return newtonsMethod(itr+1, maxItr, x, x, alpha);		// Recursively call Newton's Method for next iteration
	   }

	     x = priorX - (functionX/derivativeX);			// Calculate new x for current iteration


	     show(itr, x, functionX, x - priorX, alpha - priorX);	//Print the results for current iteration

	     itr++;

	     return newtonsMethod(itr, maxItr, x, priorX, alpha);	// Recursively call Newton's Method for next iteration
	}

	return x;							//Return the root for the max nth iteration
}

/*
* This method recursively outputs and calculates the various roots
* for a given n times using Netwon's Method
*
* function: newtonsMethod
*
* return type: double
*
* parameters:
*	itr		[int]		Counter to keep track of iteration n
*	maxItr		[int]		Maximum amount of iterations (final n)
*	x		[double]	Current calculated x in Newton's Method, i.e. xn
*	priorX		[double]	Previously calculated X from prior iteration, i.e.x(n-1)
*	alpha		[double]	The true root of the given function cos(x) - x
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

void printHeader(){

	cout << "n                    xn                     f(xn)            xn-x(n-1)         alpha-x(n-1)" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
}

/*
* This function prints the header for the table
*
* function: printHeader
*
* return type: void
*
* parameters: N/A
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void show(int n, double x, double functX, double difference, double alphaDifference){

	string space1 = "          ";	//Declare variables for each space in the table
	string space2 = "          ";
	string space3 = "          ";
	string space4 = "          ";


	if(n == 0){		//Set proper spacing for n = 0

	  space2 = "              ";

	  cout << n << space1;
	  cout << setprecision(15) << x << space2;
          cout << scientific << setprecision(2) << functX << space3;
          cout << "          " << space4;
          cout << "          " << endl;
          cout << endl;
	  return;
	}

	else if(n == 5){	// set proper spacing for n = 5

	   space2 = "           ";
	   space3 = "           ";
	   space4 = "           ";
	}

	cout << n << space1;
	cout << setprecision(15) << x << space2;
	cout << scientific << setprecision(2) << functX << space3;
	cout << scientific << setprecision(2) << difference << space4;
	cout << scientific << setprecision(2) << alphaDifference << endl;
	cout << endl;
	//Print out the row of results for given iteration
}

/*
* This function produced the table body and the proper spacing for each row and columnn
*
* function: show
*
* return type: void
*
* parameters:
*	n		[int]		Current n of Newton's Method
*	x		[double]	Current calculated x of Newton's Method
*	functX		[double]	Result of x within the function cos(x) - x
*	difference	[double]	Difference between current x and previous x for Newton's Method
*	alphaDifference	[double]	Difference between alpha amd current x for Newton's Method
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

/////////////////////////////////END PROGRAM//////////////////////////////////////////////////////
