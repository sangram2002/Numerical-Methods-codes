#include <bits/stdc++.h>
using namespace std;

int main()
//optimum value for x is estimated for each problems.
{
    //Code for Q1 (iv)
    int i, k = 0;
    float m = 1.0, x = 1.0, cur = 1.0, prev = 100.0, sum = 0, func;

    while (abs(prev) > abs(cur))
    {
        i++;
        prev = cur;
        func = (1 + (x / m));
        cur = pow(func, m) - exp(x);
        m = m * 2.0;
    }

    cout << "pow(1+(x/m),m)-exp(x) for m tends to ∞ = " << prev << endl;
    cout << "No. of iterations: " << (i - 1) << endl;

    //Code for Q1 (v)
    m = 1.0, x = 1.0, cur = 2.0, prev = 100.0, sum = 0, func;

    while (abs(cur - prev) >= 1e-30)
    {
        k++;
        prev = cur;
        sum = 0.0;
        for (i = 1; i <= m; i++)
        {
            sum = sum + (1.0 / i);
        }

        cur = sum - log(m);

	//? you need to increase by a factor of 2. The limit is not correct.
	//? the correct value is 0.577215
        m = m + 1.0;
    }

    cout << "Σ1/i-ln(m) for m tends to ∞ = " << prev << endl;
    cout << "No. of iterations: " << (i - 1) << endl;

    return 0;
}
