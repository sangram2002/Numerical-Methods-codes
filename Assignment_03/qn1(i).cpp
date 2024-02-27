#include <bits/stdc++.h>
using namespace std;

int main()
{
    long double A[4][4] = {{0.000007143, 0, 0, 0}, {0.6262, 0.000007355, 0, 0}, {0.4923, 0.2123, 0.000002534, 0}, {0.8017, 0.6123, 0.7165, 0.000004133}};
    long double Augmented_Matrix[4][5], true_soln[4], b[4], temp = 0.0;
    int i, j, m, n = 4;

    // initializing true soln array elements
    for (i = 0; i < n; i++)
    {
        true_soln[i] = 1;
    }

    for (i = 0; i < n; i++)
    {
        b[i] = 0.0;
        for (j = 0; j < n; j++)
        {
            Augmented_Matrix[i][j] = A[i][j];
            b[i] = b[i] + A[i][j];
        }
        Augmented_Matrix[i][n] = b[i];
    }
    cout << "The augmented matrix of A: " << endl;
    cout << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            cout << setw(12) << setprecision(7) << Augmented_Matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    //? elimination is not needed as the matrix is lower triangular
    //? should be i<n-1
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        //pivoting
        {
		//? Interchange should be done once when the min is found
		//? not everytime a smaller element is found
            if (abs(Augmented_Matrix[i][i]) < abs(Augmented_Matrix[j][i]))
            {
                for (m = 0; m < n + 1; m++)
                {
                    temp = Augmented_Matrix[i][m];
                    Augmented_Matrix[i][m] = Augmented_Matrix[j][m];
                    Augmented_Matrix[j][m] = temp;
                }
            }
        }
	//? elimination should be inside the for i loop. Otherwise how can
	//? you eliminate entries in 2nd and higher columns?
    }
    //Gaussian elimination
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            temp = Augmented_Matrix[j][i] / Augmented_Matrix[i][i];

	    //? this loop should be from m=i+1
            for (m = 0; m < n + 1; m++)
            {
                Augmented_Matrix[j][m] = Augmented_Matrix[j][m] - (temp * Augmented_Matrix[i][m]);
            }
        }
    }

    // Back-substitution
    long double Calculated_soln[n];
    for (i = n - 1; i >= 0; i--)
    {
        Calculated_soln[i] = Augmented_Matrix[i][n];
        for (j = i + 1; j < n; j++)
        {
		//? how can you hae i=j when j stars from i+1
            if (i != j)
            {
                Calculated_soln[i] = Calculated_soln[i] - Augmented_Matrix[i][j] * Calculated_soln[j];
            }
        }
        Calculated_soln[i] = Calculated_soln[i] / Augmented_Matrix[i][i];
    }
    cout << "Calculated Solution : " << endl;
    for (i = 0; i < n; i++)
    {
        cout <<"  x_"<<(i+1)<<" = "<< Calculated_soln[i] << endl;
    }
    cout << endl;

    cout << "The error in the soln calculated: " << endl;

    for (i = 0; i < n; i++)
    {
        cout << "  Δx_" << (i + 1) << " = " << abs(Calculated_soln[i] - true_soln[i]) << endl;
    }

    cout << endl;

    return 0;
}
