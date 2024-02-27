#include <bits/stdc++.h>
using namespace std;

//Program to integrate specific functions by trapezoid and simpson's rule

int main()
{

	long double n=1e5,a,b,temp1,temp2 = 0.0,temp3, Result = 0.0, h, x;

//(a) x^x from 0 to 1
	a = 0;b = 1;
	h = (b - a) / n;
	//? start with smaller n and increase it by a factor of 2, to check
	//? for convergence
	
	for (int i = 0; i <= (int)n; i++)
	{
		x = a + (i * h);
		if (i == 0 || i == (int)n)
		{
			temp1 = (pow(x, x)) / 2.0;
			Result = Result + temp1;
		}
		else
		{
			temp1 = pow(x, x);
			Result = Result + temp1;
		}
	}
	Result = h * Result;
    
    cout << "Result of the integrations of Question 1 are:\n"<<endl;
	cout << "(a) I_1 = " << setprecision(12)<<Result << endl;

//(b) (e^(-x-1/x))/x^20 from 0 to 1
	Result = 0.0;
	a = 0;b = 1;
	h = (b - a) / n;
	
	for (int i = 1; i <= (int)n; i++)//To avoid 1/0=inf case [as integration for i=0 is negligible so it can be ignored]
	{
		x = a + (i * h);
		temp2 = x + (1 / x);
		
		if (i == 0 || i == (int)n)
		{
			temp1 = ((exp(-temp2)) / pow(x, 20)) / 2.0;
			Result = Result + temp1;
		}
		else
		{
			temp1 = ((exp(-temp2)) / pow(x, 20));
			Result = Result + temp1;
		}
	}
	Result = h * Result;

	cout << "(b) I_2 = " << Result << endl;

//(c) ln(1/x)*sin(x) from 0 to 1
	Result = 0.0;
	a = 0,b = 1;
	h = (b - a) / n;
	
	for (int i = 0; i <= (int)n; i++)
	{
		x = a + (i * h);
		temp1 = (log(1 / x) * sin(x));

		if (i==0)
			temp1 = 0.0;

		if (i == (int)n)
		{
			temp1 = temp1 / 2.0;
			Result = Result + temp1;
		}
		else
		{
			Result = Result + temp1;
		}
	}
	Result = h * Result;

	cout << "(c) I_3 = " << Result << endl;

//(d) (2/sqrt(pi))*e^-(x^2) from 0 to x ; x=1, 5, 10
	long double Result_x[3];
	long double x_values[3] = {1, 5, 10};

	for (int j = 0; j < 3; j++)
	{
		Result = 0.0;
		a=0, b = x_values[j];
		h = (b - a) / n;

		for (int i = 0; i <= (int)n; i++)
		{
			x = a + (i * h);
			temp1 = (2 / sqrt(M_PI)) * (exp(-(pow(x, 2))));
			if (i == 0 || i == (int)n)
			{
				temp1 = temp1 / 2.0;
				Result = Result + temp1;
			}
			else
			{
				Result = Result + temp1;
			}
		}
		Result = h * Result;
		Result_x[j] = Result;
	}
    
    cout << "(d)"<<endl;
	cout << "(i)   I_4(For x=1) = " << Result_x[0] << endl;
	cout << "(ii)  I_4(For x=5) = " << Result_x[1] << endl;
	cout << "(iii) I_4(For x=10) = " << Result_x[2] << endl;

//(e)  e^(1/x) from a to 1; a=0.2, 0.1, 0.01, 0.002 by simpson's 1/3 rule to minimise the error more as compared to trapezoid rule 
//? In this case it is better to add the results over intervals (0.2,1), (0.1,0.2) (0.01,0.1) ...
//? that would choose different h in different interval, giving better results.
	long double Result_a[4], a_values[4] = {0.2, 0.1, 0.01, 0.002};

	for (int j = 0; j < 4; j++)
	{
		Result = 0.0;
		a = a_values[j],b = 1;
		h = (b - a) / n;

		for (int i = 0; i <= (int)n; i++)
		{
			x = a + (i * h);
			temp1 = exp(1 / x);
			if (i == 0 || i == (int)n)
			{
				Result = Result + temp1;
			}
			else if (i % 2 != 0)
			{
			    temp1 = temp1*4.0;
				Result = Result + temp1;
			}
			else
			{   
			    temp1 = temp1*2.0;
				Result = Result + temp1;
			}
		}
		Result = h * Result/ 3.0;
		Result_a[j] = Result;
	}
    
	cout << "(e)"<<endl;
	cout << "(i)   I_5(For a=0.2) = " << Result_a[0] << endl;
	cout << "(ii)  I_5(For a=0.1) = " << Result_a[1] << endl;
	cout << "(iii) I_5(For a=0.01) = " << Result_a[2] << endl;
	cout << "(iv)  I_5(For a=0.002) = " << Result_a[3] << endl;
	cout << endl;

//(f) W(x) from 0.1 to 0.2 , where W(x)=(1/pi)*(Sum_{j=1}^{infty}2^-j cos(7^j pi x))

	Result = 0.0;
	a = 0.1,b = 0.2;
	h = (b - a) / n;
	
	for (int i = 0; i <= (int)n; i++)
	{
		x = a + (i * h);
		//function to approximate Weiestrass continuous nondifferential function
		temp3=0.0;
		//? what about the end points?
    	for (int j = 1; j <= 100; j++)
    	{
    	    
    		temp1 = pow(2, -j);
    		temp2 = pow(7, j),
    		temp3 = temp3 + (temp1 * cos(temp2 * M_PI * x));
    	}
    	temp3 = temp3 / M_PI;
		
		Result = Result + temp3;
	}
	Result = h * Result;

	cout << "(f) I_6 = " << Result << endl;

	return 0;
}
