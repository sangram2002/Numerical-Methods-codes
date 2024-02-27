#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// Factorial of n(n!)
long double factorial_fn(long double n)
{
    long double temp = 1;
    for (long double i = 2; i <= n; i++)
        temp = temp * i;
    return temp;
}

//Given Fi=unction of Integration
long double true_value()
{
    long double temp1, temp2, temp3, sum = 0.0;
    for (int n = 1; n < 1e3; n++)
    {
        temp1 = factorial_fn(n);
        temp2 = pow(n + 1, 4);
        temp3 = (temp1 * temp2);
        temp3 = 1.0 / temp3;
        sum += temp3;
    }

    return sum + 1.0;
}

int main()
{
    long double a = 0, b = 1, n, h, value, s, answer, Correct_answer = true_value();

    n = 3;
    int iteration = 1;
    cout << " Finding the integral exp(x1x2x3x4) in 4 dimensions, the values are:\n"
         << endl;
    while (iteration < 4)
    {
        n = iteration * n;
        h = (b - a) / n;
        int int_n = (int)n;
        long double p[int_n + 1];
        for (int i1 = 0; i1 <= int_n; i1++)
        {
            p[i1] = a + (i1 * h);
        }
        long double f[int_n + 1][int_n + 1][int_n + 1][int_n + 1];
        for (int i1 = 0; i1 <= int_n; i1++)
        {
            for (int j1 = 0; j1 <= int_n; j1++)
            {
                for (int i2 = 0; i2 <= int_n; i2++)
                {
                    for (int j2 = 0; j2 <= int_n; j2++)
                    {
                        value = p[i1] * p[j1] * p[i2] * p[j2];
                        f[i1][j1][i2][j2] = exp(value);
                    }
                }
            }
        }

        long double f1[int_n + 1][int_n + 1][int_n + 1];

        for (int i1 = 0; i1 <= int_n; i1++)
        {
            for (int j1 = 0; j1 <= int_n; j1++)
            {
                for (int i2 = 0; i2 <= int_n; i2++)
                {
                    answer = 0.0;
                    for (int j2 = 0; j2 <= int_n; j2++)
                    {
                        value = f[i1][j1][i2][j2];
                        if (isinf(value))
                            value = 0.0;
                        if (j2 == 0 || j2 == int_n)
                        {
                            value = value / 2.0;
                            answer = answer + value;
                        }
                        else
                        {
                            answer = answer + value;
                        }
                    }
                    answer = h * answer;
                    f1[i1][j1][i2] = answer;
                }
            }
        }
        long double f2[int_n + 1][int_n + 1];
        for (int i1 = 0; i1 <= int_n; i1++)
        {
            for (int j1 = 0; j1 <= int_n; j1++)
            {
                answer = 0.0;
                for (int i2 = 0; i2 <= int_n; i2++)
                {
                    value = f1[i1][j1][i2];
                    if (isinf(value))
                        value = 0.0;
                    if (i2 == 0 || i2 == int_n)
                    {
                        value = value / 2.0;
                        answer = answer + value;
                    }
                    else
                    {
                        answer = answer + value;
                    }
                }
                answer = h * answer;
                f2[i1][j1] = answer;
            }
        }
        long double f3[int_n + 1];
        for (int i1 = 0; i1 <= int_n; i1++)
        {
            answer = 0.0;
            for (int j1 = 0; j1 <= int_n; j1++)
            {
                value = f2[i1][j1];
                if (isinf(value))
                    value = 0.0;
                if (j1 == 0 || j1 == int_n)
                {
                    value = value / 2.0;
                    answer = answer + value;
                }
                else
                {
                    answer = answer + value;
                }
            }
            answer = h * answer;
            f3[i1] = answer;
        }
        answer = 0.0;
        for (int i1 = 0; i1 <= int_n; i1++)
        {
            value = f3[i1];
            if (isinf(value))
                value = 0.0;
            if (i1 == 0 || i1 == int_n)
            {
                value = value / 2.0;
                answer = answer + value;
            }
            else
            {
                answer = answer + value;
            }
        }
        answer = h * answer;

        cout << setprecision(15) << "Value of I_2 = " << setprecision(15) << answer << ", having error wrt actual answer = " << abs(answer - Correct_answer) << endl;

        iteration++;
    }
    return 0;
}
