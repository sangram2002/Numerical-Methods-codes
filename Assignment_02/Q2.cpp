#include <bits/stdc++.h>
using namespace std;

int main()
{
    float x, f_0 = 1; //f(0)=1 for function f = exp(x)
    cout << "Enter the Value of the power of e you want to find(for example:±0.1,±1.0,±20,±50 etc) ";
    cin >> x;
    float cur = 0, prev = 1;
    int i = 0;
    while (abs(cur - prev) >= 1e-300)
    {
        prev = cur;
        cur = cur + f_0;
        i++;
        f_0 = f_0 * (x / i);
    }
    cout << "Value of e^" << x << " calculated = " << setprecision(15) << prev << endl;
    cout << "Value of the in-built function(exp(x))= " << setprecision(15) << exp(x) << endl;
    cout << "Steps it takes to converge:" << i - 1 << endl;
    cout << "Percentage Error = " << (abs(cur - exp(x)) * 100) / exp(x) << endl;
    cout << " The Percentage Error for the values -20 and -50 is very large because \n of the overflow as for single precision arithmetic the range is from \n 2^(−126) ≈ 1.18e-38 to 3.4e-38. So,to improve the results instead of \n single precission double precission should be used." << endl;
    //? double precision will not help, for x<0 use exp(x)=1/exp(-x)
    return 0;
}
