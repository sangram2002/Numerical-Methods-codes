#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main()
{
	long double actual_answer = pow(M_PI,2)/6,lower = 0, upper = 1, n, h, f_value, answer = 0.0;
	n = 10;

	while (abs(actual_answer - answer) >= 1e-3)
	{

		n = 2 * n;
		h = (upper - lower) / n;
		int int_n = (int)n;
		long double xy_values[int_n + 1];
		for (int i = 0; i <= int_n; i++)
		{
			xy_values[i] = lower + (i * h);
		}
		
		//? there is no need to store all these
		long double f[int_n + 1][int_n + 1];
		for (int i = 0; i <= int_n; i++)
		{
			for (int j = 0; j <= int_n; j++)
			{
				f[i][j] = 1 / (1 - (xy_values[i] * xy_values[j]));
				// cout<<	f[i][j]<<endl;
			}
		}
		long double fx[int_n + 1];
		long double answer;
		//? no need for the second loop. the condition for
		//? index i can be put in this loop itself
		//? if w1 and w2 are weights in x and y then
		//? if(i==0 || i==n) w1=1;
		//  else if(i%2 != 0) w1=4; else w1=2;
		//  similarly for w2 and then
		//  sum=sum+f*w1*w2
		for (int i = 0; i <= int_n; i++)
		{
			answer = 0.0;
			for (int j = 0; j <= int_n; j++)
			{
				f_value = f[i][j];
				if (isinf(f_value) || isnan(f_value))
					f_value = 0.0;
				if (j == 0 || j == int_n)
				{

					answer = answer + f_value;
				}
				else if (j % 2 != 0)
				{
					f_value = f_value * 4.0;
					answer = answer + f_value;
				}
				else
				{
					f_value = f_value * 2.0;
					answer = answer + f_value;
				}
			}
			answer = h * answer / 3.0;
			fx[i] = answer;
		}

		answer = 0.0;
		for (int i = 0; i <= int_n; i++)
		{
			f_value = fx[i];
			if (isinf(f_value) || isnan(f_value))
				f_value = 0.0;
			if (i == 0 || i == int_n)
			{

				answer = answer + f_value;
			}
			else if (i % 2 != 0)
			{
				f_value = f_value * 4.0;
				answer = answer + f_value;
			}
			else
			{
				f_value = f_value * 2.0;
				answer = answer + f_value;
			}
		}
		answer = h * answer / 3.0;
		cout << "Value of I_1 = " << setprecision(10) << answer << ", having error wrt actual answer = " << abs(answer - actual_answer ) << endl;
	}

	return 0;
}
