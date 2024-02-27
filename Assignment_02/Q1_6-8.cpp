#include <bits/stdc++.h>
using namespace std;

double function_6(long double x)
{
    return log(x) * pow(x, 0.01);
}
double function_7(long double x)
{
    return x * sqrt(1 + pow(x, 2)) - pow(x, 2);
}
double function_8(long double x)
{
    return cosh(x) / sinh(x);
}

//optimum value for x is estimated for each problems.
//Code for Q1(vi)
int main()
{
    int i = 0;
    long double x = 1.0;
    long double prev = 100.0, cur = 1.0;
    while (abs(cur - prev) >= 1e-30)
    {
        prev = cur;
        cur = function_6(x);
        x = x / 2;
        i++;
    }
    cout << "log(x)*pow(x,0.01) for x tends to 0 = " << cur << endl;
    cout << "No. of iterations: " << i << endl;

    //Code for Q1 (vii)

    i = 0;
    x = 1.0;
    prev = 100.0, cur = 1.0;
    while (abs(cur - prev) >= 1e-30)
    {
        prev = cur;
        cur = function_7(x);
        x = x * 2;
        i++;
    }
    cout << "x*sqrt(1+pow(x,2))-pow(x,2) for x tends to ∞ = " << cur << endl;
    cout << "No. of iterations: " << i << endl;

    //Code for Q1 (viii)

    i = 0;
    x = 0.1;
    prev = 100.0, cur = 1.0;
    while (abs(cur - prev) >= 1e-30)
    {
        prev = cur;
        cur = function_8(x);
        x = x * 2;
        i++;
    }
    cout << "cosh(x)/sinh(x) for x tends to ∞ = " << cur << endl;
    cout << "No. of iterations: " << i << endl;

    return 0;
}
