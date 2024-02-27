#include <bits/stdc++.h>
using namespace std;

int main()
{
    long i, j, m, n, degree = 2;
    cout << "Enter the value of n(For example: 5,10,20,50 etc.)" << endl;
    cin >> n;

    long double temp, Augmented_matrix[2][3], soln[2];
    //? use double as this can overflow at large n, say 100
    long long f[n + 3];

    f[0] = 0;
    f[1] = 1;

    //To calculate fibonacci nos.

    i = 2;
    while (i <= n + 3)
    {
        f[i] = f[i - 1] + f[i - 2];
        i++;
    }

    //To store in the matrix
    m = n - 1;

    i = 0;
    while (i < 2)
    {
        j = 0;
        while (j <= 2)
        {
            Augmented_matrix[i][j] = f[m];
            m = m + 1;
            j++;
        }
        m = m - 2;
        i++;
    }

    cout << "The augmented matrix is" << endl;

    i = 0;
    while (i < 2)
    {
        j = 0;
        while (j <= 2)
        {
            cout << Augmented_matrix[i][j] << "  ";
            
            j++;
        }
        cout << endl;
        i++;
    }

    for (i = 0; i < degree; i++)
        for (m = i + 1; m < degree; m++)
            //pivoting
            if (abs(Augmented_matrix[i][i]) < abs(Augmented_matrix[m][i]))
                for (j = 0; j <= degree; j++)
                {
                    long double temp = Augmented_matrix[i][j];
                    Augmented_matrix[i][j] = Augmented_matrix[m][j];
                    Augmented_matrix[m][j] = temp;
                }

    //Gaussian elimination
    for (i = 0; i < degree - 1; i++)
        for (m = i + 1; m < degree; m++)
        {
            long double t = Augmented_matrix[m][i] / Augmented_matrix[i][i];
            for (j = 0; j <= degree; j++)
                Augmented_matrix[m][j] = Augmented_matrix[m][j] - t * Augmented_matrix[i][j];
        }

    //Back-substitution
    for (i = degree - 1; i >= 0; i--)
    {
        soln[i] = Augmented_matrix[i][degree];
        for (j = i + 1; j < degree; j++)
            if (j != i)
                soln[i] = soln[i] - Augmented_matrix[i][j] * soln[j];
        soln[i] = soln[i] / Augmented_matrix[i][i];
    }
    cout << "\n Solution of the matrix:\n";
    for (i = 0; i < degree; i++)
        cout <<"  x_"<<(i+1)<<" = "<< soln[i] << endl;
    
    cout << "\n The Solution of the matrix becomes more ill-conditioned as value of n increases(for example n=50).\n The condn number is of the order f_n^2.";
    
    return 0;
}
