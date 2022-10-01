using namespace std;

#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <iomanip>

double function(double);
double secantMethod(int, int, double, double, double);
void printHeader();
void show(int, double, double, double);
// Prototypes

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

int main(){

        int maxIterations = 5;					   //Set max iterations
        double x0 = 0;						   //Declare first and second guess X for Secant Method
	double x1 = M_PI/2;
	printHeader();						   //Print Table Header

	double root = secantMethod(0, maxIterations, x1, x0, 0);   //Recursively calculate the roots using the Secant Method
								   //and produce a table with the results
	return 0;
}

/*
* This program computes the root up to n = 5 for the function
* cos(x) - x using the Secant Method. It will produce a table with
* thee results.
*
* CSC 2262 Programming Project 3
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
*	x	[double]	Calculated x for the Secant Method
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

double secantMethod(int itr, int maxItr, double x, double priorX1, double priorX2){


	if(itr <= maxItr){

	   if(itr == 0.0){

	     show(itr, priorX1, function(priorX1), 0.0);		// Print data for 0th iteration

	     return secantMethod(itr+1, maxItr, x, priorX1, priorX2);	// Recursively call Secant Method for next iteration
	   }

	   else if(itr == 1.0){

	     show(itr, x, function(x), x-priorX1);

	     return secantMethod(itr+1, maxItr, x, priorX1, priorX2);
	   }

           priorX2 = priorX1;
           priorX1 = x;

           double functionPriorX1 = function(priorX1);
           double functionPriorX2 = function(priorX2);

           x = priorX1 - functionPriorX1 / ((functionPriorX1 - functionPriorX2)/(priorX1 - priorX2));	// Calculate new x for current iteration

           double functionX = function(x);                              //Calculate f(x(n))

	   show(itr, x, functionX, x - priorX1);			       			        //Print the results for current iteration

	   itr++;

	   return secantMethod(itr, maxItr, x, priorX1, priorX2);	// Recursively call Secant Method for next iteration
	}

	return x;						        // Return the root for the max nth iteration
}

/*
* This method recursively outputs and calculates the various roots
* for a given n times using the Secant Method
*
* function: secantMethod
*
* return type: double
*
* parameters:
*	itr		[int]		Counter to keep track of iteration n
*	maxItr		[int]		Maximum amount of iterations (final n)
*	x		[double]	Current calculated x in the Secant Method, i.e. xn
*	priorX1		[double]	Previously calculated X from prior iteration, i.e.x(n-1)
*	priorX2		[double]	Previously calculated X from prior iteration, i.e.x(n-2)
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

void printHeader(){

	cout << "n                    xn                     f(xn)            xn-x(n-1)         " << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
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

void show(int n, double x, double functX, double difference){

	string space1 = "          ";	//Declare variables for each space in the table
	string space2 = "          ";
	string space3 = "          ";


	if(n == 0){		//Set proper spacing for n = 0

	  space2 = "                              ";

	  cout << n << space1;
	  cout << setprecision(15) << x << space2;
          cout << scientific << setprecision(2) << functX << endl;
          cout << endl;
	  return;
	}

	else if(n == 5){	// set proper spacing for n = 5

	   space2 = "          ";
	   space3 = "          ";
	}

	cout << n << space1;
	cout << setprecision(15) << x << space2;
	cout << scientific << setprecision(2) << functX << space3;
	cout << scientific << setprecision(2) << difference << endl;
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
*	n		[int]		Current n of the Secant Method
*	x		[double]	Current calculated x of the Secant Method
*	functX		[double]	Result of x within the function cos(x) - x
*	difference	[double]	Difference between current x and previous x for the Secant Method
*
* @author Chris Vasquez
* @since 9/18/2020
*
*/

////////////////////////////////////////////END PROGRAM//////////////////////////////////////////////////////
