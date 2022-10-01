using namespace std;
// Namespace

#include <iostream>
#include <vector>
#include <iomanip>
// Libraries

double f(double, double);
vector<vector<double>> eulerMethod(double, double, double, double);
void show(vector<vector<double>>, double);
// Prototypes

/********************************************************************/
/********************************************************************/

/*
* This program uses the Euler method to solve any given
* differential equation.
*
* CSC 2262 Euler Method
*
* @author Chris Vasquez
* @since 11/19/2020
*
*/

int main(){

	double low = 0;
	double high = 1;
	double h = 0.25;
	double y0 = 1;

	vector<vector<double>> output = eulerMethod(low, high, h, y0);

	show(output, h);

	return 0;
}

/********************************************************************/
/********************************************************************/
/********************************************************************/
/********************************************************************/

/*
* This function computes the result of a given differential equation
*
* method: f
*
* return type: double
*
* parameters:
*	x	[double]	xn for given iteration
*
*	y	[double]	yn for given iteration
*
* @author Chris Vasquez
* @since 11/19/2020
*
*/

double f(double x, double y){

	return x*y + (4*x)/y;	// Differential Equation
}


/*
* This function performs Euler's Method to solve a given
* differential equation
*
* function: eulerMethod
*
* return type: vector<vector<double>>
*
* parameters:
*	low	[double]	Low bound of x
*
*	high	[double]	high bound of x
*
*	h	[h]		Given step size
*
*	y0	[y0]		intial condition y(0)
*
* @author Chris Vasquez
* @since 11/19/2020
*
*/

vector<vector<double>> eulerMethod(double low, double high, double h, double y0){

	vector<vector<double>> output;
	output.resize(2);		// index [0][*] = x; [1][*] = yh(x)
	int n = 0;			// Iteration counter

	// Perform Euler Method

	for(double x = low; x <= high; x+=h){
	   output[0].push_back(x);
	   if(n != 0)
	     output[1].push_back(output[1][n-1] + h*f(output[0][n-1], output[1][n-1]));
	   else
	     output[1].push_back(y0);
	   n++;
	}

	return output;	// Return x values and computer y values
}


/*
* This function displays the results of the
* Euler Method calculations, i.e. h, x, yh(x)
*
* function: show
*
* return type: void
*
* parameters:
*	out	[vector<vector<double>>]	Used X values and computer y values
*
*	h	[double]			Given Step Size
*
* @author Chris Vasquez
* @since 11/19/2020
*
*/

void show(vector<vector<double>> out, double h){

	// Display results in the terminal

	cout << "h	x	yh(x)" << endl;

	for(int i = 0; i < out[0].size(); i++){
	   cout << setprecision(2) << fixed << h << "	";
	   cout << setprecision(2) << fixed << out[0][i] << "	";
	   cout << setprecision(4) << fixed << out[1][i];
	   cout << endl;
	}
}
