#include "complex.h"
#include <limits>

bool read_input(std::istream &in, Complex &a)
{
  unsigned char c;
  if (!(in >> c) || c != '['
      || !(in >> a.re) 
      || !(in >> c) || c != ',' 
      || !(in >> a.im) 
      || !(in >> c) || c != ']')
    return false;
  else
    return true;
}

std::istream &operator>>(std::istream &in, Complex &a)
{
  if (!read_input(in, a))
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}
std::ostream &operator<<(std::ostream &out, Complex &a)
{
  return out << '[' << a.re << ',' << a.im << ']';
}

// TODO: Write all the operators and functions implementations here.
Complex Complex::operator-()
{
  return {-re, -im};
}

Complex operator+(const Complex &c1, const Complex &c2)
{
  return {c1.re + c2.re, c1.im + c2.im};
}
Complex operator-(const Complex &c1, const Complex &c2)
{
  return {c1.re - c2.re, c1.im - c2.im};
}

Complex operator*(const Complex &c1, const Complex &c2)
{
  return
  {
      c1.re *c2.re - c1.im *c2.im,
      c1.im *c2.re + c1.re *c2.im
  };
}

Complex operator/(const Complex &c1, const Complex &c2)
{
  double div, t;
  if (std::abs(c2.re) >= std::abs(c2.im))
  {
    t = c2.im / c2.re;
    div = c2.re + c2.im * t;
    return {
        (c1.re + c1.im * t) / div,
        (c1.im - c1.re * t) / div};
  }
  else
  {
    t = c2.re / c2.im;
    div = c2.re * t + c2.im;
    return {
        (c1.re * t + c1.im) / div,
        (c1.im * t - c1.re) / div};
  }
}

bool almostEqual(double x, double y)                         
{
    constexpr double maxRelDiff = std::numeric_limits<double>::epsilon();
    // Calculate the difference.
    double diff = std::abs(x - y);
    x = std::abs(x);
    y = std::abs(y);
    double largest = (y > x) ? y : x;

    if (diff <= largest * maxRelDiff)
        return true;
    return false;
}

bool operator==(const Complex &c1, const Complex &c2)
{
  return almostEqual(c1.re, c2.re) && almostEqual(c1.im, c2.im);
}

bool operator!=(const Complex &c1, const Complex &c2)
{
  return !(c1==c2);
}
