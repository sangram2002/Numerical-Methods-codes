//to find approximation of a ODE using Trapezoidal rule.
#include <bits/stdc++.h>

using namespace std;

long double function1(long double t, long double y)
{
    return (10 * y + 15 * exp(-5 * t));
}

// Function for Trapezoidal rule
void euler_method(long double t0, long double y, long double h, long double t, long double theoretical_value)
{
    long double temp = 0;

    while (t0 < t)
    {
        temp = y;
	//? this is not trapezoidal rule. That is an implicit method
	//? which needs to be iterated. In this case since the eq is linear
	//? you could have solved it for new y explicitly, but for that
	//? you need to write the iteration explicitly
	//? Here y in the 2nd term should be the new y and you can't overwrite
	//? on it like this
	//? If you had writen the 2nd term with y+h*f(t0,y) it would be the
	//? Runge-Kutta method, then you may get correct result
        y = y + h / 2.0 * (function1(t0, y) + function1(t0 + h, y));
        t0 = t0 + h;
    }

    cout << "Calculated solution at t = "
         << t << " is " << y << " with error = " << y - theoretical_value << endl;
}

int main()
{
    // Initial Values
    long double t0 = 0, lower_limit = 0;
    long double y0 = 1, upper_limit = 10;
    long double h = 1e-4;
    long double theoretical_value;

    long double t_values[200];

    cout << "For y(0)=1 and 0 ≤ t ≤ 10:\n\n";

    for (int j = 0; j <= 100; j++)
    {
        t_values[j] = lower_limit + j * 0.1;
        theoretical_value = 2.0 * exp(10 * t_values[j]) - exp(-5 * t_values[j]);
        euler_method(t0, y0, h, t_values[j], theoretical_value);
    }
    y0 = -1;
    cout << "_______________________________________________________________________" << endl;
    cout << "For y(0)= -1 and 0 ≤ t ≤ 10:\n\n";
    for (int j = 0; j <= 100; j++)
    {
        theoretical_value = -exp(-5 * t_values[j]);
        euler_method(t0, y0, h, t_values[j], theoretical_value);
    }
    //The solution is unstable so the error is huge
    return 0;
}
