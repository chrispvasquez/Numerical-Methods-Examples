using namespace std;

#include <iostream>
#include <iomanip>

double equation(double x){

	return (x*x*x) + 4.0*(x*x) - 10.0;
}

double bisect(double a, double b, double E){

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double c = (a+b)/2;

	cout << "c = " << c << endl;

	cout << "b-c = " << b-c << endl;

        if((b - c) <= E)	return  c;

        else if((b - c) > E){

	    double functionB = equation(b);
	    double functionC = equation(c);

	    cout << "f(b) = " << functionB << endl;
	    cout << "f(c) = " << functionC << endl;

	    if(functionB * functionC <= 0){

	       cout << "a = c\n" << endl;
	       return bisect(c, b, E);
	    }

	    else {
	       cout << "b = c\n" << endl;
	       return bisect(a, c, E);
	    }
	}

	else
	  cout << "ERROR" << endl;
	  return 0;
}

int main(){

	double a = 1.0;

	double b = 2.0;

	double c = (1.0/2.0)*(a-b);

	double E = 0.0001;

	double root = bisect(a, b, E);

	cout << "The Root is: " << setprecision(9) << root << endl;

	return 0;

}
