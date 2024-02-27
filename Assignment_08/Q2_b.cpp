// Bisection Method to find roots of a equation

#include <bits/stdc++.h>
using namespace std;


void get_cofactor(vector<vector<double>> mat, vector<vector<double>> &temp, int p,
                 int q, int n)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Recursive function for finding determinant of matrix.
//? you should use Gaussian elimination, this takes n! operations.

double Det_of_matrix(vector<vector<double>> mat, int n)
{
    double D = 0; // Initialize result

    if (n == 1)
        return mat[0][0];

    vector<vector<double>> temp(n, vector<double>(n, 0)); // To store cofactors

    int sign = 1; // To store sign multiplier

        
    for (int f = 0; f < n; f++)
    {

        get_cofactor(mat, temp, 0, f, n);

        D += sign * mat[0][f] * Det_of_matrix(temp, n - 1);
        if(n==10)
        {
  
        }

        sign = -sign;
    }

    return D;
}

// Function that generates a Hilbert matrix
void Hilbert_Matrix(int n)
{
    vector<vector<double>> H(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            H[i][j] = 1.0 / ((i + 1) + (j + 1) - 1.0);
        }
    }

}

//To find (A -λI)

double f(vector<vector<double>> H, double x, int n)
{
    vector<vector<double>> Id(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                Id[i][j] = x;

            else
                Id[i][j] = 0;
        }
    }
    vector<vector<double>> chareqn(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            chareqn[i][j] = H[i][j] - Id[i][j];
        }
    }

    return Det_of_matrix(chareqn, n);
}

// Bisection Method
void Bisection_method(int n, double x0, double x1)
{
    vector<vector<double>> H(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // using the formula to generate hilbert matrix
            H[i][j] = 1.0 / ((i + 1) + (j + 1) - 1.0);
        }
    }

    double midpt = x0;

    while ((x1 - x0) >= 1e-8)
    {
        midpt = (x0 + x1) / 2.0;

        // if middle point is a root then break
        double f_value = f(H, midpt, n);
        if (f_value== 0.0)
            break;
        else if (f_value * f(H, x0, n) < 0)
            x1 = midpt;
        else
            x0 = midpt;

    }

    cout << setprecision(7) << "is root  = " << midpt << "\n"
         << endl;
}

int main()
{
    cout << "The eigenvalues of n x n Hilbert matrix i.e. the zeros of the determinant(A -λI). for n = 4 and 6 \n"
         << endl;
    int n_values[2] = {4, 6};

    vector<vector<double>> x0{
	    //? this is not the way to solve nonlinear eqs. You can't get
	    //? the roots from somewhere and put the limits.
	    //? You don't get any credit for such programs
	    //? You need to locate the roots. In any case your limits are
	    //? not even correct. e.g., for n=6, 2nd root (0,1) there are 5 roots
	    //? in that interval
        /* 1st row */
        {1.4, 0.1, 5e-3, 9e-5},

        /* 2nd row */
        {1.4, 0.0, 0.01,5e-4,1e-5,1e-7}};

    vector<vector<double>> x1{
        /* 1st row */
        {1.6, 0.2, 7e-3, 10e-5},

        /* 2nd row */
        {1.7, 1, 0.02,7e-4,2e-5,2e-7}};

    for (int i = 0; i < 2; i++)
    {
        cout<<"For n="<<n_values[i]<<endl;
        for (int j = 0; j < x0[i].size(); j++)
        {
            Bisection_method(n_values[i], x0[i][j], x1[i][j]);
        }
    }


    return 0;
}
