
#include <bits/stdc++.h>

using namespace std;

double f(double x, int n)
{
    return acos(x*exp(-1*x))+2*n*M_PI - exp(x)*sin(acos(x*exp(-1*x)));
}

// Bisection Method
void Bisection_method(double x0, double x1, int n)
{

    double midpt = x0;
    while (abs(x1 - x0) >= 1e-7)
    {
        midpt = (x0 + x1) / 2;

        // if middle point is a root then break
        if (f(midpt, n) == 0.0)
            break;
        else if (f(midpt, n) * f(x0,n) < 0)
            x1 = midpt;
        else
            x0 = midpt;
    }
    double y = acos(midpt*exp(-1*midpt))+2*n*M_PI;
    cout << setprecision(7) << "root of the form x+iy (n=" << n << ") : ( x= " << midpt << " ,y= " << y << " )\n"
         << endl;
}

int main()
{

    double x_values[2001];
    double x0[5], x1[5];
    int n_values[5] = {0, 1, 2, 3, 4};

    for (int i = 0; i < 2001; i++)
    {
        x_values[i] = -10.0 + 0.01 * i;
    }

    int k = 0;
    for (int z = 0; z < 5; z++)
    {
        for (int i = 0; i < 2001; i++)
        {
            if (f(x_values[i], n_values[z]) * f(x_values[i + 1], n_values[z]) <= 0)
            {

                x0[k] = x_values[i];
		//? the dimensions are exceeded for i=2000, i+1 doesn't exist
		//? That was giving wrong value of x.
                x1[k] = x_values[i + 1];
                k++;
            }
        }
    }

    cout << endl;
    cout << " All complex zeros of e^z=z with |x| < 10 and |y| < 10 by Eliminating y and solving for x"<<endl;

    //? you are assuming that there is exactly 1 root for each n
    //? you have not stored the n_value for each root located.
    for (int i = 0; i < 5; i++)
    {
        cout << "  In the interval of x (" << x0[i] << ", " << x1[i] << ") " << endl;
        Bisection_method(x0[i], x1[i], n_values[i]);
    }
    cout<<"For n=2,3,4.... the value of y is coming >10 which we dont require So, We consider only n=0 and 1 i.e. root(1) and root(2) of above  "<<endl;
    return 0;
}
