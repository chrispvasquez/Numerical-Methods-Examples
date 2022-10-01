using namespace std;

#include <iostream>
#include <string>
#include <iomanip>

template <class T>
class Summation {

	private:

	   T m_N;   // Representes the chosen n for the summation.

	public:

	   Summation(){

	      m_N = 0;

	   }
	   // Default Constructor
	   // Initalizes m_N to 0


	   ~Summation(){};
	   //Destructor


	   T CalcTrue();
	/*
	* This function computes thhe true value of the
	* given function.
	*
	* function: CalcTrue
	*
	* return type: T
	*
	* parameters: N/A
	*
	* @author Chris Vasquez
	* @since 9/15/2020
        *
	*/


	   T CalcSmallToLarge();
	/*
        * This function computes the given functions's
        * summation form, starting with the smallest
        * instance of j till the largest instance, n
        *
        * function: CalcSmallToLarge
        *
        * return type: T
        *
        * parameters: N/A
	*
        * @author Chris Vasquez
        * @since 9/15/2020
        *
	*/


	   T CalcLargeToSmall();
	/*
        * This functionm computes the given function's
        * summation form, starting with the largest
        * instance of j, i.e. n, till the smallest
        * instance, i.e. 1
        *
        * function: CalcLargeToSmall
        *
        * return type: T
        *
        * parameters: N/A
        *
        * @author Chris Vasquez
        * @since 9/15/2020
        *
	*/


	   void SetN(T);
	/*
        * This function sets the value of m_N
        * for an object of type Summation
        *
        * function: SetN
        *
        * return type: void
        *
        * parameters:
        *	n	[T]	value of n to evalutate at
        *
        * @author Chris Vasquez
        * @since 9/15/2020
        *
	*/


	   T GetN();
	/*
        * This function gets the value of m_N
        * for an object of type Summation
        *
        * function: GetN
        *
        * return type: T
        *
        * parameters: N/A
        *
        * @author Chris Vasquez
        * @since 9/15/2020
        *
	*/



	   T CalcError(T, T);
	/*
        * This function calculates the error between
        * the true value and the summation approximation
        *
        * function CalcError
        *
        * return type: T
        *
        * parameters:
        *	trueValue	 [T]	The true value of the function
        *
        *	SummationApprox	 [T]	The summation approximation of the function
        *
        * @author Chris Vasquez
        * @since 9/15/2020
        *
	*/
};

/*******************************************************************/
/*******************************************************************/
/*******************************************************************/

template <class T>
T Summation<T>::CalcTrue(){

	T answer = (3.0/4.0) - ((2.0*m_N + 3.0)/(2.0*(m_N + 1.0)*(m_N + 2.0)));
	//Calculates the summation's true value function for given n

	return answer;
}


template <class T>
T Summation<T>::CalcSmallToLarge(){

	T answer = 0; // Initialize counter variable to 0

	for(T j = m_N; j >= 1.0; j--) answer += 1.0/(j*(j + 2.0));
	//Compute summation starting from 1 to given n

	return answer;
}


template <class T>
T Summation<T>::CalcLargeToSmall(){

	T answer = 0; //Initializae counter variable

	for(T j = 1.0; j <= m_N; j++) answer += 1.0/(j*(j + 2.0));
	// Compute the summation starting with given n down until 1

	return answer;
}


template <class T>
void Summation<T>::SetN(T x){

	m_N = x; //Set n to given x
}


template <class T>
T Summation<T>::GetN(){

	return m_N; //Retrieve object's n value
}


template <class T>
T Summation<T>::CalcError(T trueValue, T approx){

	return trueValue - approx; // Subtract trueValue - approx of function
}


template <class T>
void Show(Summation<T> s, T n){

	s.SetN(n); //Set the n for a given value

	string space1;
	string space2;
	string space3;
	string space4;
	string space5;
	// Initialize strings for properly spaced table

	if(10 == n){
			     space1 = "          ";
			     space2 = "          ";
			     space3 = "                         ";
			     space4 = "                          ";
                             space5 = "          ";
	}

	else if(50 == n){
			     space1 = "          ";
                             space2 = "          ";
			     space3 = "                         ";
			     space4 = "                          ";
			     space5 = "          ";
	}

	else if(100 == n){
			     space1 = "         ";
                             space2 = "          ";
			     space3 = "                         ";
                             space4 = "                          ";
                             space5 = "          ";
	}

	else if(500 == n){
			     space1 = "         ";
                             space2 = "          ";
                             space3 = "                         ";
                             space4 = "                          ";
                             space5 = "          ";

	}

	else if(1000 == n){
			     space1 = "        ";
                             space2 = "          ";
                             space3 = "           ";
                             space4 = "           ";
                             space5 = "          ";
	}

	else if(5000 == n){
			     space1 = "        ";
			     space2 = "          ";
                             space3 = "                         ";
                             space4 = "                          ";
                             space5 = "          ";
	}
	// Determine the proper spacing of the table based on
	// the given values of n

	T t = s.CalcTrue();		//Calculate the true value of the function
	T sl = s.CalcSmallToLarge();	//Calculate the approx of function for summation from small j to large j
	T errorSL = s.CalcError(t, sl); //Calculate the error between the true value and the small to large approx
	T ls = s.CalcLargeToSmall();    //Calculate the approx of the function for the summation from large j to small j
	T errorLS = s.CalcError(t, ls); //Calculate the error between the true value and the large to small approx

	cout << setprecision(25) << s.GetN() << space1;
	cout << setprecision(25) << t << space2;
	cout << setprecision(25) << sl << space3;
	cout << setprecision(25) << errorSL << space4;
	cout << setprecision(25) << ls << space5;
	cout << setprecision(25) << errorLS << "\n" << endl;
        // Output the correctly spaced line of values into terminal
}
