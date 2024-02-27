#include <bits/stdc++.h>
using namespace std;

int main()
{

    double Value;
    cout << "Enter value of x at which you want 1/(1+25*x**2) by interpolation:" << endl;
    cin >> Value;

    for (int k = 0; k < 10; k++)
    {
        int i, j, n = 2 * (k + 1);
        double temp, temp1, sum, x[n + 2], y[n + 2][25];

 //initialising x Values
 //? These are not Chebyshev points, why are they needed. Only n pts defined
 //? in the loop are needed.
    x[0]=-1.0,x[n+1]=1.0;
    for (i = 0; i < n; i++)
    {
        
        temp=((2.0*(i+1))-1)* M_PI;
        x[i+1]=cos(temp/(2.0*n));
       
    }
    
    for (i = 0; i < n+2; i++)
    {
     temp = (x[i] * x[i]);
            temp1 = 1.0 + (25.0 * temp);
            y[i][0] = 1.0 / temp1; 
        
    }

        //Program to make and print Newton's divided difference table

        for (i = 1; i < n + 2; i++)
        {
            for (j = 0; j < n + 2 - i; j++)
            {
                y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
            }
        }

        // cout << " Newton's Forward Difference Table " << endl;
	//? This is divided difference not forward difference
        // printf("\n_______________________________________________________________________________________________________________________\n");
        // printf("\n x(i)\t  y(i)\t     y1(i)\t  y2(i)\t     y3(i)\t  y4(i) .....                                                y9(i)");
        // printf("\n_______________________________________________________________________________________________________________________\n");
        // for (i = 0; i < n+2; i++)
        // {
        //     printf("\n %.3f", x[i]);
        //     for (j = 0; j < n+2 - i; j++)
        //     {
        //         printf(" ");
        //         printf(" %.7f", y[i][j]);
        //     }
        //     printf("\n");
        // }

        // Using the table to find f(x) at some values
	//? How will you get the error distribution using only 1 value?

        cout << "" << endl;

        sum = y[0][0];

        for (i = 1; i < n + 2; i++)
        {
            temp = 1.0;
	    //? this loop is not needed as you can use temp=temp*(Value-x[i-1])
            for (j = 0; j < i; j++)
            {
                temp = temp * (Value - x[j]);
            }
            sum = sum + (temp * y[0][i]);
        }

	//? you also need to compare with exact value to find error
        cout << "The value of 1/[1+25*(" << Value << "^2)] "
             << "with " << n << " Chebyshev points calculated by interpolation = "<< setprecision(15) << sum << endl;

        cout << "" << endl;
    }
    //? How can you make this statement using only 1 value of x?
cout<<"\n Contrary to the case of uniformly spaced points the Chebyshev points are best and most reliable as \n it gives the correct answer for almost all values ( it minimises P_n(x))."<<endl;
    return 0;
}
