
#include <bits/stdc++.h>

using namespace std;

// Newton Raphson Method to find roots of a equation

double f1(double x, double y)
{
    return -2.0 * x * x - 3 * x * y + 4 * sin(y) + 6.0;
}

double f2(double x, double y)
{
    return 3 * x * x - 2 * x * y * y + 3 * cos(x) - 8.0;
}

// Function to find the root by Newton Raphson Method
void NewtonRaphsonMethod(double x_i, double y_i)
{
    double x, y, det, numerator, a11, a12, a21, a22;
    double Jinv_F[2][1] = {{1}, {1}};

    double M[2][1] = {{x_i}, {y_i}};

    while (abs(Jinv_F[0][0]) >= 1e-7 || abs(Jinv_F[1][0]) >= 1e-7)
    {

        x = M[0][0];
        y = M[1][0];
        det = x * (2 * x * (8 * y + 9.0) - 9 * sin(x) + 6 * y * y) + 4 * cos(y) * (-6 * x + 3 * sin(x) + 2 * y * y);
        a11 = -4.0 * x * y / det;
        a12 = (3 * x - 4 * cos(y)) / det;
        a21 = (-6.0 * x + 3 * sin(x) + 2 * y * y) / det, a22 = (-4 * x - 3.0 * y) / det;

        double Jacobian_inv[2][2] = {{a11, a12}, {a21, a22}}, F_mat[2][1] = {{f1(x, y)}, {f2(x, y)}};

        for (int i = 0; i < 2; i++)
        {

            Jinv_F[i][0] = 0;

            for (int k = 0; k < 2; k++)
            {
                Jinv_F[i][0] += Jacobian_inv[i][k] * F_mat[k][0];
            }

            M[i][0] = M[i][0] - Jinv_F[i][0];
        }
    }
    cout << setprecision(7) << "The value of the root is (correct upto 7 significant figures): ( x= " << M[0][0] << " ,y= " << M[1][0] << " )" << endl;
}

int main()
{
    //The initial guess is obtained by observing the graph of f1(x) = 0 and f2(x) = 0

    vector<double> x{
        /* 1st row */
        {-1, -0.1, 1.5, 2}};

    vector<double> y{
        /* 1st row */
        {-0.1, -2, 0.2, -1}};

    cout << "The roots for - 2x^2 - 3xy + 4 sin y + 6 = 0 and 3x^2 -2xy^2 + 3 cos x = 8 are: " << endl;

    for (int z = 0; z < x.size(); z++)
    {

        NewtonRaphsonMethod(x[z], y[z]);
    }
    return 0;
}
