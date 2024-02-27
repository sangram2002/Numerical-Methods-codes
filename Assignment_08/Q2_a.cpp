// Bisection Method to find roots of a equation

#include <bits/stdc++.h>
using namespace std;

//Integration
double f(double n_value, double x)
{
    double b, a;
    b = 100;
    a = 0;
    double h, f, t, sum,sum_prev, temp1, temp2, temp3;
    int n = 1e3;
    

    //converging condition check
    sum_prev = 0.0,sum = 1.0;
    while (abs(sum_prev - sum) >= 1e-5)
    {
        sum_prev = sum;
        sum = 0.0;
        h = (b - a) / n;
        int k = (int)n;

        for (int i = 0; i <= k; i++)
        {
            t = a + (i * h);
            temp1 = pow(t, 2);
            temp2 = 1.0 + exp(pow((pow(t, 2) + 1), 1.0 / 2.0) - x);

            f = temp1 / temp2;
            if (isinf(f) || isnan(f))
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
        
        n = n * 2;
    }

    return sum - n_value;
}

// Bisection Method
void Bisection_method(int n_value, double x0, double x1)
{

    double midpt = x0;

    while ((x1 - x0) >= 1e-5)
    {
        midpt = (x0 + x1) / 2.0;

        // if middle point is a root then break
        double f_value = f(n_value, midpt);
        if (f_value == 0.0)
            break;
        else if (f_value * f(n_value, x0) < 0)
            x1 = midpt;
        else
            x0 = midpt;
    }

    cout << setprecision(7) << "is root  = " << midpt << "\n"
         << endl;
}

int main()
{
    cout << "Solve the following nonlinear equation to find the chemical potential  for a Fermion of mass m \n from the number density n:(correct upto 7 significant figures)\n"<< endl;
    //? How did you get these limits? The limits for 0.001 are not correct
    double x0[3] = {-8, -1.0, 14}, x1[3] = {-7.4, 0.0, 15};
    double n_values[3] = {0.001, 1, 1000};

    for (int i = 0; i < 3; i++)
    {
        cout << "For n=" << n_values[i] << endl;

        Bisection_method(n_values[i], x0[i], x1[i]);
    }

    return 0;
}
