
#include <bits/stdc++.h>

using namespace std;

// Newton Raphson Method to find roots of a equation

// Factorial of n(n!)
long double factorial_fn(long double n)
{
    long double temp = 1;
    for (long double i = 2; i <= n; i++)
        temp = temp * i;
    return temp;
}
//Bessel function J_0(x)
long double f(long double x)
{
		
	double temp,temp1,temp2=0.0;
	for (int i = 0; i < 100; i++)
	{
	temp = pow(-1,i);
	temp = temp*pow(x/2.0,(2*i));
	temp1=temp/pow(factorial_fn(i),2);
	temp2=temp2+temp1;
	}	
    return temp2;
}

long double f_derivative(long double x)
{
    	
	double temp,temp1,temp2=0.0;
	for (int i = 0; i < 100; i++)
	{
	temp = pow(-1,i);
	temp = temp*2*i*pow(x/2.0,(2*i-1));
	temp1=temp/pow(factorial_fn(i),2);
	temp2=temp2+temp1;
	}	
    return temp2;
}

// Function to find the root by Newton Raphson Method
void NewtonRaphsonMethod(int i,long double x)
{
    long double temp = f(x) / f_derivative(x);
    while (abs(temp) >= 1e-7)
    {
        temp = f(x) / f_derivative(x);
        x = x - temp; // x(i+1) = x(i) - f(x) / f'(x)
    }


    cout << setprecision(7) <<"is root ("<< i+1 <<") = "<< x << endl;
}

int main()
{
     //The initial guess is obtained by observing the graph of Bessel function J_0(x)
    long double a[3]= {2,6,9};
    cout<<"(iv) First three positive zeros of Bessel function J_0(x) (correct upto 7 significant figures)\n"<<endl;

    for (int i = 0; i < 3; i++)
    {
        
        NewtonRaphsonMethod(i,a[i]);
    }
    

    return 0;
}
