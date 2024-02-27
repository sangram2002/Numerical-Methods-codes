#include <bits/stdc++.h>
using namespace std;

void For_pivotting_and_Gaussian_elimination(double *Augmented_Matrix, int n)
{
    int i, j, k;
    double f,temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (abs(*(Augmented_Matrix + i * (n + 1) + i)) < abs(*(Augmented_Matrix + j * (n + 1) + i)))
            {
                //pivoting
                for (k = 0; k < n + 1; k++)
                {
                    temp = *(Augmented_Matrix + i * (n + 1) + k);
                    *(Augmented_Matrix + i * (n + 1) + k) = *(Augmented_Matrix + j * (n + 1) + k);
                    *(Augmented_Matrix + j * (n + 1) + k) = temp;
                }
            }
        }
    }

    //Gaussian elimination
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            f = (*(Augmented_Matrix + j * (n + 1) + i)) / (*(Augmented_Matrix + i * (n + 1) + i));
            for (k = 0; k < n + 1; k++)
            {
                *(Augmented_Matrix + j * (n + 1) + k) -= (f * (*(Augmented_Matrix + i * (n + 1) + k)));
            }
        }
    }
}

int main()
{
    int i, j, k, n;
    cout << "Enter the value n(For example 5,10 & 15 etc.)" << endl;
    cin >> n;

    double A[n][n], b[n], Identity_matrix[n][n], Augmented_Matrix[n][n + 1], inv_of_A[n][n], Column_of_inv_mat[n], soln_calculated[n], true_soln[n], temp_array[n][n];
    double temp, Det_of_A = 1.0;

    // initializing true soln array elements
    for (i = 0; i < n; i++)
    {
        true_soln[i] = 1;
    }

    // To create identity matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (i == j)
            {
                Identity_matrix[i][j] = 1;
            }
            else
            {
                Identity_matrix[i][j] = 0;
            }
    }

    //To create the required Hilbert matrix for 2(i)
    for (i = 0; i < n; i++)
    {
        b[i] = 0.0;
        for (j = 0; j < n; j++)
        {
            A[i][j] = 1.0 / ((i + 1) + (j + 1) - 1);
            b[i] = b[i] + A[i][j];
        }
    }

    // To find inverse of a matrix A
    //? you are rpeating elimination for each column. That should be done
    //? only once, or you can augment all n columns and the elimination once
    for (int z = 0; z < n; z++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                Augmented_Matrix[i][j] = A[i][j];
            }
            Augmented_Matrix[i][n] = Identity_matrix[z][i];
        }

        For_pivotting_and_Gaussian_elimination((double *)Augmented_Matrix, n);

        // Back-substitution
        for (i = n - 1; i >= 0; i--)
        {
            Column_of_inv_mat[i] = Augmented_Matrix[i][n];
            for (j = i + 1; j < n; j++)
            {
                if (i != j)
                {
                    Column_of_inv_mat[i] = Column_of_inv_mat[i] - (Augmented_Matrix[i][j] * Column_of_inv_mat[j]);
                }
            }
            Column_of_inv_mat[i] = Column_of_inv_mat[i] / Augmented_Matrix[i][i];
        }

        //To store the column of inverse matrix
        for (i = 0; i < n; i++)
        {
            inv_of_A[z][i] = Column_of_inv_mat[i];
        }
    }

    //To calculate soln by A^(-1)b
    for (i = 0; i < n; i++)
    {
        soln_calculated[i] = 0;
        for (j = 0; j < n; j++)
        {
            temp = 0.0;
            temp = ((b[j]) * (inv_of_A[i][j]));
            soln_calculated[i] = soln_calculated[i] + temp;
        }
    }

    //To calculate determinant of matrix A
    //? The sign may not be correct as pivoting changes the sign

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            Augmented_Matrix[i][j] = A[i][j];
        }
        Augmented_Matrix[i][n] = b[i];
    }

    For_pivotting_and_Gaussian_elimination((double *)Augmented_Matrix, n);

    //determinant of A matrix
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
            temp_array[i][j] = Augmented_Matrix[i][j];
    }

    for (i = 0; i < n; i++)
    {
        Det_of_A = Det_of_A * temp_array[i][i];
    }

    //printing values
    cout << "For the Hilbert matrix with value of n =" << n << " we have:" << endl;
    cout << endl;

    cout << "The matrix A : " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << setw(10) << A[i][j] << " ";
        cout << endl;
    }

    cout << endl;
    cout << "The inverse matrix of A :" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << setw(12) << setprecision(7) << inv_of_A[i][j] << " ";
        cout << endl;
    }

    cout << endl;
    cout << "The Determinant of matrix A = " << Det_of_A << endl;

    cout << endl;
    cout << "The soln calculated using A^(-1)b are " << endl;

    for (i = 0; i < n; i++)
    {
        cout << "  x_" << (i + 1) << " = " << soln_calculated[i] << endl;
    }

    cout << endl;
    cout << "The error in the soln calculated: " << endl;

    for (i = 0; i < n; i++)
    {
        cout << "  Δx_" << (i + 1) << " = " << abs(soln_calculated[i] - true_soln[i]) << endl;
    }

    cout << endl;

    return 0;
}
