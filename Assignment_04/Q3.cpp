#include <bits/stdc++.h>
using namespace std;

double inverse_interpolation(double a[], double b[], int n, double y)
	//? why have you used Lagranges interpolation in this case. You can
	//? use the divided difference formula, by just interchanging the 1st 2 columns
{
    double x = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        double xi = a[i];
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                xi = xi * (y - b[j]) / (b[i] - b[j]);
            }
        }
        x += xi;
    }
    return x;
}

int main()
{
    int i, j, k, n = 8, minutes, hours;
    double Values[4], temp, seconds, sum, y[n][20], y_temp[n], log_y[n], x[n], log_x[n];

    //initialising x Values
    x[0] = 100;
    y[0][0] = 9.58;

    x[1] = 200;
    y[1][0] = 19.19;

    x[2] = 400;
    y[2][0] = 43.03;

    x[3] = 800;
    y[3][0] = 100.91;

    x[4] = 1500;
    y[4][0] = 206;

    x[5] = 5000;
    y[5][0] = 755.36;

    x[6] = 10000;
    y[6][0] = 1571;

    x[7] = 30000;
    y[7][0] = 5207.4;

    //Program to make and print Newton's divided difference table
    //? You are using all points. Should use only a few neighbouring pts

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }

    cout << " Newton's Forward Difference Table:" << endl;
    printf("\n__________________________________________________________________________________________________\n");
    printf("\n x(i)\t  y(i)\t     y1(i)\t  y2(i)\t        y3(i)\t      y4(i) .....                         y7(i)");
    printf("\n__________________________________________________________________________________________________\n");
    for (i = 0; i < n; i++)
    {
        printf("\n %.3f", x[i]);
        for (j = 0; j < n - i; j++)
        {
            printf(" ");
            printf(" %.8f", y[i][j]);
        }
        printf("\n");
    }

    Values[0] = 1000;
    Values[1] = 2000;
    Values[2] = 25000;
    Values[3] = 42195;

    // Using the table to find f(x) at some values

    cout << endl;

    for (k = 0; k < 4; k++)
    {
        sum = y[0][0];

        for (i = 1; i < n; i++)
        {
            temp = 1;
            for (j = 0; j < i; j++)
            {
                temp = temp * (Values[k] - x[j]);
            }
            sum = sum + (temp * y[0][i]);
        }

        //To convert seconds into minutes and hours
        seconds = sum;
        if (seconds >= 60)
        {
            minutes = (int)seconds / 60;
            seconds = sum - (minutes * 60);
            if (minutes >= 60)
            {
                hours = minutes / 60;
                minutes = minutes - (hours * 60);
                cout << " Estimated world record time = " << hours << ":" << minutes << ":" << seconds << "s"
                     << " for distance = " << Values[k] << "m" << endl;
            }
            else

                cout << " Estimated world record time = " << minutes << ":" << seconds << "s"
                     << " for distance = " << Values[k] << "m" << endl;
        }

        else

            cout << " Estimated world record time = " << seconds << "s"
                 << " for distance = " << Values[k] << "m" << endl;
    }

    cout << "\n If we compare the result with the original record 2:11.96s, 4:44.79s, 1:12:25s and 2:01:39s respectively.\n We can clearly observe that it is coming out to be closer to the actual value \n for 1000m and 2000m but for other two the answer is coming out to be useless.\n This is because both the distance and time vary by a few orders of magnitude\n over the range covered by the table(i.e. inherent fluctuations)\n Hence using a log scale is better to estimate. " << endl;

    for (i = 0; i < n; i++)
    {
        y_temp[i] = y[i][0];
        log_x[i] = log(x[i]);
        log_y[i] = log(y_temp[i]);
    }

    cout << "\nDistance covered in one hour by using normal interpolation = " << inverse_interpolation(x, y_temp, 8, 3600) << endl;

    cout << "Distance covered in one hour by using log scale =  " << exp(inverse_interpolation(log_x, log_y, 8, log(3600))) << endl;
    
    cout << "\nBy using normal interpolation we get a meaningless result but by using log scale \nit gives a answer which is near to the actual record i.e. 21330m " << endl;

    return 0;
}
