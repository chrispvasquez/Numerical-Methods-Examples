using namespace std;

#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

/* Class for applying the trapezoidal/simpson rule */

class TrapSimp{

	private:

	   int m_n;		// Number of Intervals
	   double m_upper;	// Upper Bound
	   double m_lower;	// Lower Bound

	   double f(double x){	// Function f(x)
	   	return log(x);
	   }

	public:

	   TrapSimp(double, double, double);	// Constructor
	   ~TrapSimp(){};			// Destructor
	   double Trapezoidal();		// Calculate the approximation with Trapezoidal rule
	   double Simpson();			// Calculate the approximation with Simpson Rule
};

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

/* Constructor */

TrapSimp::TrapSimp(double n, double upper, double lower){

	this->m_n = n;
	this->m_upper = upper;
	this->m_lower = lower;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* This function computes the integral approximation using
* using the trapezoidal rule
*
* function: Trapezoidal
*
* return type: double
*
* parameters: N/A
*
* @author Chris Vasquez
* @since 10/21/2020
*
*/

double TrapSimp::Trapezoidal(){

	double h = (m_upper - m_lower)/m_n;   // h
	vector<double> x;		      // Stores the x values for each interval
	x.resize(m_n+1);
	double tempX = m_lower;		      // Counter for each X starting at lower bouund
	double trapSum = 0;		      // Stores the sum of all the trapezoidal rule terms


	for(int i = 0; i <= m_n; i++){	      // Calculate each interval's x;
	   x[i] = tempX;
	   tempX += h;
	}


	for(int i = 0; i <= m_n; i++){	      // Calculate all the f(x) terms for the trapezoidal rule and add them

	   if(i == 0)
	     trapSum += f(x[0])/2;

	   else if(i == m_n)
	     trapSum += f(x[i])/2;

	   else
	     trapSum += f(x[i]);
	}

	return h*trapSum;		     // Return the trapezoidal sum times h to calculate the final result of the trapezoidal rule
}


/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* This function computes the integral approximation using
* using the simpson rule
*
* function: Simpson
*
* return type: double
*
* parameters: N/A
*
* @author Chris Vasquez
* @since 10/21/2020
*
*/

double TrapSimp::Simpson(){

        double h = (m_upper - m_lower)/m_n;   // h
        vector<double> x;                     // Stores the x values for each interval
        x.resize(m_n+1);
        double tempX = m_lower;               // Counter for each X starting at lower bouund
        double simpSum = 0;                   // Stores the sum of all the simpson rule terms

	for(int i = 0; i <= m_n; i++){	      // Calculate each interval's x;
	   x[i] = tempX;
	   tempX += h;
	}

	for(int i = 0; i <= m_n; i++){	      // Calculate all f(x) terms for the Simpson rule and add them

	   if(i == 0)
	     simpSum += f(x[0]);

	   else if(i == m_n)
	     simpSum += f(x[i]);

	   else if(i%2 == 1)
	     simpSum += 4*f(x[i]);

	   else
	     simpSum += 2*f(x[i]);
	}

	return (h/3)*simpSum;		     // Return final result of Simpson's fule after multiplying simpSum by h/3
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* This function displays the results of the computed
* integral approximation with the simpson rule and
* trapezoidal rule
*
* function: Show
*
* return type: void
*
* parameters:
*	t	[double]	trapezoidal rule result
*
*	s	[double]	simpson rule result
*
*	n	[int]		number of subintervals
*
* @author Chris Vasquez
* @since 10/21/2020
*
*/

void Show(double t, double s, int n){

	cout << "Trapezoidal Rule: T" << n << "(f) = " ;	// Print out Trapezoidal rule results
	cout << setprecision(15) << t << endl;

	cout << endl;

        cout << "Simpson Rule: S" << n << "(f) = ";		// Print out simpson rule results
	cout << setprecision(15) << s << endl;
}
