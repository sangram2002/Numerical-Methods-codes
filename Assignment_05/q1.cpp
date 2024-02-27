#include <bits/stdc++.h>
using namespace std;

//Interpolation in 2-dimension by lagrange interpolation
//? this is not linear interpolation

void Linear_lagrange_interpolation(int n, long double values[5], long double xy_2dMash[5][5], long double cofactor_matrix[5])
{
    for (int i = 0; i < n; i++)
    {
        values[i] = 0;
        for (int j = 0; j < n; j++)
        {
            values[i] = values[i] + (cofactor_matrix[j] * xy_2dMash[j][i]);
        }
    }
}

//To find f(x,y) at a given (x,y) i.e. final result
long double Result(int n, long double values_2[5], long double cofactor_matrix[5])
{  
    long double soln = 0;
    for (int i = 0; i < n; i++)
    {
        soln = soln + (cofactor_matrix[i] * values_2[i]);
    }
    return soln;
}

//To calculate the horizontal/vertical cofactors i.e. l_k polynomial of degree n
void Cofactor(int n, int x_value, long double x[5], long double cofactor_matrix[5])
{
    long double temp;
    for (int i = 0; i < n; i++)
    {
        cofactor_matrix[i] = 1;
        for (int j = 0; j < 5; j++)
        { 
            temp = (x_value - x[j]) / (x[i] - x[j]);
            if (i != j)
            {
                cofactor_matrix[i] = cofactor_matrix[i] * temp;
            }
        }
    }
}


int main()
{
    int n = 5;
    long double xy_2dMash[5][5] = {{0.9401, 0.9647, 0.9876, 1.0044, 1.0107}, {0.9835, 1.0118, 1.0387, 1.0587, 1.0662}, {1.0277, 1.0602, 1.0915, 1.1152, 1.1242}, {1.0725, 1.1097, 1.1462, 1.1743, 1.1851}, {1.1180, 1.1605, 1.2030, 1.2362, 1.2492}};   
    long double cofactor_x[n], cofactor_y[n], values_horizontal[n], values_vertical[n], values_diagonal[n],calculated_value, correct_value = 1.0509;
    long double x[n] = {50, 60, 70, 80, 90}, y[n] = {50, 52, 54, 56, 58}, x_value = 65, y_value = 53;
    
//(i)interpolating horizontally and then vertically

    //horizontal interpolation
    Cofactor(n, x_value, x, cofactor_x);
    Linear_lagrange_interpolation(n, values_horizontal, xy_2dMash, cofactor_x);

    //vertical interpolation
    Cofactor(n, y_value, y, cofactor_y);
    calculated_value = Result(n, values_horizontal, cofactor_y);
    
    cout <<"________________________________________________________"<< endl;
    cout << "Interpolation in 2-dimension by lagrange interpolation:" << endl;
    cout <<"________________________________________________________\n"<< endl;
    cout << "(i)An approximation to f(65,53) by interpolating horizontally and then vertically gives " << calculated_value << " with error: " << (correct_value -calculated_value) << endl;

//(ii)interpolating vertically and then horizontally

    //vertical interpolation
    Cofactor(n, y_value, y, cofactor_y);
    Linear_lagrange_interpolation(n, values_vertical, xy_2dMash, cofactor_y);

    //horizontal interpolation
    Cofactor(n, x_value, x, cofactor_x);
    calculated_value = Result(n, values_vertical, cofactor_x); 

    cout << "(ii)An approximation to f(65,53) by interpolating vertically and then horizontally gives " << calculated_value << "  with error: " << (correct_value - calculated_value) << endl;

//(iii)interpolating diagonally along the two diagonals
    Cofactor(n, x_value, x, cofactor_x);

    for (int i = 0; i < n; i++)
    {
	    //? why is the loop needed, it doesn't depend on i and the value
	    //? is already the interpolation why do you need to do another one
        values_diagonal[i] = 0;
        for (int j = 0; j < n; j++)
        {
            values_diagonal[i] = values_diagonal[i] + (cofactor_x[j] * xy_2dMash[j][j]);
        }
    }
    cout << values_diagonal[1] << " " <<values_diagonal[2]<<endl;

    Cofactor(n, y_value, y, cofactor_y);
    calculated_value = Result(n, values_diagonal, cofactor_y);

    cout << "(iii)An approximation to f(65,53) by interpolating diagonally along the two diagonals gives " << calculated_value << " with error: " << (correct_value - calculated_value) << endl;

    return 0;

} 
