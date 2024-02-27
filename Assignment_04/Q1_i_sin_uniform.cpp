#include <bits/stdc++.h>
using namespace std;

int main()
{
    
double Value;
cout<<"enter value of x at which you want sin(x) by interpolation:"<<endl;
cin>>Value;

    
for (int k = 0; k < 10; k++)
{
    int i, j,n=2*(k+1);
    double temp, sum,x[n+2], y[n+2][25];


    //initialising x Values
    x[0]=-1.0,x[n+1]=1.0;
    for (i = 0; i < n; i++)
    {
        x[i+1]=x[i]+2.0/(1.0*(n+1));
        
    }
    for (i = 0; i < n+2; i++)
    {
     double Deg_to_Rad = (x[i] * M_PI) / 180.0;
        y[i][0] = sin(Deg_to_Rad);   
        
    }

    //Program to make and print Newton's divided difference table

    for (i = 1; i < n+2; i++)
    {
        for (j = 0; j < n+2 - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }

    // cout << " Newton's Forward Difference Table " << endl;
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

    cout << "" << endl;

    
        sum = y[0][0];

        for (i = 1; i < n+2; i++)
        {
            temp = 1.0;
            for (j = 0; j < i; j++)
            {
                temp = temp * (Value - x[j]);
            }
            sum = sum + (temp * y[0][i]);
        }

        cout << "The value of sin(" << Value << ") "<<"with "<< n <<" uniformly spaced points calculated by interpolation = " << setprecision(15)<< sum << endl;
   

    cout<<""<<endl;
    
}
    return 0;
}
