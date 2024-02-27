#include <bits/stdc++.h>

using namespace std;

int main()
{

	int i, j, n = 4, step;
	long double a_pI[n][n], x[n], x_new[n], p = 5;
	long double initial_guess[2][n] = {
		{1, 1, 1, 1},

		{1, 1, 1, -1}};
	long double temp, eigenvalue_new = 1, eigenvalue_old = 1, error = 1e-5;

	cout << setprecision(7) << fixed;

	long double a[n][n] = {
		{-1, 4, 4, 1},

		{4, -1, 1, 4},

		{4, 1, -1, 4},

		{1, 4, 4, -1}};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			if (i == j)
			{
				a_pI[i][j] = p;
			}
			else
			{
				a_pI[i][j] = 0.0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a_pI[i][j] = a[i][j] - a_pI[i][j];
		}
	}

	cout << "The given matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	for (int z = 0; z < 2; z++)
	{
		step = 0;
		for (j = 0; j < n; j++)
		{
			x[j] = initial_guess[z][j];
		}

		do
		{
			eigenvalue_old = eigenvalue_new;
			step++;
			for (i = 0; i < n; i++)
			{
				temp = 0.0;
				for (int j = 0; j < n; j++)
				{
					temp = temp + a_pI[i][j] * x[j];
				}
				x_new[i] = temp;
			}

			for (i = 0; i < n; i++)
			{
				x[i] = x_new[i];
			}

			eigenvalue_new = fabs(x[0]);
			for (i = 0; i < n; i++)
			{
				if (fabs(x[i]) > eigenvalue_new)
				{
					eigenvalue_new = x[i];
				}
			}

			for (i = 0; i < n; i++)
			{
				x[i] = x[i] / eigenvalue_new;
			}

		} while (fabs(eigenvalue_new - eigenvalue_old) > error);

		cout << endl
			 << "No. of steps required to converge = " << step << endl;
		cout << "Eigen Value = " << eigenvalue_new + p << endl;
		cout << "Eigen Vector: " << endl;
		cout << "[";
		for (i = 0; i < n; i++)
		{
			cout << x[i] << "\t";
		}
		cout << "]";
		cout << "\n-----------------------------------------------------------------" << endl;
	}

	return (0);
}