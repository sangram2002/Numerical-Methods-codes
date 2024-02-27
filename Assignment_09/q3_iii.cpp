#include <bits/stdc++.h>

using namespace std;

long double f(long double x)
{
    return pow(x,6) - 36*pow(x,5) +450*pow(x,4)-2400* pow(x,3)+5400* pow(x,2) -4320*x +720.0;
}

long double golden_section_search(long double a, long double b, long double eps)
{
    long double gr = (sqrt(5.0) + 1.0) / 2.0;
    long double c, d;
    c = b - (b - a) / gr;
    d = a + (b - a) / gr;

    while (abs(b - a) >= eps)
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
    cout<<"All local minimas and global minima of f(x):\n"<<endl;
    long double x_values[50001]; //found by plotting the function
    long double a_values[3], b_values[3];

    for (int i = 0; i < 50001; i++)
    {
        x_values[i] = 0.001 * i;
    }

    int k = 0;

    for (int i = 1; i < 50001 && k < 3; i++)
    {
        if (f(x_values[i]) < min(f(x_values[i - 1]), f(x_values[i + 1])))
        {
           
            a_values[k] = x_values[i - 1];
            b_values[k] = x_values[i + 1];
            k++;
        }
        
    }
    long double global_min = DBL_MAX,global_min_at;

    for (int i = 0; i < 3; i++)
    {

        long double x_min = golden_section_search(a_values[i], b_values[i], 1e-7);

        if (f(x_min) < global_min)
        {
            global_min = f(x_min);
            global_min_at=x_min;
        }

        cout << setprecision(7) << "minimum value = " << f(x_min)  << " at x = " << x_min << "\n"
             << endl;
    }
    cout<<"Global minimum is : "<< global_min <<" at x = "<<global_min_at <<endl;

    return 0;
    
}