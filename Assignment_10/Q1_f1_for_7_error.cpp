#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Q1)Generating synthetic data using the function f(x) with some error and then fitting the polynomial\n (estimating the error in each coeffcient) for m=7:\n"
         << endl;
    int i, j, k, n = 50, m = 7;
    long double fi[n], A_mat[m][m + 1];
    long double x[n], temp, R;
    long double Soln[7][100] = {0};

    srand((unsigned)time(NULL));
    for (int z = 0; z < 100; z++)
    {
        long double fi_error[n];
        for (int i = 0; i < n; i++)
        {
            x[i] = (i + 1) / (long double)(n + 1);
            fi[i] = 231.0 * pow(x[i], 6) - 315 * pow(x[i], 4) + 105 * pow(x[i], 2) - 5.0;
            R = ((long double)rand() / (RAND_MAX));

            fi_error[i] = 231.0 * pow(x[i], 6) - 315 * pow(x[i], 4) + 105 * pow(x[i], 2) - 5.0 + (R - 0.5) * pow(10, -2);

            // cout<<setprecision(9)<< x[i] <<","<< fi_error[i]<<endl;
        }

        for (int k = 0; k < m; k++)
        {
            for (int j = 0; j < m; j++)
            {
                A_mat[k][j] = 0.0;
                for (int i = 0; i < n; i++)
                {
                    A_mat[k][j] += pow(x[i], k + j);
                }
            }
        }

        for (int k = 0; k < m; k++)
        {
            long double sum = 0.0;
            for (int i = 0; i < n; i++)
            {
                sum += (fi_error[i] * pow(x[i], k));
            }
            A_mat[k][m] = sum;
        }
        //Solving system of linear equations
	//? The matrix doesn't depend on the function value so the
	//? elimination should be done only once

        // partial pivoting

        for (i = m - 1; i > 0; i--)
        {
            if (A_mat[i - 1][0] < A_mat[i][0])
                for (j = 0; j <= m; j++)
                {
                    temp = A_mat[i][j];
                    A_mat[i][j] = A_mat[i - 1][j];
                    A_mat[i - 1][j] = temp;
                }
        }

        //changing to upper triangular matrix
        //Forward elimination process

        for (k = 0; k < m - 1; k++)
            for (i = k; i < m - 1; i++)
            {
                temp = (A_mat[i + 1][k] / A_mat[k][k]);

                for (j = 0; j <= m; j++)
                    A_mat[i + 1][j] -= temp * A_mat[k][j];
            }

        //Backward Substitution method

        for (i = m - 1; i >= 0; i--)
        {
            temp = 0;
            for (j = i; j <= m - 1; j++)
                temp = temp + A_mat[i][j] * Soln[j][z];

            Soln[i][z] = (A_mat[i][m] - temp) / A_mat[i][i];
        }

        // show the ai values
    }

    long double soln_avg[7] = {0.0}, soln_error[7] = {0.0};
    for (int i = 0; i < 7; i++)
    {

        for (int j = 0; j < 100; j++)
        {
            soln_avg[i] += Soln[i][j];
        }
        soln_avg[i] = soln_avg[i] / 100;
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            soln_error[i] += pow(Soln[i][j] - soln_avg[i], 2);
        }
        soln_error[i] = pow(soln_error[i],0.5) / 10;
    }

    cout << "\n Avearage of the coefficients of fitted polynomial(ai_avg values):\n"
         << endl;
    for (int j = 0; j < 7; j++)
    {
        cout << soln_avg[j] << " ";
    }
    cout << "\n\n Error in the coefficients of fitted polynomial(ai_error values):\n"
         << endl;
    for (int j = 0; j < 7; j++)
    {
        cout << soln_error[j] << " ";
    }

    return 0;
}
