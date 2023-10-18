#include <iostream>
using namespace std;

// round(x) == floor(x+0.5)

// round(x) = int(x) if (x - int(x)) < (int(x)+1) - x otherwise int(x)+1

int round_number(double x) {
    return (int)(x+0.5);
}

int main() {
    cout << round_number(3.4) << endl;
    cout << round_number(3.9) << endl;

    return 0;
}