//to find approximation of a ODE using euler rule.
#include <bits/stdc++.h>

using namespace std;

long double function1(long double y)
{
    return (-1.0 * y * y);
}

// Function for euler rule
void euler_method(long double t0, long double y, long double h, long double t)
{
    long double temp = 0;

    while (t0 < t)
    {
        temp = y;
        y = y + h * (function1(y));
        t0 = t0 + h;
    }
    long double theoretical_value = 1.0 / (t + 1);

    cout << "Calculated solution at t = "
         << t << " is " << y << " with error = " << y - theoretical_value << endl;
}

int main()
{
    // Initial Values
    long double t0 = 0, lower_limit = 0;
    long double y0 = 1, upper_limit = 10;
    long double h = 1e-4;

    cout << setprecision(7) << fixed;
    long double t_values[200];

    for (int j = 0; j <= 100; j++)
    {
        t_values[j] = lower_limit + j * 0.1;
        euler_method(t0, y0, h, t_values[j]);
    }

    return 0;
}
