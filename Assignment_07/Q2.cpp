#include <bits/stdc++.h>
using namespace std;

// To Find the sum of the following series by using the Euler-Maclaurin formula

// Factorial of n(n!)
long double factorial_fn(long double n)
{
    long double temp = 1;
    for (long double i = 2; i <= n; i++)
        temp = temp * i;
    return temp;
}

//Combination function
long double Combination_nCr(long double n, long double r)
{
    return factorial_fn(n) / (factorial_fn(r) * factorial_fn(n - r));
}

// To Find the sum of the following series by using the Euler-Maclaurin formula
//S_n =∑1/i from i=1 to n for n=200, 12495, 2^44; 10^100; 10^(10^10)

int main()
{
    int n = 9;
    long double EULER_CONSTANT = 0.577215664901532860606512090082;
    vector<long double> b(n + 2, 0);
    //? why are you calculating b[n]. You can use the known values
    //? this whole part is similar to that from Arnab. Same mistakes too.
    b[1] = 1;
    b[2] = 0.5;
    for (int m = 2; m < n + 1; m++)
    {
        for (int k = 0; k < m + 1; k++)
        {
            for (int a = 0; a < k + 1; a++)
            {
                b[m + 1] += (pow(-1.0, a)) * Combination_nCr(k, a) * (pow(a, m)) / (k + 1.0);
            }
        }
    }
    long double n_values_123[3] = {200, 12495, pow(2, 44)};
    for (int z = 0; z < 3; z++)
    {
        long long temp1 = n_values_123[z];
        long double sum = log(temp1) + (1 + 1.0 / temp1) / 2;
        long double Gamma = (1 + 1.0 / temp1) / 2;
	//? only even B_m are needed.
	//? fact(j-2)/fact(j-1)=1/(j-1.)
	//? You need to sum the first few terms explicitly and then apply the
	//? formula. Now the series is divergent and the best value if for j=3
        for (int j = 3; j <= 10; j++)
        {
            if (isinf(pow(temp1, j - 1)) || isnan(pow(temp1, j - 1)))
            {
                Gamma = Gamma + b[j] * (-pow(-1, j - 2) * factorial_fn(j - 2)) / factorial_fn(j - 1);
                sum = sum + b[j] * (-pow(-1, j - 2) * factorial_fn(j - 2)) / factorial_fn(j - 1);
            }
            else
            {
                Gamma = Gamma + b[j] * (pow(-1, j - 2) * factorial_fn(j - 2) / pow(temp1, j - 1) - pow(-1, j - 2) * factorial_fn(j - 2)) / factorial_fn(j - 1);
                sum = sum + b[j] * (pow(-1, j - 2) * factorial_fn(j - 2) / pow(temp1, j - 1) - pow(-1, j - 2) * factorial_fn(j - 2)) / factorial_fn(j - 1);
            }
        }

        cout << "S_n =∑1/i from i=1 to " << n_values_123[z] << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << setprecision(12) << "Sum(S_n) is: " << sum << endl;
        cout << setprecision(12) << "Gamma(S_n - ln(n)) is: " << Gamma << endl;
        cout << setprecision(12) << "Error(Gamma - EULER_CONSTANT): " << abs(Gamma - EULER_CONSTANT) << endl;
        cout << "" << endl;
    }

    long long temp1 = pow(10, 100);
    long double sum = 100 * log(10) + (1 + 1.0 / temp1) / 2;
    long double Gamma = (1 + 1.0 / temp1) / 2;
    for (int j = 3; j <= 10; j++)
    {
        Gamma = Gamma + b[j] * (pow(-1, j - 2) * factorial_fn(j - 2) / pow(temp1, j - 1) - pow(-1, j - 2) * factorial_fn(j - 2)) / factorial_fn(j - 1);
        sum = sum + b[j] * (pow(-1, j - 2) * factorial_fn(j - 2) / pow(temp1, j - 1) - pow(-1, j - 2) * factorial_fn(j - 2)) / factorial_fn(j - 1);
    }

    cout << "S_n =∑1/i from i=1 to 10^100 " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << setprecision(25) << "Sum(S_n) = " << sum << endl;
    cout << setprecision(25) << "Gamma(S_n - ln(n)) =" << Gamma << endl;
    cout << setprecision(25) << "Error(Gamma - EULER_CONSTANT) = " << abs(Gamma - EULER_CONSTANT) << endl;
    cout << "" << endl;

    long long temp2 = pow(10, pow(10, 10));
    sum = pow(10, 10) * log(10) + (1 + 1.0 / temp2) / 2;
    Gamma = (1 + 1.0 / temp2) / 2;
    for (int j = 3; j <= 10; j++)
    {

        Gamma = Gamma + b[j] * (pow(-1, j - 2) * factorial_fn(j - 2) / pow(temp1, j - 1) - pow(-1, j - 2) * factorial_fn(j - 2)) / factorial_fn(j - 1);
        sum = sum + b[j] * (pow(-1, j - 2) * factorial_fn(j - 2) / pow(temp1, j - 1) - pow(-1, j - 2) * factorial_fn(j - 2)) / factorial_fn(j - 1);
    }

    cout << "S_n =∑1/i from i=1 to 10^(10^10)  " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << setprecision(25) << "Sum(S_n) = " << sum << endl;
    cout << setprecision(25) << "Gamma(S_n - ln(n)) =" << Gamma << endl;
    cout << setprecision(25) << "Error(Gamma - EULER_CONSTANT) = " << abs(Gamma - EULER_CONSTANT) << endl;
    cout << "" << endl;

    return 0;
}
