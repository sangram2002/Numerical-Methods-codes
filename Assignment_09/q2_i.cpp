
#include <bits/stdc++.h>

using namespace std;

double f(double y)
{
    return y / tan(y) - log(y / sin(y));
}

// Bisection Method
void Bisection_method(int i,double x0, double x1)
{

	double midpt = x0;
	while (abs(x1-x0) >= 1e-7)
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
    double x=log(midpt/sin(midpt));
	cout << setprecision(7) <<"root of the form x+iy ("<< i+1 <<") = ( x= " << x << " ,y= " << midpt << " )\n" << endl;
	
}

int main()
{

    double y_values[2001];
    double x0[4],x1[4];

    for (int i = 0; i < 2001; i++)
    {
        y_values[i] = -10.0 + 0.01 * i;
    }

    int k=0;
    
    for (int i = 0; i < 2001; i++)
    {
        if (f(y_values[i]) * f(y_values[i + 1]) <= 0)
        {  
            
            x0[k] = y_values[i];
            x1[k] =y_values[i + 1] ;
            k++;
        }
    }
    cout<<endl;
    cout<<" All complex zeros of e^z=z with |x| < 10 and |y| < 10 by Eliminating x between the two equations and \n solving for y {y / tan(y) - log(y / sin(y))=0} (correct upto 7 significant figures):\n"<<endl;
    
    for (int i = 0; i < 4; i++)
    {
        cout<<"  In the interval of y ("<<x0[i]<<", "<<x1[i]<<") "<<endl;
        Bisection_method(i,x0[i], x1[i]);
        
    }


    return 0;
}
