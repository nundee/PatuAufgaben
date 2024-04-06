
#include <iostream>

struct A {
    int a;
    //A operator+(A y);
    A operator-() {
        return {-a};
    };

    A& operator++() {
        ++a;
        return *this;
    };

    A& operator++(int) {
        a++;
        return *this;
    };

    operator bool()
    {
        return a!=0;
    }

    operator double()
    {
        return (double)a;
    }

};

A operator +(A x, A y)
{

}

std::istream& operator >>(std::istream& in, A& x)
{
    in >> x.a;
    if(x.a<0)
        in.setstate(std::ios_base::failbit);
    return in;
}

std::ostream& operator <<(std::ostream& out, const A& x)
{
    out << x.a;
    return out;
}



int main() {
    int i = (int)2.2;
    A a1, a2;
    A aa=a1+a2;
    aa = -a1; 
    ++aa;
    aa++;
    if(aa) {}
    if(!aa) {}
    double xx = (double)a1;

    (std::cin >> a2) >> a1;
    if(std::cin) {}

    std::cout << a1 << a2;
    A c;
    //bool nok = !(std::cin >> c);

    !(std::cin >> c); // = std::cin

}