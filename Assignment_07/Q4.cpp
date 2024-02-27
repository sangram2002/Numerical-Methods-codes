#include <bits/stdc++.h>
using namespace std;

//Integration for the given function using Monte Carlo method

double Function(double x, bool isF)
//Function to integrate
{
    return isF ? exp(x) : exp(x) - 1.0 - x;
}

void MC_Integration_Variance(double a, double b, int n, double Array[], bool isF)
//Function to execute Monte Carlo integration on predefined function
{

    double Sum = 0;
    double Sum_Squared = 0;

    int iter = 0;

    while (iter < n - 1)
    {

        double randNum = a + (float(rand()) / RAND_MAX) * (b - a);

        double Value = Function(randNum, isF);

        Sum += Value;
        Sum_Squared += pow(Value, 2);

        iter++;
    }

    double Result = (b - a) * Sum / n;
    double estimate = Sum / n;

    double expectedSquare = Sum_Squared / n;

    //? why is this divided by n-1?
    double variance = (b - a) * (expectedSquare - pow(estimate, 2))/ (n - 1);

    Array[0] = Result;
    Array[1] = variance;
}

int main()
{

    double a, b, error;
    int n;

    a = 0;
    b = 1;

    double Result_Var[2]; // Result and Variance

    for (int i = 1; i < 10; i++)
    {

        n = pow(4, i);

        MC_Integration_Variance(a, b, n, Result_Var, true);
        error = abs(exp(1.0) - 1.0 - Result_Var[0]);

        printf("Integration of e^x from %.1f to %.1f is %.9f with error %.9f with Variance = %.8f by taking %i points\n",
               a, b, Result_Var[0], error, Result_Var[1], n);
    }

    cout << endl;

    for (int i = 1; i < 10; i++)
    {

	    //? n=4 is too small for Monte-Carlo
        n = pow(4, i);

        MC_Integration_Variance(a, b, n, Result_Var, false);
        error = abs(exp(1.0) - 5.0 / 2.0 - Result_Var[0]);

        printf("Integration of e^x-1-x from %.1f to %.1f is %.9f with error %.9f with Variance = %.8f by taking %i points\n",
               a, b, Result_Var[0], error, Result_Var[1], n);
    }

    cout << endl;
    cout << "The number of function evaluations for the same accuracy should reduce by 0.044/0.242 ≈ 0.182(done in pdf attached)." << endl;
    cout << "But with modified function it requires a little more time so actual gain is little less than expected." << endl;
    return 0;
}
