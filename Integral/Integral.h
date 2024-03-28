#include <cmath>

namespace numerical {

// Create function Integral wich will compute a single value from two vectors
template <typename T1>
double Integral(const std::vector<T1>& x, const std::vector<T1>& y) {
  double sum = 0;
  double dx = (x[1] - x[0]);
  for (size_t i = 1; i < x.size(); i++) {
    sum += (y[i - 1] + y[i]) * dx / 2;
  }
  return sum;
}

template <typename T2>
double Integral(const T2& F, const double& a, const double& b, const int& n) {
  std::vector<double> x(n);
  std::vector<double> y(n);

  double h = (b - a) / (n - 1);
  for (int i = 0; i < n; i++) {
    x.at(i) = i * h + a;
    y.at(i) = F(x.at(i));
  }

  /*
    double area = (F(a)+F(b))/2;
    double sum = 0;
    for (int i = 1; i < n-1; i++) {
      sum += F(i*h+a);
    }
    area += sum;
    */

  return Integral(x, y);
}
}