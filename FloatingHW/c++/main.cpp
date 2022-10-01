// Chris Vasquez

using namespace std;

#include <iostream>

template <class T>
class direct {

	private:
	   T total;

	public:

	   direct(T x){
	     total = (x*x*x*x*x) + 0.9*(x*x*x*x) - 1.62*(x*x*x) - 1.458*(x*x) + 0.6561*x + 0.59049;
	   }

	   T get_direct(){
	     return total;
	   }
};

template <class T>
class nested {

	private:
	   T total;

	public:

	   nested(T x){
             total = 0.59049 + x*(0.6561 + x*(-1.458 + x*(-1.62 + x*(0.9 + x))));
	   }

	   T get_nested(){
	     return total;
	   }
};



int main(){

 	double x = -0.7;

	direct<double>* a = new direct<double>(x);
	nested<double>* b = new nested<double>(x);

	double dVal = a->get_direct();
	double nVal = b->get_nested();

	double noise = dVal - nVal;

	cout << "Direct Calculation: " << dVal << endl;
	cout << "Nested Calculation: " << nVal << endl;
	cout << "Composite of the Noise : " << noise << endl;
	return 0;
}
