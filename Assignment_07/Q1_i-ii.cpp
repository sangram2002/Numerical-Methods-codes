#include <bits/stdc++.h>
using namespace std;

//function for given integration-1
//? these are singular or nearly singular integral. They should not
//? be evaluated using simpson's rule. You have to treat the singularity.
//? I_2 also has a large roundoff error near x=0, so in that region the
//? integrand should be rewritten
double f1(double n)
{
    double a, b;
    a = 1;
    b = 0;
    double h, f, x, sum, temp1, temp2, temp3;
    sum = 0.0;
    h = (a - b) / n;
    int k = (int)n;

    for (int i = 0; i <= k; i++)
    {
        x = b + (i * h);
        temp1 = exp(-5 * x);
        temp2 = cos(10 * x);
        temp3 = sqrt(x);
        f = (temp1 * temp2) / temp3;
        if(isinf(f)||isnan(f))
            f = 0.0;
        if (i == 0 || i == k)
        {

            sum = sum + f;
        }
        else if (i % 2 != 0)
        {
            f = f * 4.0;
            sum = sum + f;
        }
        else
        {
            f = f * 2.0;
            sum = sum + f;
        }
    }
    sum = h * sum / 3.0;
    return sum;
}

//function for given integration-2

double f2(double b, double n)
{
    double a, sum, h, x, f, temp1;
    a = 1;
    h = (a - b) / n;
    sum = 0.0;
    int k = (int)n;

    for (int i = 0; i <= k; i++)
    {
        x = b + (i * h);
        temp1 = x - sin(x);
        f = 1 / temp1;
        if(isinf(f)||isnan(f))
            f = 0.0;
        if (i == 0 || i == k)
        {

            sum = sum + f;
        }
        else if (i % 2 != 0)
        {
            f = f * 4.0;
            sum = sum + f;
        }
        else
        {
            f = f * 2.0;
            sum = sum + f;
        }
    }
    sum = h * sum / 3.0;
    return sum;
}

//main program starts
int main()
{

    double n, temp;

    //(a) int_{0}^{1} (e^(-5x)cos(10x))/sqrt(x) dx
    n = 1e7;
    cout << "(a) I_1 = int_{0}^{1} (e^(-5x)cos(10x))/sqrt(x) dx " << endl;
    cout << "    no. of points \t\t Answer " << endl;
    temp = 0.0;
    while (abs(temp - f1(n)) >= 1e-3)
    {
        cout << "       " << n << "                " << f1(n) << endl;
        temp = f1(n);
        n = n * 2;
    }

    cout << endl;
    cout << endl;

    //(b) int_{a}^{1} 1/(x-sin(x)) dx ; a=10^-1, 10^-3, 10^-6, 10^-9
    double l[4] = {0.1, 0.001, 1e-6, 1e-9};
    n = 1e3;
    cout << "(b) I_2 = int_{a}^{1} 1/(x-sin(x)) dx ; a=10^-1, 10^-3, 10^-6, 10^-9" << endl;
    cout << "    no. of points          Answer(a=10^-1) " << endl;
    cout << "--------------------------------------------" << endl;

    temp = 0.0;
    while (abs(temp - f2(l[0], n)) >= 1e-5)
    {
        cout << "       " << n << "                " << f2(l[0], n) << endl;
        temp = f2(l[0], n);
        n = n * 2;
    }

    cout << endl;
    cout << "    no. of points          Answer(a=10^-3) " << endl;
    cout << "--------------------------------------------" << endl;
    temp = 0.0;
    while (abs(temp - f2(l[1], n)) >= 0.01)
    {
        cout << "       " << n << "                " << f2(l[1], n) << endl;
        temp = f2(l[1], n);
        n = n * 2;
    }

    cout << endl;
    cout << "    no. of points          Answer(a=10^-6) " << endl;
    cout << "--------------------------------------------" << endl;
    n = 1e4;
    temp = 0.0;
    while (abs(temp - f2(l[2], n)) >= 1e10)
    {
        cout << "       " << n << "                " << f2(l[2], n) << endl;
        temp = f2(l[2], n);
        n = n * 2;
    }

    cout << endl;
    cout << "    no. of points          Answer(a=10^-9) " << endl;
    cout << "--------------------------------------------" << endl;
    n = 1e6;
    temp = 0.0;

    for (int z = 1; z <= 7; z++)
    {

        cout << "       " << n << "                " << f2(l[3], n) << endl;
        temp = f2(l[3], n);
        n = n * 2;
    }

    cout << endl;

    return 0;
}
