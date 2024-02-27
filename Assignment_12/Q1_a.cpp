#include <bits/stdc++.h>

using namespace std;

void fn(vector<vector<long double>> a_pI, vector<long double> x, long double p)
{
	long double temp, eigenvalue_new = 1, eigenvalue_old = 1, error = 1e-5;
	int i, j, n = 4, step = 0;

	vector<long double> x_new(n);

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
				//? you need to use fabs(x[i])
				//? but that is also not correct as
				//? after finding the maximum magnitude
				//? you need to divide by actual value
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

int main()
{

	int i, j, n = 4, step;
	vector<vector<long double>> a_pI(n, vector<long double>(n));
	vector<vector<long double>> a(n, vector<long double>(n));

	long double temp, p = 5, eigenvalue_new = 1, eigenvalue_old = 1, error = 1e-7;

	cout << setprecision(7) << fixed;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			// using the formula to generate hilbert matrix
			a[i][j] = 1.0 / ((i + 1) + (j + 1) - 1.0);
		}
	}

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

	//? you cannot calculate eigenvalues by applying arbitrary shifts
	//? like this
	//? you need to find the dominant value first and then apply shift
	//? which is close to that, not rbitrary value of 5
	fn(a_pI, {1, 1, 1, 1}, 5);	  //p=5
	fn(a_pI, {1, 1, 1, 0.75}, 5); //initial guess is orthogonal to the eigenvector obtained by 1st initial guess
	fn(a, {1, 1, 1, 1}, 0);		  //p=0

	cout << "3 different eigenvector for different eigenvalues are obtained so the \n4th eigenvalue is trace of matrix - (sum of eigenvalues) " << endl;
	//? the trace of the matrix is smaller than the sum of eigenvalues
	//? which would give -ve eigenvalue, but the matrix is positive definite
	//? You can see that the eigenvector is not correctly normalised
	//? for the 2nd eigenvalue, which is not correct. The problem
	//? is from incorrect normalisation
	//? I don't think the 1st vector has also converged properly

	return (0);
}
