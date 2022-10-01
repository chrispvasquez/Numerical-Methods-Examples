using namespace std;

#include <iostream>
#include <string>
#include <iomanip>

class Summation {

	private:

	   double m_N;   // Representes the chosen n for the summation.

	public:

	   Summation(){

	      m_N = 0;

	   }
	   // Default Constructor
	   // Initalizes m_N to 0


	   ~Summation(){};
	   //Destructor


	   double CalcTrue();
	/*
	* This function computes thhe true value of the
	* given function.
	*
	* function: CalcTrue
	*
	* return type: double
	*
	* parameters: N/A
	*
	* @author Chris Vasquez
	* @since 9/11/2020
        *
	*/


	   double CalcSmallToLarge();
	/*
        * This function computes the given functions's
        * summation form, starting with the smallest
        * instance of j till the largest instance, n
        *
        * function: CalcSmallToLarge
        *
        * return type: double
        *
        * parameters: N/A
	*
        * @author Chris Vasquez
        * @since 9/11/2020
        *
	*/


	   double CalcLargeToSmall();
	/*
        * This functionm computes the given function's
        * summation form, starting with the largest
        * instance of j, i.e. n, till the smallest
        * instance, i.e. 1
        *
        * function: CalcLargeToSmall
        *
        * return type: double
        *
        * parameters: N/A
        *
        * @author Chris Vasquez
        * @since 9/11/2020
        *
	*/


	   void SetN(double);
	/*
        * This function sets the value of m_N
        * for an object of type Summation
        *
        * function: SetN
        *
        * return type: void
        *
        * parameters:
        *	n	[double]	value of n to evalutate at
        *
        * @author Chris Vasquez
        * @since 9/11/2020
        *
	*/


	   double GetN();
	/*
        * This function gets the value of m_N
        * for an object of type Summation
        *
        * function: GetN
        *
        * return type: double
        *
        * parameters: N/A
        *
        * @author Chris Vasquez
        * @since 9/11/2020
        *
	*/



	   double CalcError(double, double);
	/*
        * This function calculates the error between
        * the true value and the summation approximation
        *
        * function CalcError
        *
        * return type: double
        *
        * parameters:
        *	trueValue	 [double]	The true value of the function
        *
        *	SummationApprox	 [double]	The summation approximation of the function
        *
        * @author Chris Vasquez
        * @since 9/11/2020
        *
	*/
};

/*******************************************************************/
/*******************************************************************/
/*******************************************************************/

double Summation::CalcTrue(){

	double answer = (3.0/4.0) - ((2.0*m_N + 3.0)/(2.0*(m_N + 1.0)*(m_N + 2.0)));
	//Calculates the summation's true value function for given n

	return answer;
}


double Summation::CalcSmallToLarge(){

	double answer = 0; // Initialize counter variable to 0

	for(double j = 1.0; j <= m_N; j++) answer += (1.0/(j*(j + 2.0)));
	//Compute summation starting from 1 to given n

	return answer;
}


double Summation::CalcLargeToSmall(){

	double answer = 0; //Initializae counter variable

	for(double j = m_N; j >= 1.0; j--) answer += (1.0/(j*(j + 2.0)));
	// Compute the summation starting with given n down until 1

	return answer;
}


void Summation::SetN(double x){

	m_N = x; //Set n to given x
}


double Summation::GetN(){

	return m_N; //Retrieve object's n value
}


double Summation::CalcError(double trueValue, double approx){

	return trueValue - approx; // Subtract trueValue - approx of function
}


void Show(Summation s, double n){

	s.SetN(n); //Set the n for a given value

	string space;
	string space2 = "          ";
	string space3 = "          ";
	// Initialize strings for properly spaced table

	if(10 == n){
			     space = "         ";
			     space3 = "           ";
	}
	else if(50 == n)     space = "         ";
	else if(100 == n){
			     space = "        ";
			     space3 = "           ";
	}
	else if(500 == n)    space = "        ";
	else if(1000 == n)   space = "       ";
	else if(5000 == n){
			     space = "       ";
			     space2 = "            ";
	}
	// Determine the proper spacing of the table based on
	// the given values of n

	double t = s.CalcTrue();	       //Calculate the true value of the function
	double sl = s.CalcSmallToLarge();      //Calculate the approx of function for summation from small j to large j
	double errorSL = s.CalcError(t, sl);   //Calculate the error between the true value and the small to large approx
	double ls = s.CalcLargeToSmall();      //Calculate the approx of the function for the summation from large j to small j
	double errorLS = s.CalcError(t, ls);   //Calculate the error between the true value and the large to small approx

	cout << setprecision(25) << t << endl;
	cout << setprecision(25) << ls << endl;
	cout << setprecision(25) << errorLS << endl;
	cout << setprecision(25) << s.GetN() << space << t << space2 << sl << space2 << errorSL
	<< space3 << ls << space2 << errorLS << endl;/	cout << endl;
        // Output the correctly spaced line of values into terminal
}
