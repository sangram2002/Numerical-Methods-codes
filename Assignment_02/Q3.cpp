#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, c, k, n , m;    
    double J[32], norm_const; 
    c = 0;
    J[0] = 0.7651976865;
    J[1] = 0.4400505857;

    for (i = 2; i <= 30; i++)
//calculating value of Bessel function using recurrrence relation
    {
        J[i] = (2 * (i - 1) * J[i - 1]) - J[i - 2]; 
    } 

    cout << "The Bessel functions from J_0 to J_30, calculated in forward direction by using J_0 & J_1: " << endl;
    cout << "\tS No."
         << "\t|\t"
         << "Function value" << endl;

    for (i = 0; i <= 30; i++) 
    {
        cout << "\t" <<"J_"<< i << "\t|\t" << J[i] << endl; 
	//? you can print the exact value using jn(n,x)
    }                                                

    cout << "The recurrence is unstable in the forward direction." << endl;
    cout << endl;
    cout << endl;

    //Calculation of Bessel function in backward direction by using J_m=1 and J_m+1=0
    cout << "Calculation of Bessel function in backward direction by using J_m=1 and J_m+1=0:" << endl;
    cout << "Enter the value of m (For last but 1 Bessel function for example:10, 20 or 30)" << endl;
    cin >> m;

    J[m+1] = 0.0;
    J[m] = 1.0;

    //calculating the Bessel function
    for (i = m-1; i >= 0; i--)
    {
        J[i] = ((2 * (i + 1)) * J[i + 1]) - J[i + 2];
    }

    norm_const = J[0];

    //calculating the normalization constant
    for (i = 2; i <= m; i = i + 2)
    {

        norm_const = norm_const + (2 * J[i]);
    }
    cout<<"Normalization constant = "<<norm_const<<endl;
    cout << "\tS No."
         << "\t|\t"
         << "Function value" << endl;
    for (i = 0; i <= m; i++)
    {
        cout << "\t" <<"J_"<< i << "\t|\t" << J[i] / norm_const << endl;
    }

    return 0;

}
