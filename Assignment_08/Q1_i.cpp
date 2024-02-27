
#include <bits/stdc++.h>

using namespace std;

// Newton Raphson Method to find roots of a equation

double f(double x, double a)
{
    return x - a * sin(x);
}

double f_derivative(double x, double a)
{
    return 1.0 - a * cos(x);
}

// Function to find the root by Newton Raphson Method
void NewtonRaphsonMethod(double x, double a)
{
    double temp = f(x,a) / f_derivative(x,a);
    while (abs(temp) >= 1e-4)
    {
        temp = f(x,a) / f_derivative(x,a);
        x = x - temp; // x(i+1) = x(i) - f(x) / f'(x)
    }

    //? you are checking for 1e-4. How do you get 7 significant figures.
    //? All roots are not correct to that.
    cout << setprecision(7) << "The value of the root is (correct upto 7 significant figures): " << x << endl;
}

void Different_a_values(double a)
{
    cout << "\n For a=" << a << endl;

 //The initial guess is obtained by observing the graph of x-asinx
    
    if(a == 2) {
        double Initial_guess[] = {-3, 0.2, 3};

        for (int z = 0; z < 3; z++)
        {
            NewtonRaphsonMethod(Initial_guess[z],a);
        }
    } else if(a == 10) {
        double Initial_guess[] = {-9, -7, -3, 0.2, 3, 7, 9};

        for (int z = 0; z < 7; z++)
        {
            NewtonRaphsonMethod(Initial_guess[z],a);
        }
    } else if(a == 20) {
        double Initial_guess[] = {-15, -13, -10, -7, -3, 0.2, 3, 7, 10, 13, 15};

        for (int z = 0; z < 11; z++)
        {
            NewtonRaphsonMethod(Initial_guess[z],a);
        }
    } else if(a == 20.3959) {
        double Initial_guess[] = {-21, -20, -15, -13, -9, -7, -3, 0.2, 3, 7, 9, 13, 15, 20, 21}; 

        for (int z = 0; z < 15; z++)
        {
            NewtonRaphsonMethod(Initial_guess[z],a);
        }
    }
}

int main()
{
 
    double a_values[4] = {2, 10, 20, 20.3959};
    for (int z = 0; z < 4; z++)
    {
        Different_a_values(a_values[z]);
    }
    return 0;
}
