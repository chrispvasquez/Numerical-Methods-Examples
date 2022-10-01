using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
// Libraries

vector<vector<double>> cubicSpline(vector<double>, vector<double>, int, int);
void show(vector<double>, vector<vector<double>>);
// Prototypes

/*
* This program is used to calculate the Cubic Spline
* from a given set of x and f(xj) values. The results
* will be outputted into a table.
*
* CSC 2262 Programming Project 6
*
* @author Chris Vasquez
* @since 9/29/2020
*
*/

int main(){

	vector<double> x = {17.0, 20.0, 23.0, 24.0, 25.0, 27.0, 27.7};	// Create Vector of x values
	vector<double> a = {4.5, 7.0, 6.1, 5.6, 5.8, 5.2, 4.1};	        // Create Vector of f(xj) values
	int vSize = x.size();						// Get size for vectors used in Cubic Spline method
	int n = x.size()-1;						// Get n size

	vector<vector<double>> output = cubicSpline(x, a, vSize, n);	// Calculate the Cubic Spline

	show(x, output);						// Output Results in Table Form

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<vector<double>> cubicSpline(vector<double> x, vector<double> a, int vectSize, int n){

	// Declare Vectors for algorithm implementation
	vector<double> alpha;
	vector<double> h;
	vector<double> l;
	vector<double> u;
	vector<double> z;
	vector<double> b;
	vector<double> c;
	vector<double> d;

	// Size each vector to the proper size
	alpha.resize(vectSize);
	h.resize(vectSize);
	l.resize(vectSize);
	u.resize(vectSize);
	z.resize(vectSize);
	b.resize(vectSize);
	c.resize(vectSize);
	d.resize(vectSize);


	// Fill vector h
	for(int i = 0; i < n; i++)
	   h[i] = x[i+1] - x[i];


	// Calculate Alpha
	for(int i = 1; i < n; i++){

	   double alphaNum = 3*(a[i+1]*h[i-1] - a[i]*(x[i+1] - x[i-1]) + a[i-1]*h[i]);
	   double alphaDen = h[i-1]*h[i];

	   alpha[i] = alphaNum/alphaDen;
	}

	// Set index 0 of vector l, z, and c to 1, 0, and 0, respectively
	l[0] = 1;
	u[0] = 0;
	z[0] = 0;

	// Calculate each value at each index for vectors l, u, and z
	for(int i = 1; i < n; i++){

	   l[i] = 2.0*(x[i+1] - x[i-1]) - h[i-1]*u[i-1];
	   u[i] = h[i]/l[i];
	   z[i] = (alpha[i] - (h[i-1]*z[i-1]))/l[i];
	}

        // Set index n of vector l, z, and c to 1, 0, and 0, respectively
	l[n] = 1;
	z[n] = 0;
	c[n] = 0;

	// Calculate each value at each index for vectors c, b, and d
	for(int j = n-1; j >= 0; j--){

	   c[j] = z[j] - (u[j]*c[j+1]);
	   b[j] = (a[j+1]-a[j])/h[j] - h[j]*(c[j+1] + 2*c[j])/3;
	   d[j] = (c[j+1] - c[j])/(3.0*h[j]);
	}

	// Store vector results within another vector
	vector<vector<double>> output = {a, b, c, d};

	// Return cubic spline calculation results
	return output;

}

/*
* This function calculates the Cubic Spline
* using the provided algorithm from class.
* Results are returned as a vector of vectors
*
* function: cubicSpline
*
* return type: vector<vector<double>>
*
* parameters:
*	x		[vector<double>]	X Values
*
*	a		[vector<double>]	f(xj) Values
*
*	vectSize	[int]			Size for each vector used within the function
*
*	n		[int]			Final index value of vectors
*
*
* @author Chris Vasquez
* @since 9/29/2020
*
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

void show(vector<double> x, vector<vector<double>> output){

	string space = "             ";

	// Print the Table Header

	cout << "j             xj           aj=f(xj)         bj                cj               dj" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;


	for(int i = 0; i < x.size(); i++){

	   // Set proper spacing based on iteration number

	   switch(i){

	      case 0:
	         cout << i  << space;
	         cout << x[i] << space;
	         cout << output[0][i] << "           ";
	         cout << setprecision(4) << output[1][i] << space;
	         cout << setprecision(3) << output[2][i] << "               ";
	         cout << setprecision(2) << output[3][i] << endl;
		 break;

	      case 1:

	         cout << i  << space;
	         cout << x[i] << space;
	         cout << output[0][i] << "             ";
	         cout << setprecision(3) << output[1][i] << "            ";
	         cout << setprecision(3) << output[2][i] << "            ";
	         cout << setprecision(2) << output[3][i] << endl;
		 break;

	      case 2:

	         cout << i  << space;
	         cout << x[i] << space;
	         cout << output[0][i] << "          ";
	         cout << setprecision(3) << output[1][i] << space;
	         cout << setprecision(2) << output[2][i] << "            ";
	         cout << setprecision(3) << output[3][i] << endl;
		 break;

	      case 3:

	         cout << i  << space;
	         cout << x[i] << space;
	         cout << output[0][i] << "          ";
	         cout << setprecision(3) << output[1][i] << "             ";
	         cout << setprecision(3) << output[2][i] << "           ";
	         cout << setprecision(3) << output[3][i] << endl;
		 break;

	      case 4:

	         cout << i  << space;
	         cout << x[i] << space;
	         cout << output[0][i] << "           ";
	         cout << setprecision(3) << output[1][i] << "            ";
	         cout << setprecision(3) << output[2][i] << "           ";
	         cout << setprecision(2) << output[3][i] << endl;
		 break;

	      case 5:

	         cout << i  << space;
	         cout << x[i] << space;
	         cout << output[0][i] << "          ";
	         cout << setprecision(4) << output[1][i] << "            ";
	         cout << setprecision(3) << output[2][i] << space;
	         cout << setprecision(3) << output[3][i] << endl;
		 break;

	      default:

	         cout << i  << space;
	         cout << x[i] << "           ";
	         cout << output[0][i] << space;
		 cout << endl;
		 break;
	   }
	}

}


/*
* This function generates the table of results
* with appropriate spacing between coloumns
*
* function: show
*
* return type: void
*
* parameters:
*	x	[vector<double>]		X values used in computation
*
*	output	[vector<vector<double>>]	Results of the Cubic Spline function
*
* @author Chris Vasquez
* @since 9/29/2020
*
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////END PROGRAM////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
