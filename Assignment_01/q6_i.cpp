#include<bits/stdc++.h>

using namespace std;
//? you were not supposed to write program for this Q,

int main()
{
    int i=1;
    float num, prev_sum = 1000.0, sum=4.0;
    
    cout << "Enter the value of precision you want(for example- 0.001,0.0001 etc.):" << endl;
    cin >> num;
//To calculate absolute value abs is used
    while (abs(sum - prev_sum) > num)
    {
        prev_sum = sum;
        sum = sum + (4.0 / (2 * i + 1)) * pow((-1), i);
        i++;
    }
    cout << "No. of iterations:" << i << endl;
    cout << setprecision(10)<< "value of pi:" << sum;
    return 0;
}
