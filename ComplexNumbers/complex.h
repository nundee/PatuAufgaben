#pragma once

#include <iostream>
#include <cmath>

// TODO: Write structure declaration/operators forward declarations here.

struct  Complex
{
    double 
        re, //real part
        im; // imaginary part
    Complex operator -();
};

// operator overloading
// see https://en.cppreference.com/w/cpp/language/operators
// and https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading#4421719

Complex operator +(const Complex& c1, const Complex& c2);
Complex operator -(const Complex& c1, const Complex& c2);
Complex operator *(const Complex& c1, const Complex& c2);
Complex operator /(const Complex& c1, const Complex& c2);
bool operator ==(const Complex& c1, const Complex& c2);
bool operator !=(const Complex& c1, const Complex& c2);


// reads a complex number from input
// returns a boolean to indicate whether the input was valid or not
bool read_input(std::istream& in, Complex& a);

// input operator
// sets fail bit if input is not a valid complex number
std::istream& operator>>(std::istream& in, Complex& a);

// output operator
std::ostream& operator<<(std::ostream& out, Complex& a);
