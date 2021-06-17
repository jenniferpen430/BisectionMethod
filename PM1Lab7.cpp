#include <iostream>
#include  <math.h>
using namespace std;

double func(double x){
    double fun;
    double p  = pow(x,3.0);
    fun = p +(x-5);
    return fun;
}

int main (int argc, char *argv[]){

	double tol;
    double left;//a
    double right; //b
    cout << "Please enter a tolerance value and endpoints of an interval: ";
    cin >> tol >> left >> right;

    int nmax = 100;
    int n;
    double c;
    double d;
    if (right  < left){
        cout <<  "improper interval";
    }
    else if ((func(left)  > 0 && func(right) >0) || (func(left) < 0 && func(right)  < 0)){
        cout <<  "no root in this interval";
    }
    else{
        while(n  <= nmax){
            c = (left+right)/2;
            d = (right-left)*2;
            double fc = func(c);
            double fa = func(left);

            if (fc ==  0 ||  d < tol){
                cout << c ;
                break;
            }
            n++;
            if( (fc > 0 && fa > 0) || (fc < 0 && fa < 0)){
                left = c;
            }
            else {
                right = c;
            }
        }
    }


}

