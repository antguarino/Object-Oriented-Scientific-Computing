#include <iostream>
#include <cmath>
#include <complex>
using namespace std;
int main() {

    //Define variables
    double a, b, c;

    //Ask for inputs
    cout <<"a: ";
    cin >> a;
    cout <<"b: ";
    cin >> b;
    cout <<"c: ";
    cin >> c;

    //Define Discriminant
    double disc = (b*b) - (4*a*c);
   
    
    //Test if the discriminant is positive, negative, or 0
    if (disc == 0){
        double x = (-b) / (2*a);
        cout << "The root is {" << x << "}" << endl;
    }    
    else if (disc > 0){
        double x1 = ((-b) + (sqrt(disc))) / (2*a);
        double x2 = ((-b) - (sqrt(disc))) / (2*a);
        cout << "The roots are {" << x1 << "," << x2 << "}" << endl;
    }
    else if (disc < 0){
        complex<double> x1(-b / (2 * a), sqrt(-disc) / (2 * a));
        complex<double> x2(-b / (2 * a), -sqrt(-disc) / (2 * a));
        cout << "The roots are {" << x1 << "," << x2 << "}" << endl;
    }
    else{
        cout << "I dont even know what you did. If you see this, you really messed up" << endl;
    }
}