using namespace std;
// Namespaces

#include <iostream>
#include <vector>
#include <iomanip>
// Libraries

vector<vector<double>> getAugmentedMatrix(vector<vector<double>>, vector<double>, int);
vector<double> gaussianElimination(vector<vector<double>>, vector<double>, int);
void show(vector<vector<double>>, vector<double>, vector<double>);
// Prototypes

/****************************************************************************************/

/*
* This program uses Gaussian Elimination with Pivoting
* to solve a system of linear equations of any size n > 1.
* It will aoutput the matricies of each term within Ax = b
*
* CSC 2262 Programming Project: Gaussian Elimination
*
* @author Chris Vasquez
* @since 11/6/2020
*
*/

int main(){

	int n = 4;	// Size of Matrix (n x n)

	vector<vector<double>> A	// Matrix of A
	{
	   {2.0,   1.0, -1.0, -2.0},
	   {4.0,   4.0,  1.0,  3.0},
	   {-6.0, -1.0,  10.0, 10.0},
	   {-2.0,  1.0,  8.0,  4.0}
	};

	vector<double> b	// Matrix of b
	{
	    2.0,
	    4.0,
	   -5.0,
	    1.0
	};

	vector<double> x = gaussianElimination(A, b, n);	// Calculated x values matric from Gaussian Elimination


	show(A, x, b);	// Display the results in the terminal

	return 0;
}

/*************************************************************************************/
/*******************************HELPER FUNCTIONS**************************************/
/*************************************************************************************/


/*
*
* This function uses Gaussian Elimination to calculate the values of the X matrix
* and return said matrix
*
* function: gaussianElimination
*
* return type: vector<double>
*
* parameters:
*	A	[vector<vector<double>>]	the matrix of A
*
*	b	[vector<double>]		the matrix of b
*
*	n	[int]				the size of matrix A (being n x n)
*
* @author Chris Vasquez
* @since 11/6/2020
*
*/

vector<double> gaussianElimination(vector<vector<double>> A, vector<double> b, int n){

	vector<double> x;
	x.resize(n);

	// Perform Gaussian Elimination with Pivoting

	for(int k = 0; k < n; k++){

	   int maxColoumnIndex = k;

	   for(int x = k+1; x < n; x++){

	      double temp1 = A[x][k];

	      if(temp1 > A[maxColoumnIndex][k])
		maxColoumnIndex = x;
	   }

	   if(k != n-1){

	      vector<double> temp2 = A[k];
	      A[k] = A[maxColoumnIndex];
	      A[maxColoumnIndex] = temp2;

	      double temp3 = b[k];
	      b[k] = b[maxColoumnIndex];
	      b[maxColoumnIndex] = temp3;
	   }

	   for(int i = k+1; i < n; i++){
	        double m = A[i][k]/A[k][k];

		for(int j = k+1; j < n; j++){
		   A[i][j] = A[i][j] - m*A[k][j];
		}

	        b[i] = b[i] - m*b[k];
	   }
	}

	// Use backward substitution for finding the x values

	for(int i = n-1; i >= 0; i--){

	   x[i] = b[i];

	   for(int j = 0; j < n; j++)
	      if(i != j)
		x[i] = x[i] - A[i][j]*x[j];

	   x[i] = x[i]/A[i][i];

	}

	// Return the X values matrix

	return x;
}

/*
* This function outputs the matricies of A, b, and x within the equation
* Ax = b into the terminal.
*
* function: show
*
* return type: void
*
* parameters:
*	A	[vector<vector<double>>]	the matrix of A
*
*	x	[vector<double>]		the matrix of x
*
*	b	[vector<double>]		the matrix of b
*
* @author Chris Vasquez
* @since 11/6/2020
*
*/

void show(vector<vector<double>> A, vector<double> x, vector<double> b){

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

	for(int i = 0; i < x.size(); i++){
	   if(x[i] >= 0 && !(x[i] >= 10))
	     cout << fixed << setprecision(3) << "  |     " << x[i] << "     |" << endl;
	   else
     	     cout << fixed << setprecision(3) << "  |    " << x[i] << "     |" << endl;

	}

	cout << endl;

	cout << "b =" << endl;;

	// Display the matrix of b

	for(int i = 0; i < b.size(); i++){
	   if(b[i] >= 0 && !(b[i] >= 10))
	     cout << fixed << setprecision(3) << "  |     " << b[i] << "     |" << endl;
	   else
	     cout << fixed << setprecision(3) << "  |    " << b[i] << "     |" << endl;
	}
}
