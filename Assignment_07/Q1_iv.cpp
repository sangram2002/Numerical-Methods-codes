
#include <bits/stdc++.h>
using namespace std;

//To Find the integral by trapezoidal rule and extrapolation

//To calculate the extrapolation table
//? This integral has a very strong singularity and none of these methods
//? will work. You should have used extrapolation method with exponents
// 0.01,1.01,2.01, etc. then it would work.
void Make_Extrapolation_Table(double Ep_matrix[10][10])
{
    int n = 10;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            Ep_matrix[j][i] = ((pow(4, i) * Ep_matrix[j][i - 1]) - Ep_matrix[j - 1][i - 1]) / (pow(4, i) - 1);
        }
    }
}

double f4(double n)
{
    double a, b;
    a = 1;
    b = 0;
    double h, f, x, s, temp1, temp2;
    s = 0.0;
    h = (a - b) / n;
    int k = (int)n;

    for (int i = 0; i <= k; i++)
    {
        x = b + (i * h);
        temp1 = exp(x);
        temp2 = 100 * pow(x, 0.99);
        f = temp1 / temp2;
        if (isinf(f))
            f = 0.0;
        if (i == 0 || i == k)
        {
            f = f / 2.0;
            s = s + f;
        }
        else
        {
            s = s + f;
        }
    }
    s = h * s;
    return s;
}

int main()
{

    double Ep_matrix[10][10], h, h_values_1[10];

    //To find int_{0}^{1} (e^(x)/100*x^0.99) dx
    cout.precision(7); //setting precision for all output
    cout.setf(ios::fixed);
    // only using trapezoidal rule
    int n = 1e4;
    cout << "int_{0}^{1} (e^(x)/100*x^0.99) calculated only using trapezoidal rule:" << endl;
    cout << "    no. of points          Answer " << endl;
    for (int z = 1; z <= 5; z++)
    {
        cout << "       " << n << "                " << f4(n) << endl;
        n = n * 5;
    }
    cout << endl;
    cout << endl;

    n = 10;
    h = 1e4;

    for (int i = 0; i < n; i++)
    {
        Ep_matrix[i][0] = f4(h);
        h_values_1[i] = h;
        h = h * 2.0;
    }

    Make_Extrapolation_Table(Ep_matrix);

    //To print Extrapolation Table

    cout << endl;
    cout << "int_{0}^{1} (e^(x)/100*x^0.99) calculated using Richardson's extrapolation:" << endl;
    cout << "________________________________________________________________________________________________________" << endl;
    cout << "    h            T0        T1        T2        ......" << endl;
    cout << "________________________________________________________________________________________________________" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << h_values_1[i] << "    ";
        for (int j = 0; j <= i; j++)
        {
            cout << Ep_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
