// Static Polymorphosm in C++ : Factorial (CRTP: Curiously Recursively Template Pattern )

#include<iostream>
using namespace std;

// Template class with INT static parameter type
template<int NUM>
class Factorial 
{
    public:
        static const long long factorial = NUM*Factorial<NUM-1>::factorial ;    // call same class with one number less each time
};

// End condition/value (decide the depth for completion) class with const value 1
template<> class Factorial<1>
{
    public:
        static const long long factorial = 1;  // End value at end condition
};

int main()
{
    Factorial<5> f; // Declare object eith constant number
    cout << f.factorial << endl;
}