// Fizz, Buzz, FizzBuzz problem with CRTP
#include<iostream>
#include<string>
using namespace std;

// Actual structure template
template<int impl>
struct FizzBuzzAct
{
    static const int value = 0;
    template<typename T> FizzBuzzAct(T t) { }
};

// End condition of structure template to end the recursion.
template<> struct FizzBuzzAct<0>
{
    static const int value = 1;
    template<typename T> FizzBuzzAct(T t) { cout << t << endl; }
};

// Utilization structure template
template<int N>
struct FizzBuzz : FizzBuzz<N-1> // Each time the N will be decremented recursively and becomes derived to its own until meets the end condtion <0>
{
    FizzBuzz()
    {
        FizzBuzzAct< N % 3 + FizzBuzzAct< N % 15>::value>( to_string(N) + " " + "Fizz");    // FizzBuzzAct<0> only when N % 3 == 0 then calls end condition.
        FizzBuzzAct< N % 5 + FizzBuzzAct< N % 15>::value>( to_string(N) + " " + "Buzz");    // FizzBuzzAct<0> only when N % 5 == 0 then calls end condition.
        FizzBuzzAct< N % 15>( to_string(N) + " " + "FizzBuzz");                             // FizzBuzzAct<0> only when N % 15 == 0 then calls end condition.
        FizzBuzzAct< FizzBuzzAct< N % 3 >::value + FizzBuzzAct< N % 5>::value>(to_string(N));    // FizzBuzzAct<0> only when N is other than above then calls end condition.
                                                                                            // i.e, FizBuzzAct< FizzBuzzActN%3=1>::value (produces value=0) 
                                                                                            // + FizzBuzzAct<FizzBuzzAct<N%5=1>::value (produces value=0)> then wrties(1>) etc.
    }
};

// End condition to end the recursion.
template<> struct FizzBuzz<0> {};

int main()
{
    FizzBuzz<31> fb;    // Test for results.
    return 0;
}
