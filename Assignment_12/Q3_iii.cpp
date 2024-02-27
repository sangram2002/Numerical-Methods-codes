//to find approximation of a ODE using Trapezoidal rule.
#include <bits/stdc++.h>

using namespace std;

long double function1(long double t, long double y)
{
	return (10 * y + 15 * exp(-5 * t));
}

// Function for Trapezoidal rule
void euler_method(long double t0, long double y, long double h, long double t)
{
	long double temp = 0;

	while (t0 < t)
	{
		temp = y;
		y = y + h / 2.0 * (function1(t0, y) + function1(t0 + h, y));
		t0 = t0 + h;
	}

	long double theoretical_value = exp(10 * t - 150.0) - exp(-5 * t);

	cout << "Calculated solution at t = "
		 << t << " is " << y << " with error = " << y - theoretical_value << endl;
}

int main()
{
	// Initial Values
	long double t0 = 10, lower_limit = 0;
	long double y0 = 0, upper_limit = 10;
	//? you are calculating the solution in forward direction, while
	//? the Q is for starting from t=10 and going backward, with
	//? negative h
	long double h = 1e-4;

	long double t_values[200];

	for (int j = 0; j <= 100; j++)
	{
		t_values[j] = lower_limit + j * 0.1;
		euler_method(t0, y0, h, t_values[j]);
	}

	return 0;
}
