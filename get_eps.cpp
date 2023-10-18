#include <vector>
#include <iostream>

double get_eps(double x) {
    double eps=x;
    while ( (x+eps) > x)
    {
        eps /= 2.0;
    }
    return eps*3;
}


int main() {
    std::vector<double> X={0.1, 1, 100, 1000, 10000, 5e10, 5e15, 5e20, 5e100};
    for(auto x : X)
        std::cout << x << " -> " << get_eps(x) << std::endl;

}
