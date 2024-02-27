#include <bits/stdc++.h>

using namespace std;

double f(double x)
{
    return x * sin(x);
}

double golden_section_search(double a, double b, double eps)
{
    double gr = (sqrt(5.0) + 1.0) / 2.0;
    double c, d;
    c = b - (b - a) / gr;
    d = a + (b - a) / gr;

    while (abs(b - a) >= 1e-7)
    {

        if (f(c) < f(d))
            b = d;
        else
            a = c;

        c = b - (b - a) / gr;
        d = a + (b - a) / gr;
    }

    return (b + a) / 2;
}

int main()
{
    cout<<"First Five positive minimisers and global minima of f(x):\n"<<endl;
    double x_values[5001]; //found by plotting the function
    double a_values[5], b_values[5];

    for (int i = 0; i < 5001; i++)
    {
        x_values[i] = 0.0 + 0.01 * i;
    }

    int k = 0;

    for (int i = 0; i < 5001 && k < 5; i++)
    {
        if (f(x_values[i]) < min(f(x_values[i - 1]), f(x_values[i + 1])))
        {

            a_values[k] = x_values[i - 1];
            b_values[k] = x_values[i + 1];
            k++;
        }
    }
    double global_min = DBL_MAX,global_min_at;

    for (int i = 0; i < 5; i++)
    {
        double x_min = golden_section_search(a_values[i], b_values[i], 1e-7);

        if (f(x_min) < global_min)
        {
            global_min = f(x_min);
            global_min_at=x_min;
        }

        cout << setprecision(7) << "minimum value = " << f(x_min)  << " at x = " << x_min << "\n"
             << endl;
    }
    //? there is no global min for this func
    cout<<"Global minimum is :"<< global_min <<" at x = "<<global_min_at <<endl;
    return 0;
}
