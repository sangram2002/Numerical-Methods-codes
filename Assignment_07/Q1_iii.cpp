#include <bits/stdc++.h>
using namespace std;

//Program To evaluate a Definite Integral by Gauss Legendre quadrature formula.
//I_3 = int_{0}^{b} (1/sqrt((x^2 - 1)*(b^2 - x^2)) dx ; b=2, 1.1, 1.01, 1.001, 1.0001

//Given Fi=unction of Integration
long double f(long double x, long double b)
{
    long double temp1, temp2, temp3;
    temp1 = pow(b, 2) - pow(x, 2);
    temp2 = pow(x, 2) - 1.0;
    temp3 = temp1 * temp2;
    temp3 = sqrt(temp3);
    temp3 = 1.0 / temp3;
    return temp3;
}

//For Legendre's Polynomial Pn(x)
long double pn(long double a[], int n, int m, long double x)
{
    int i;
    long double p = 0;
    if (m == 0)
    {
        for (i = 0; i <= n; i = i + 2)
        {
            if (x == 0)
                break;
            p += a[i] * pow(x, i);
        }
    }
    else
    {
        for (i = 1; i <= n; i = i + 2)
        {
            p += a[i] * pow(x, i);
        }
    }
    return p;
}

//Derivative of Pn(x)
long double dn(long double a[], int n, int m, long double x)
{
    int i;
    long double p = 0;
    if (m == 0)
    {
        for (i = 0; i <= n; i = i + 2)
        {
            if (x == 0)
                break;
            p += i * a[i] * pow(x, i - 1);
        }
    }
    else
    {
        for (i = 1; i <= n; i = i + 2)
        {
            p += i * a[i] * pow(x, i - 1);
        }
    }
    return p;
}

//Factorial Function
long double factorial_fn(int n)
{
    int i;
    long double f = 1;
    for (i = 2; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

//Main Function
int main()
{
    int n, m, i, N;
    long double c, b_values[5] = {2, 1.1, 1.01, 1.001, 1.0001};
    cout << "\n This Integral is evaluated by Gauss Legendre quadrature formula.\n\n";
    cout << "Enter the value of n for Pn(x)[for example:- 7,10,15 etc.] : \n";
    cin >> n;
    cout << "Enter the lower limit a of integration(For this question please enter 1) : \n";
    cin >> c;
    //? why is all this needed. You can just enter the weights and abscissas
    //? for Gauss-Legendre formula
    //? In any case this integrand has singularity at both ends and this will
    //? not work. You should have used Gauss-Chebyshev formula.

    if (n <= 0)
        return 0;

    long double a[n], b, x, y[n], z[n], w[n], l, v, s, u[n];
    m = n % 2;
    if (m == 0)
    {
        N = n / 2;
    }
    else
    {
        N = (n - 1) / 2;
    }

    for (i = 0; i <= N; i++)
    {
        a[n - 2 * i] = (pow(-1, i) * factorial_fn(2 * n - 2 * i)) / (pow(2, n) * factorial_fn(i) * factorial_fn(n - i) * factorial_fn(n - 2 * i));
    }

    if (m == 0)
    {
        cout << "\nThe Legendre's Polynomial is : ";
        cout << a[0];
        for (i = 2; i <= n; i = i + 2)
            cout << " + (" << setprecision(10) << a[i] << ") X^" << i;
    }
    else
    {
        cout << "\nThe Legendre's Polynomial is : ";
        cout << "(" << a[1] << ") X";
        for (i = 3; i <= n; i = i + 2)
            cout << " + (" << a[i] << ") X^" << i;
    }
    cout << endl;
    //Roots of Pn(x)
    for (i = 0; i < n; i++)
    {
        z[i] = cos(3.14 * (i + 0.75) / (n + 0.5));
        l = z[i];
        do
        {
            s = l - (pn(a, n, m, l) / dn(a, n, m, l));
            v = l;
            l = s;
        } while (fabs(l - v) > 0.0000000000000001);

        y[i] = l;
        w[i] = 2 / ((1 - pow(l, 2)) * (dn(a, n, m, l) * dn(a, n, m, l)));
    }

    cout << "Roots\t\t\t\t"
         << "Weights\n";
    for (i = 0; i < n; i++)
    {
        cout << setprecision(15) << y[i] << "\t\t" << setprecision(15) << w[i] << endl;
    }

    //For different b values
    for (int t = 0; t < 5; t++)
    {
        long double g = 0.0;
        for (i = 0; i < n; i++)
        {
            u[i] = ((b_values[t] - c) * y[i] / 2) + (c + b_values[t]) / 2;
        }

        for (i = 0; i < n; i++)
            g += w[i] * f(u[i], b_values[t]);

        g = g * (b_values[t] - c) / 2;
        cout << "The Value of Integration(I3) for b = " << b_values[t] << " from limit " << c << " to " << b_values[t] << " is = " << setprecision(10) << g << endl;
    }

    return 0;
}
