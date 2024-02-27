
#include <bits/stdc++.h>

using namespace std;

// Newton Raphson Method to find roots of a equation

long double f(long double x)
{
    return pow(x,6) - 9.2*pow(x,5) +34.45*pow(x,4)-66.914* pow(x,3)+70.684* pow(x,2) -38.168*x +8.112 + 0.01234*log(x);
}

long double f_derivative(long double x)
{
    return 6*pow(x,5) - 9.2*5*pow(x,4) + 34.45*4*pow(x,3)-66.914*3* pow(x,2)+70.684*2*x -38.168 + 0.01234*1.0/x;
}

// Function to find the root by Newton Raphson Method
void NewtonRaphsonMethod(int i,long double x)
{
    long double temp = f(x) / f_derivative(x);
    while (abs(temp) >= 1e-4)
    {
        temp = f(x) / f_derivative(x);
        x = x - temp; // x(i+1) = x(i) - f(x) / f'(x)
    }


    cout << setprecision(7) <<"is root ("<< i+1 <<") = "<< x << endl;
}

int main()
{
     //The initial guess is obtained by observing the graph of the polynomial
     //? you have missed one root near x=0
    long double a[4]= {0.5,1.1,1.5,1.8};
    cout<<"(iii) All real roots of the polynomial (correct upto 7 significant figures)\n"<<endl;

    for (int i = 0; i < 4; i++)
    {
        
        NewtonRaphsonMethod(i,a[i]);
    }
    

    return 0;
}
