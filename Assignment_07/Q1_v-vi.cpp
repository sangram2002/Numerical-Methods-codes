#include <bits/stdc++.h>
using namespace std;

//function I5
double f5(double n)
{
    double b, a;
    //? why have you used b=1e4. That is too high. You can try 20-50. You
    //? should look at the function to decide the limit.
    b = 1e4;// infinite is the limit
    a = 0;
    double h, temp, x, sum, temp1, temp2;
    sum = 0.0;
    h = (b - a) / n;
    int k = (int)n;

    for (int i = 0; i <= k; i++)
    {
        x = a + (i * h);
        temp1 = 1 / (exp(x) - 1);
        temp2 = exp(-x) / x;
        temp = temp1 - temp2;
        if(isinf(temp)||isnan(temp))
            temp = 0.0;
        if (i == 0 || i == k)
        {

            sum = sum + temp;
        }
        else if (i % 2 != 0)
        {
            temp = temp * 4.0;
            sum = sum + temp;
        }
        else
        {
            temp = temp * 2.0;
            sum = sum + temp;
        }
    }
    sum = h * sum / 3.0;
    return sum;
}
 
//function I6       
//? this integral is divergent.
double f6(double n)
{
    double b, a;
    b = 1;
    a = 0;
    double h, temp, x, sum, temp1;
    sum = 0.0;
    h = (b - a) / n;
    int k = (int)n;

    for (int i = 0; i <= k; i++)
    {
        x = a + (i * h);
        temp1 = x * (log(x));
        temp = 1 / temp1;
        if (isnan(temp) || isinf(temp))
            temp = 0.0;
        if (i == 0 || i == k)
        {
            temp = temp / 2.0;
            sum = sum + temp;
        }
        else
        {
            sum = sum + temp;
        }
    }
    sum = h * sum;
    return sum;
}

//main program starts
int main()
{
    double n,temp;

       //(a) int_{0}^{1} (e^(-5x)cos(10x))/sqrt(x) dx
    n = 1e6;
    cout << "(a)  I_5 = int_{0}^{infty} (1/(e^x - 1) - (e^-x)/x) dx = 0.577215664902" << endl;
    cout << "    no. of points \t\t Answer " << endl;
    temp = 0.0;
    while (abs(temp - f5(n)) >= 1e-4)
    {
        cout << "       " << n << "                " << f5(n) << endl;
        temp = f5(n);
        n = n * 5;
    }
     cout << endl;
    cout << endl;

    //int_{0}^{1} 1/(x ln(x)) dx
    n = 100;
    cout << "(b) I_6 = int_{0}^{1} 1/(x ln(x)) dx " << endl;
    cout << "    no. of points          result " << endl;
    for (int z = 1; z <= 6; z++)
    {
        cout << "       " << n << "                " << f6(n) << endl;
        n = n * 10;
    }
    cout << endl;
    cout << "The integral is divergent as the answer is ln(|ln(x)|) by putting x=1 , it tends to -∞" << endl;

    return 0;
}
