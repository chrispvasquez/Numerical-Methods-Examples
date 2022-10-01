using namespace std;
// Namespace

#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <cmath>
// Libraries

void show(vector<vector<double>>, vector<vector<double>>, vector<double>);
vector<vector<double>> gaussSeidelIterationMethod(vector<vector<double>>, vector<double>, double);
// Prototypes


/*
* This program computes the values of x for a given n
* equations using the Gauss Seidel Iteration method.
* Results are displayed in table format into the terminal.
*
* CSC 2262 Gauss Seidel Iteration Method
*
* @author Chris Vasquez
* @since 11/14/2020
*
*/

int main(){

	double epsilon = 0.0001;	// Epsilom to test convergence

	vector<vector<double>> A	// Matrix of A
	{
	   { 4.0, -1.0,  0.0, -1.0,  0.0,  0.0},
	   {-1.0,  4.0, -1.0,  0.0, -1.0,  0.0},
	   { 0.0, -1.0,  4.0,  0.0,  0.0  -1.0},
	   {-1.0,  0.0,  0.0,  4.0, -1.0,  0.0},
	   { 0.0, -1.0,  0.0, -1.0,  4.0, -1.0},
	   { 0.0,  0.0, -1.0,  0.0, -1.0,  4.0}
	};

	vector<double> b	// Matrix of b
	{
	    0.0,
	    5.0,
	    0.0,
	    6.0,
	   -2.0,
	    6.0
	};

	// Vector of Vectors to store table of x values at each iteration along with error
	vector<vector<double>> xTable = gaussSeidelIterationMethod(A, b, epsilon);

	// Display the results into the terminal
	show(A, xTable, b);

	return 0;
}

/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/

/*
* This function uses the Gauss Seidel Iteration Method to compute the values
* of X. Additionally, it computes the error between each iteration using the
* Euclidian norm
*
* function: gaussSeidelIterationMethod
*
* return type: vector<vector<double>>
*
* parameters:
*	A	[vector<vector<double>>]	the matrix of A
*
*	b	[vector<double>]		the matrix of b
*
*	ep	[int]				the value of epsilon for testing convergence
*
* @author Chris Vasquez
* @since 11/14/2020
*
*/

vector<vector<double>> gaussSeidelIterationMethod(vector<vector<double>> A, vector<double> b, double ep){

	vector<double> x0;		// Initial X0 vector
	vector<vector<double>> xValues; // Vector for X Value iterations
	int k = 0;			// Iteration counter

	// Use Zero Vector for Initial Guess
	for(int i = 0; i < A.size(); i++)
	   x0.push_back(0);
	xValues.push_back(x0);

	// Perform Gauss Seidel Iteration Method until convergence

	do {
	    vector<double> tempRow;

	    for(int i = 0; i < A.size(); i++){
                  double tempX = 0;
		  tempX += b[i];
		  int kPlusCounter = 0;

		  for(int j = 0; j < A.size(); j++){
		     if(j != i){
		       if(kPlusCounter < i){
		         tempX -= A[i][j]*tempRow[j];
			 kPlusCounter++;
		       }
		       else
			 tempX -= A[i][j]*xValues[k][j];
		     }
	          }

		  tempX = (1/A[i][i])*tempX;
		  tempRow.push_back(tempX);
	    }

	    // Calculate the Error

	    double priorEuclid = 0;
	    double currEuclid = 0;

	    for(int x = 0; x < A.size(); x++){
	       priorEuclid += pow(xValues[k][x], 2);
	       currEuclid += pow(tempRow[x], 2);
	    }

	    priorEuclid = sqrt(priorEuclid);
	    currEuclid = sqrt(currEuclid);

	    double error = priorEuclid - currEuclid;

	    tempRow.push_back(error); // add the error to the end of the x values

	    xValues.push_back(tempRow); // Add computed iteration x values to the table

	    k++;

	} while((abs(xValues[xValues.size()-1][A.size()]) - ep) > ep);

	// Return table of x values at each iteration and error
	return xValues;
}


/*
* This function outputs the matricies of A, b, and x within the equation
* Ax = b into the terminal in addition to displaying the iteration table
*
* function: show
*
* return type: void
*
* parameters:
*	A	[vector<vector<double>>]	the matrix of A
*
*	x	[vector<vector<double>>]	Matrix of Calculated x values and error
*
*	b	[vector<double>]		the matrix of b
*
* @author Chris Vasquez
* @since 11/14/2020
*
*/

void show(vector<vector<double>> A, vector<vector<double>> x, vector<double> b){

	// Displays the tables of k, X values, and error

	cout << "k      ";
	for(int i = 0; i < A.size(); i++)
	   cout << "x " << i << "       ";
	cout << "Diff" << endl;

	for(int j = 0; j < x.size(); j++){
	   if(j <= 9)
	     cout << "  " << j;
	   else
	     cout << " " << j;
	   for(int k = 0; k < x[j].size(); k++)
	      if(x[j][k] >= 0)
	         cout << fixed << setprecision(4) << "    " << x[j][k];
	      else
		 cout << fixed << setprecision(4) << "   "<< x[j][k];
	   cout << endl;
	}

	cout << endl;
	cout << endl;

	cout << "Ax = b" << endl;
	cout << endl;

	cout << "A =" << endl;

	// Display the matrix of A

	for(int i = 0; i < A.size(); i++){
	   cout << "  ";
	   for(int j = 0; j < A.size(); j++){
	      if(A[i][j] >= 0 && !(A[i][j] >= 10))
	      	cout << fixed << setprecision(3) << "|     " << A[i][j] << "     ";
	      else
	      	cout << fixed << setprecision(3) << "|    " << A[i][j] << "     ";

	   }
	      cout << "|" << endl;
	}

	cout << endl;

	cout << "x =" << endl;

	// Display the matrix of x values

	cout << "  |";
	for(int i = 0; i < x[x.size()-1].size() - 1; i++){
	   if(x[x.size()-1][i] >= 0 && !(x[x.size()-1][i] >= 10))
	     cout << fixed << setprecision(3) << "  " << x[x.size()-1][i] << "  |";
	   else
     	     cout << fixed << setprecision(3) << " " << x[x.size()-1][i] << "  |";
	}

	cout << endl;
	cout << endl;

	cout << "b =" << endl;;

	// Display the matrix of b

	cout << "  |";
	for(int i = 0; i < b.size(); i++){
	   if(b[i] >= 0 && !(b[i] >= 10))
	     cout << fixed << setprecision(3) << "  " << b[i] << "  |";
	   else
	     cout << fixed << setprecision(3) << " " << b[i] << "  |";
	}

	cout << endl;
}


/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/
/*******************************END PROGRAM****************************************/
/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/
/**********************************************************************************/
