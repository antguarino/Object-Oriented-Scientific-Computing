#include <iostream>
#include <vector>
#include <cmath>

#include "imgs/numerical/integral/Integral.h"

using namespace std;

// Create function F
double F(const double& x) { return cos(x); };

int main() {
  // Define variables a, b, and n
  const double a = 0;
  const double b = 1.570796;
  const int n = 10;

  // Only putput 7 decimal places
  cout.precision(7);

  // Output variable values
  cout << "For the defined function ..." << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "n: " << n << endl;

  // Create vectors x and y of length n
  vector<double> x(n);
  vector<double> y(n);

  // Compute h
  double h = (b - a) / (n - 1);
  for (int i = 0; i < n; i++) {
    x.at(i) = i * h + a;
    y.at(i) = F(x.at(i));
  }

  // Creates a lambda function to calculate the cos(x)
  auto lambda_function = [](const double& x) { return cos(x); };

  // Output the areas using the three different methods.
  cout << "Area = " << numerical::Integral(x, y) << " (using vector interface)"
       << endl;
  cout << "Area = " << numerical::Integral(F, a, b, n)
            << " (using function/limits/number of points interface)"
            << endl;
  
  cout << "Area = "
            << numerical::Integral(lambda_function, a, b, n)
            << " (using lambda function/limits/number of points interface)"
            << endl;
}