#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i, j, k, m, flag, n = 10, max_itrn = 100;
    double Values[5], x[n], temp, temp1, temp2, sum, y[n][20], s[100], x_estimated[4];

    //initialising x Values
    for (i = 0; i < n; i++)
    {
        x[i] = 1.564 + (0.001 * (i + 1));
        double Deg_to_Rad = (x[i] * M_PI) / 180.0;
        y[i][0] = sin(Deg_to_Rad);
    }

    //Program to make and print Newton's divided difference table

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }

    cout << " Newton's Forward Difference Table Using values of sin x for x = 1.564 + 0.001j, (j = 1,2,...,10):" << endl;
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("\n x(i)\t  y(i)\t     y1(i)\t  y2(i)\t     y3(i)\t  y4(i) .....                                                y9(i)");
    printf("\n_______________________________________________________________________________________________________________________\n");
    for (i = 0; i < n; i++)
    {
        printf("\n %.3f", x[i]);
        for (j = 0; j < n - i; j++)
        {
            printf(" ");
            printf(" %.7f", y[i][j]);
        }
        printf("\n");
    }

    Values[0] = 1.5716;
    Values[1] = 1.5736;
    Values[2] = 1.5635;
    Values[3] = 1.5605;
    Values[4] = 1.5585;

    // Using the table to find f(x) at some values

    cout << "" << endl;

    for (k = 0; k < 5; k++)
    {
        sum = y[0][0];

        for (i = 1; i < n; i++)
        {
            temp = 1.0;
            for (j = 0; j < i; j++)
            {
                temp = temp * (Values[k] - x[j]);
            }
            sum = sum + (temp * y[0][i]);
        }

        cout << "The value of sin(" << Values[k] << ") calculated by interpolation = " << sum << endl;
    }

    cout<<""<<endl;
    double y_value[4] = {0.999995, 0.99995, 0.9999, 0.9995};

    for (k = 0; k < 4; k++)
    {
        temp = y_value[k] - y[0][0];
        s[1] = temp / y[0][1];
        flag = 0;

        for (i = 2; i < max_itrn; i++)
        {
            sum = temp;
            temp1 = s[i - 1];
            temp2 = temp1;

            for (j = 2; j < min(i, n); j++)
            {
                temp2 = temp2 * (temp1 - j + 1) / j;
                sum = sum - y[0][j] * temp2;
            }
            s[i] = sum / y[0][1];

            if ((temp1 - s[i]) < 1e-10)
            {
                flag = 1;
                m = i;
                break;
            }
        }

        if (flag = 0)
        {
            m = max_itrn;
            cout << "successive approximation do not converge in 100 iterations" << endl;
        }
        x_estimated[k] = x[0] + 0.001 * s[m];
        cout << "For sinx = (" << y_value[k] << ") the value of x calculated by inverse interpolation = " << x_estimated[k] << endl;
    }

    return 0;
}
