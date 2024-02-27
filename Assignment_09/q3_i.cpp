#include <bits/stdc++.h>

using namespace std;

double f(double n, double x)
{
    return pow(x - n * sin(x), 2);
}

double golden_section_search(double a, double b, double eps, double n)
{
    double gr = (sqrt(5.0) + 1.0) / 2.0;
    double c, d;
    c = b - (b - a) / gr;
    d = a + (b - a) / gr;

    while (abs(b - a) >= 1e-7)
    {

        if (f(n, c) < f(n, d))
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
    int t;
    cout<<" \n The function has infinite number of local minimas. I have calculated local minimas between 0 and 30: "<<endl;
    for (t = 0; t < 3; t++)
    {
        double n_values[3] = {10, 20, 20.3959};
        cout << endl;
        cout << "For a = " << n_values[t] << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "All local minimas and global minima of f(x):\n"
             << endl;
        double x_values[3001]; //found by plotting the function
        double a_values[1000], b_values[1000];

        for (int i = 0; i < 3001; i++)
        {
            x_values[i] = 0.01 * i;
        }

        int k = 0;

        for (int i = 0; i < 3001; i++)
        {
		//? again you are exceeding the dimeinsion
            if (f(n_values[t], x_values[i]) < min(f(n_values[t], x_values[i - 1]), f(n_values[t], x_values[i + 1])))
            {

                a_values[k] = x_values[i - 1];
                b_values[k] = x_values[i + 1];
                k++;
            }
        }
        double global_min = DBL_MAX, global_min_at;

        for (int i = 0; i < k; i++)
        {
            double x_min = golden_section_search(a_values[i], b_values[i], 1e-7, n_values[t]);

            if (f(n_values[t], x_min) < global_min)
            {
                global_min = f(n_values[t], x_min);
                global_min_at = x_min;
            }

            cout << setprecision(7) << "minimum value = " << f(n_values[t], x_min) << " at x = " << x_min << "\n"
                 << endl;
        }
	//? there are many global min
	//? one global min at 20.368 is missed for a=20.3959
        cout << "Global minimum is :" << global_min << " at x = " << global_min_at << endl;
    }

    return 0;
}
