#include <bits/stdc++.h>

using namespace std;

long double f(long double x)
{
	//? the func is incorrect, the last coefficient is not correct
    return pow(pow(x,6) - 9.2*pow(x,5) +34.45*pow(x,4)-66.914* pow(x,3)+70.684* pow(x,2) -38.168*x +8.112 + 0.01234*log(x),2);
}

long double golden_section_search(long double a, long double b, long double eps)
{
    long double gr = (sqrt(5.0) + 1.0) / 2.0;
    long double c, d;
    c = b - (b - a) / gr;
    d = a + (b - a) / gr;

    cout<<a<<" "<<b;
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
    long double x_values[100001]; //found by plotting the function
    long double a_values[5], b_values[5];

    for (int i = 0; i < 100001; i++)
    {
        x_values[i] = 0.0001 * i;
    }

    int k = 0;

    for (int i = 1; i < 100001 && k < 5; i++)
    {
        if (f(x_values[i]) < min(f(x_values[i - 1]), f(x_values[i + 1])))
        {
           
            a_values[k] = x_values[i - 1];
            b_values[k] = x_values[i + 1];
            k++;
        }
        
    }
    long double global_min = DBL_MAX,global_min_at;

    for (int i = 0; i < 5; i++)
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
    //? All are global min
    cout<<"Global minimum is : "<< global_min <<" at x = "<<global_min_at <<endl;

    return 0;
    
}
