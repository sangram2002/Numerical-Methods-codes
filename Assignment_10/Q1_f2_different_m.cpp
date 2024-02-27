#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Q1)Generating synthetic data using the function f(x) with some error and then fitting the polynomial:\n"
         << endl;
    int i, j, k, n = 50;
    long double fi_error[n], fi[n], m_values[8];
    long double x[n], temp, R;
    long double chi_square = 0.0;

    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++)
    {
        x[i] = (i + 1) / (long double)(n + 1);
        fi[i] = 231.0 * pow(x[i], 6) - 315 * pow(x[i], 4) + 105 * pow(x[i], 2) - 5.0;
        R = ((long double)rand() / (RAND_MAX));

        fi_error[i] = 231.0 * pow(x[i], 6) - 315 * pow(x[i], 4) + 105 * pow(x[i], 2) - 5.0 + pow(10, -5)/pow(R - 0.5 ,3);
        chi_square += pow(fi[i] - fi_error[i], 2);
    }

    for (int i = 0; i < 8; i++)
    {
        m_values[i] = 2 + i;
    }

    for (int z = 0; z < 8; z++)
    {

        int m = m_values[z];

        cout << "---------------------------------" << endl;
        cout << "For m = " << m << endl;
        cout << "---------------------------------" << endl;
        long double A_mat[m][m + 1];

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

        cout << "the normal equations MATRIX :\n"
             << endl;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j <= m; j++)
                cout << A_mat[i][j] << " ";
            printf("\n");
        }

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

        long double Soln[10] = {0};
        for (i = m - 1; i >= 0; i--)
        {
            temp = 0.0;
            for (j = i; j <= m - 1; j++)
                temp = temp + A_mat[i][j] * Soln[j];

            Soln[i] = (A_mat[i][m] - temp) / A_mat[i][i];
        }

        // show the ai values
        cout << "\n The coefficients of fitted polynomial(ai values):\n"
             << endl;
        for (i = 0; i < m; i++)
            cout << Soln[i] << endl;

        long double del_square = 0.0;
        for (int i = 0; i < n; i++)
        {
            temp = 0.0;
            for (int j = 0; j < m; j++)
            {
                temp += Soln[j] * pow(x[i], j);
            }
            del_square += pow(fi[i] - temp, 2);
        }
        cout << "\ndelta_square = " << del_square << endl;
        cout << "chi_square = " << chi_square << endl;
    }

    return 0;
}