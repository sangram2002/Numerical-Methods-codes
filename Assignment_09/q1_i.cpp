
#include <bits/stdc++.h>

using namespace std;

// Newton Raphson Method to find roots of a equation
//? you can trivially eliminate x. No need for Newton's method

double f1(double x, double y)
{
    return x-tan(y);
}

double f2(double x, double y,double a)
{
    return sin(4.0/(x*x+y*y+a));
}

// Function to find the root by Newton Raphson Method
void NewtonRaphsonMethod(double x_i, double y_i,double a)
{

    double x, y, det, numerator,denominator, a11, a12, a21, a22;
    double Jinv_F[2][1] = {{1}, {1}};

    double M[2][1] = {{x_i}, {y_i}};
    

    while (abs(Jinv_F[0][0]) >= 1e-7 || abs(Jinv_F[1][0]) >= 1e-7)
    {

        x = M[0][0];
        y = M[1][0];
        numerator = -1*pow(x*x+y*y+a,2)/cos(4.0/(x*x+y*y+a));
        denominator = x/pow(cos(y),2)+y;
        a11 = y/denominator;
        a12 = numerator/(8*x+4*y+4*y*cos(2*y));
        a21 = -1*x/denominator;
        a22 = numerator/(8*x/pow(cos(y),2)+8*y);

        double Jacobian_inv[2][2] = {{a11, a12}, {a21, a22}}, F_mat[2][1] = {{f1(x, y)}, {f2(x, y,a)}};

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
    cout<<endl;
}

int main()
{
    //The initial guess is obtained by observing the graph of f1(x) = 0 and f2(x) = 0
    cout<<endl;
    cout<<"If (x, y) is a solution, then (-x, -y) is also a solution of the system. So, only positive solutions are calculated."<<endl;
    vector<double> x{
        /* 1st row */
        {0.3}};

    vector<double> y{
        /* 1st row */
        {0.3}};

    cout << "The roots for x-tany=0 and sin(4.0/(x*x+y*y+a)) for a = 1 are: " << endl;
    cout<<endl;

    for (int z = 0; z < x.size(); z++)
    {

        NewtonRaphsonMethod(x[z], y[z],1.0);
    }

    //The initial guess is obtained by observing the graph of f1(x) = 0 and f2(x) = 0
      vector<double> x1{
        
	      //? you have just supplied the roots
        {0.05},
        {0.08},
        {0.11},
        {0.14},
        {0.17},
        {0.20},
        {0.23},
        {0.28},
        {0.33},
        {0.41},
        {0.55},
        {0.8}};

     vector<double> y1{
         
        {0.05},
        {0.08},
        {0.11},
        {0.14},
        {0.17},
        {0.20},
        {0.23},
        {0.28},
        {0.33},
        {0.41},
        {0.5},
        {0.7}};

    cout << "The roots for x-tany=0 and sin(4.0/(x*x+y*y+a)) for a = 0.1 are: " << endl;
    cout<<endl;

    for (int z = 0; z < x1.size(); z++)
    {

        NewtonRaphsonMethod(x1[z], y1[z],0.1);
    }
    return 0;
}
