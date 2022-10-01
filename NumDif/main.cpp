using namespace std;
// Namespace

#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <string>
// Libraries

double ForwardDiff(double, double);
double BackwardDiff(double, double);
double LagrangeBasis(double, double);
double UndeterminedCoeff(double, double);
void show(double, double, double, double, double);
// Prototypes

/*
* This program computes 4 different methods of
* numerical differentiation using the Forward
* Differentiation Formula, the Backward
* Differentiation Formula, Lagrange Basis, and
* the Method of Undetermined Coefficients. A table
* will be generated with the results. The current
* f(x) is sin(x)
*
* CSC 2262 Programming Project: Numerical Differentiation
*
* @author Chris Vasquez
* @since 10/28/2020
*
*/

int main(){

	double x = (2.0/3.0)*M_PI;			      // approximation's interval size
	vector<double> h = {0.1, 0.5, 0.025, 0.0125, 0.0625}; // Vector of evaluation points

	cout << "h            FDF             BDF              LB              UC" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	// Print the Header row of the table

	for(int i = 0; i < h.size(); i++)
	   show(h[i], ForwardDiff(x, h[i]), BackwardDiff(x, h[i]), LagrangeBasis(x, h[i]), UndeterminedCoeff(x, h[i]));
	// Calculate each method and print each row in the table for a given evaluaation point h

	return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
* This function computes the given f(x).
* In this case, the  function computes
* sin(x) where x is a given value
*
* function: f
*
* return type: double
*
* paramters:
*	x	[double]	a given input value for f(x)
*
* @author Chris Vasquez
* @since 10/28/2020
*
*/

double f(double x){

	return sin(x);

}

////////////////////////////////////////////////////////////

/*
* This function computes a numerical
* differentiation approximation using
* the forward difference formula
*
* function: ForwardDiff
*
* return type: double
*
* paramters:
*	x	[double]	a given input value for f(x)
*	h	[double]	a given evaluation point
*
* @author Chris Vasquez
* @since 10/28/2020
*
*/

double ForwardDiff(double x, double h){

	return (f(x + h) - f(x))/h;

}

///////////////////////////////////////////////////////////

/*
* This function computes a numerical
* differentiation approximation using
* the backward difference formula
*
* function: BackwardDiff
*
* return type: double
*
* paramters:
*	x	[double]	a given input value for f(x)
*	h	[double]	a given evaluation point
*
* @author Chris Vasquez
* @since 10/28/2020
*
*/

double BackwardDiff(double x, double h){

	return (f(x) - f(x + h))/h;

}

////////////////////////////////////////////////////////////


/*
* This function computes a numerical
* differentiation approximation using
* the Lagrange Basis
*
* function: LagrangeBasis
*
* return type: double
*
* paramters:
*	x	[double]	a given input value for f(x)
*	h	[double]	a given evaluation point
*
* @author Chris Vasquez
* @since 10/28/2020
*
*/

double LagrangeBasis(double x, double h){

	return (f(x + h) - f(x - h))/(2*h);

}

/////////////////////////////////////////////////////////////


/*
* This function computes a numerical
* differentiation approximation using
* the Method of Undetermined Coefficients
*
* function: UndeterminedCoeff
*
* return type: double
*
* paramters:
*	x	[double]	a given input value for f(x)
*	h	[double]	a given evaluation point
*
* @author Chris Vasquez
* @since 10/28/2020
*
*/

double UndeterminedCoeff(double x, double h){

	return (f(x + h) - 2*f(x) + f(x - h))/(h*h);

}

//////////////////////////////////////////////////////////////


/*
* This function constructs a row for the data table
* with the computed results for the given methods
*
* function: show
*
* return type: void
*
* paramters:
*	h		[double]	a given evaluation point
*	foward		[double]	Computed Results of the Forward Difference Formula
*	backward	[double]	Computed Results of the Backward Difference Formula
*	lagrange	[double]	Computed Results of the Lagrange Basis
*	undetermined	[double]	Computed Results of the Method of Undetermined Coefficients
*
* @author Chris Vasquez
* @since 10/28/2020
*
*/

void show(double h, double forward, double backward, double lagrange, double undetermined){

	string space = "	";

	cout << setprecision(10) << h << space;
	cout << setprecision(10) << forward << space;
	cout << setprecision(10) << backward << space;
	cout << setprecision(10) << lagrange << space;
	cout << setprecision(10) << undetermined << space;
	cout << endl;

	// Print the table with data
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////END PROGRAM//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
