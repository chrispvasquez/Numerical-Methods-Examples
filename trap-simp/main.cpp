using namespace std;

#include <iostream>
#include <vector>
#include <math.h>
#include "trapSimp.h"

/*
* This program computes an integral approximation
* using the trapaezoidal rule and simpson rule
* for a given upper and lower limit and a given
* n.
*
* CSC 2262 Programming Project
*
* @author Chris Vasquez
* @since 10/21/2021
*
*/

int main(){

	int n = pow(2, 9);					// number of sub intervals
	double upper = 3;					// upper limit
	double lower = 1;					// lower limit

	TrapSimp myObject(n, upper, lower);			// trapezoidal/simpson rule object

	Show(myObject.Trapezoidal(), myObject.Simpson(), n);	// Display results of trapezoidal/simpson rule

	return 0;
}
