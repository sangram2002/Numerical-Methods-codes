// Bisection Method to find roots of a equation

#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
	return x-tan(x);
}

// Bisection Method
void Bisection_method(int i,double x0, double x1)
{

	double midpt = x0;
	while ((x1-x0) >= 1e-6)
	{
		midpt = (x0+x1)/2;

		// if middle point is a root then break
		if (f(midpt) == 0.0)
			break;
		else if (f(midpt)*f(x0) < 0)
			x1 = midpt;
		else
			x0 = midpt;
	}

	cout << setprecision(7) <<"is root ("<< i <<") = "<< midpt <<"\n"<< endl;
}

int main()
{
    cout<<"First 100 positive roots of x = tan x (correct upto 7 significant figures)\n"<<endl;
    double x0[100],x1[100];//First 100 positive roots of x = tan x
    for (int i = 1; i < 101; i++)
    {
		 //The initial guess is obtained by observing the intersection of graphs of y=x and y=tanx
		 //? X1 is the singularity and in some cases there is no
		 //? sign change between the two points, e.g., 6th root
		 //? you have not checked for sign change before doing bisection
        x0[i] = i*M_PI;
        x1[i] = (i+ 1.0/2.0)*M_PI;
        cout<<f(x1[i])<<"  In the interval ("<<x0[i]<<", "<<x1[i]<<") "<<endl;
        Bisection_method(i,x0[i], x1[i]);
        
    }

	return 0;
}
