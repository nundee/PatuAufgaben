#include <vector>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numbers>
#include <cstdlib>
#include <iostream>
using namespace std;

// For a given double value x 
// calculate the smallest eps such that x+eps!=x
double get_eps(double x) {
    double eps=x;
    while ( (x+eps) != x)
    {
        eps /= 2.0;
    }
    return eps*3;
}

double Parabola(double x) {
    return x*(0.9*x + 1.3)-0.7;
}

double my_abs(double x) {
    return x>=0 ? x : -x;
}

int main() {
    constexpr auto max_precision{std::numeric_limits<long double>::digits10 + 1};
    vector<double> X={0.00001, 0.0001, 0.001, 0.01, 0.1, 1, 100, 1000, 10000, 1.0e10, 1.0e15, 1.0e20, 1.0e100};
    cout << setprecision(max_precision);
    for(auto x : X) {
        cout << x << " -> " << get_eps(x) << endl;
        cout << "P(" << x << ") = " << Parabola(x) << endl;
    }
    cout << my_abs(-12) << endl;
}
