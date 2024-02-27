//to find approximation of a ODE using Trapezoidal rule.
#include <bits/stdc++.h>

using namespace std;

long double function1(long double t, long double y, long double lambda_values)
{
	return (lambda_values * (y - pow(t, 3)) + 3 * t * t);
}

// Function for Trapezoidal rule
void euler_method(long double t0, long double y, long double h, long double t, long double lambda_values)
{
	long double temp = 0;

	while (t0 < t)
	{
		temp = y;
		y = y + h / 2.0 * (function1(t0, y, lambda_values) + function1(t0 + h, y, lambda_values));
		t0 = t0 + h;
	}

	long double theoretical_value = pow(t, 3);

	cout << "Calculated solution at t = "
		 << t << " is " << y << " with error = " << y - theoretical_value << endl;
}

int main()
{
	// Initial Values
	long double t0 = 0, lower_limit = 0;
	long double y0 = 0, upper_limit = 10;
	//? you are using very small h to compensate for error in integration
	//? function
	long double h = 1e-4;
	long double lambda_values[4] = {+3, -3, -20, -100};

	long double t_values[50];

	for (int i = 0; i < 4; i++)
	{
		cout << "For λ = " << lambda_values[i] << endl;

		cout << "_______________________________________________________________________" << endl;
		for (int j = 0; j <= 20; j++)
		{
			t_values[j] = lower_limit + j;
			euler_method(t0, y0, h, t_values[j], lambda_values[i]);
		}
	}
	cout << "The general solution of the differential equation can be written as Ce^(λt) + t^3 , where C is an arbitrary constant. \nthe initial condition of the problem gives C = 0 and the exponential term is suppressed. \nInitially the solution is closer, but as integration proceeds the error builds up exponentially." << endl;

	return 0;
}
