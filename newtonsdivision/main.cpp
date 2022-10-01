using namespace std;

#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <iomanip>
// Libraries

double applyFormula(double, double, double, double);
vector<double> getSineValues(vector<double>);
vector<double> dividedDifferences(vector<double>, vector<double>, vector<double>, int, int);
vector<double> interpolation(double, vector<double>, vector<double>);
void show(vector<double>, vector<double>, vector<double>, vector<vector<double>>, vector<double>);
// Prototypes

/*
* This program implements Newton's Divided Difference Interpolation Formula,
* for n=6.  The function evaluated is sin(x) for various different x points
*
* CSC 2262 Programming Project 4
*
* @author Chris Vasquez
* @since 9/26/2020
*
*/

int main(){

	vector<double> x = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2}; // Stores the known points
	vector<double> points = {0.1, 0.3, 0.5};                // Stores points to evaluate
	vector<double> sine = getSineValues(x);                 // Vector of sine calculated values
	vector<double> temp;					// Temporary vector for formula implementation
	vector<double> D;					// Stores the Divided Differences calculated

	D.resize(7);						// Allocates vector size

	D = dividedDifferences(x, temp, D, 0, x.size());	// Implement formula

	vector<vector<double>> p; 				// Stores the results ofapproximating the known points

	p.resize(3);						// Allocate vector size

	for(int i = 0; i < points.size(); i++)
	  p[i] = interpolation(points[i], x, D);		// Approximate sin(x) at known points using Divided Differences

	show(D, sine, x, p, points); 				// generate table 1 and table 2

	return 0;
}


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

double applyFormula(double param0, double param1, double param2, double param3){

	double num = param0 - param1;	// Calculate numerator
	double den = param2 - param3;	// Calculate denominator

	return num/den;			// Assemble fraction and return computed value
}

/*
* This method implements the part of the divided difference formula
*
* function: apply Formula
*
* return type: double
*
* parameters:
*	param0	[double]	function to implement formula
*
*	parma1	[double]	function to implement formula
*
*	param2	[double]	function to implement formula
*
*	param3	[double]	function to implement formula
*
* @author Chris Vasquez
* @since 9/26/2020
*
*/

/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

vector<double> getSineValues(vector<double> x){

	vector<double> v;

	for(int i = 0; i < x.size(); i++)
	  v.push_back(sin(x[i]));		//Fill vecector with sine values of x

	return v;
}

/*
* This function calculates the exact Sine values of each passed point within
* the vector x
*
* function: getSineValues
*
* return type: vector<double>
*
* parameters:
*	x	[vector<double>]	Points to implement into sine function
*
* @author Chris Vasquez
* @since 9/26/2020
*
*/

/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

vector<double> dividedDifferences(vector<double> x, vector<double> temp, vector<double> D, int itr, int maxItr){


	if(itr == 0){	      // If 0th iteration

	  D[itr] = sin(x[0]); // Fill the Divided Difference Array with Xo


	  for(int i = 0; i < x.size(); i++)	temp.push_back(sin(x[i]));	// Fill temp with inital x values

	  return dividedDifferences(x, temp, D, itr+1, D.size());		// Recursively call function
	}

	else if(itr < maxItr){	// for eevery other iteration till max iteration


	  for(int i = 0; i < temp.size()-1; i++)  temp[i] = applyFormula(temp[i+1], temp[i], x[i+itr], x[i]);


	    D[itr] = temp[0];	// Store divided difference for respective iteration

	    temp.pop_back();	// Remove last element in temp vector after each iteration


	  return dividedDifferences(x, temp, D, itr+1, maxItr);	//Recursively call the function
	}

	return D;	// Return vector of calculated divided differences
}


/*
* This function calculates the divided differences from the points
* in x. The results are stored in D
*
* function: dividedDifferences
*
* return type: vector<double>
*
* paramters:
*	x	[vector<double>]	Stores points to calculate divided differences from
*
*	temp	[vector<double>]	Temporary vector for algorithm implementation
*
*	D	[vector<double>]	Divided differences calculated
*
*	itr	[int]			iteration counter
*
*	maxItr	[int]			max iterations
*
* @author Chris Vasquez
* @since 9/26/2020
*
*/

/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

vector<double> interpolation(double point, vector<double> x, vector<double> differs){

	double temp = 0;
	double counter = 0;
	vector<double> p;

	for(int i=0; i < x.size(); i++){	// Implement Interpolation formula based on respective iteration

	  temp += differs[i];

	  for(int j = 0; j < i; j++){

	    temp = temp * (point - x[j]);

	  }

	  counter += temp;
	  p.push_back(counter);
	  temp = 0;
	}

	return p;	// Return formula results
}


/*
* This function calculates the interpolation to sin(s) using the divided
* differences from differs. Results are stored in p
*
* function: interpolation
*
* return type: vector<double>
*
* parameters:
*	point	[double]		stores points to implement interpolation on
*
*	x	[vector<double>]	stores known points used to calculate divided differences
*
*	differs	[vector<double>]	calculated divided differences from points in x
*
* @author Chris Vasquez
* @since 9/26/2020
*
*/

/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void show(vector<double> differs, vector<double> sines, vector<double> x, vector<vector<double>> p, vector<double>points){

	// Generate table 1

	cout << "i               xi                   sin(xi)                  Di" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;

	string space = "          ";

	for(int i = 0; i < x.size(); i++){

	  cout << scientific << setprecision(7) << i << space;
	  cout << scientific << setprecision(7) << x[i] << space;
	  cout << setprecision(6) << sines[i] << space;
	  cout << scientific << setprecision(7) << differs[i] << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;


	// Generate table 2

	cout << "n             Pn(0.1)                Pn(0.3)                Pn(0.5)                " << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	for(int i = 1; i < x.size(); i++)

	  cout << setprecision(7) << i << space << p[0][i] << space << p[1][i] << space << p[2][i] << endl;
}


/*
* This function generates the results of Newton's DIvided Differences formula
* into two different table in the terminal
*
* function: show
*
* return type: void
*
* parameters:
*	differs	[vector<double>]		Calculated divided differences
*
*	sines	[vector<double>]		sine values of point within x
*
*	x	[vector<double>]		known points evaluated with formula
*
*	p	[vector<vector<double>>]	interpolation to sin(s) results
*
*	points	[vector<double>]		points used to generate interpolation results
*
* @author Chris Vasquez
* @since 9/26/2020
*
*/

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
///////////////////////////END PROGRAM///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
