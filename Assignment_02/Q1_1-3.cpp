#include <bits/stdc++.h>
using namespace std;

double function_1(long double x)
{
    return log(x) / pow(x, 0.01);
}
double function_2(long double x)
{
    return (exp(x) - 1) / x;
}
double function_3(long double x)
{
    return (sin(x) - sinh(x)) / pow(x, 3);
}

//optimum value for x is estimated for each problems.
//Code for Q1(i)
int main()
{
    int i = 0;
    long double x = 1.0;
    long double prev = 100.0, cur = 1.0;
    while (abs(cur - prev) >= 1e-30)
    {
        prev = cur;
        cur = function_1(x);
        x = x * 2;
        i++;
    }
    cout << "(log(x)/pow(x,0.01) for x tends to ∞ = " << cur << endl;
    cout << "No. of iterations: " << i << endl;

    //Code for Q1 (ii)

    i = 0;
    x = 1.0;
    prev = 100.0, cur = 1.0;
    //? this is too stringent condition
    while (abs(cur - prev) >= 1e-30)
    {
        prev = cur;
        cur = function_2(x);
        x = x / 4;
        i++;
    }
    cout << "(exp(x)-1)/x for x tends to 0 = " << cur << endl;
    //? you need to give the value of x
    cout << "No. of iterations: " << i << endl;

    //Code for Q1 (iii)

    i = 0;
    x = 0.1;
    prev = 100.0, cur = 1.0;
    while (abs(cur - prev) >= 1e-30)
    {
        prev = cur;
        cur = function_3(x);
        x = x / 2;
        i++;
    }
    cout << "(sin(x)-sinh(x))/pow(x,3) for x tends to 0 = " << cur << endl;
    cout << "No. of iterations: " << i << endl;

    return 0;
}
