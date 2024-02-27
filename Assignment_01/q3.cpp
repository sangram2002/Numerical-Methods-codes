
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

//function to get the nth decimal place
int getNthDecimal(float val, int n) {
    if(val == 0.0) return 0;
    float limit = pow (10.0, (float) n-1);
    float Result = val;
    while(Result < limit) {
        Result = Result * 10;
    }
    return round(Result);
}

//function to round off till desired digits
//? this will not work for all values
float roundoff (float val, int n)
{
  if(val == 0.0) return 0;
    float limit = pow (10, (float) n);
    return round(val * limit)/limit;
}

float getSum(int start, int num) {
  float sum = 0.0;
  for (int i = start; i > 0; i--) {
    sum += roundoff(1.0/i, num -1);
    sum = roundoff(sum, num -1);
  }
  return sum;
}

int main()
{
    int num, k;
  float sum,prev = 1.0;
  k = 0;
  sum=0.0;

  cout<<"Enter the digit arithmetic you want(for example: 3 or 5 for Q3(a,b,c or d) respectively):"<<endl;
  cin >> num;
  
  //?  you can just check prev!= sum
  while(getNthDecimal(prev,num) != getNthDecimal(sum,num)) {
    prev = sum;
    k++;
    sum += roundoff(1.0/k, num -1);
    sum = roundoff(sum, num -1);
  }
  cout << setprecision(num) << "Sum = "<<sum << ", n=" << k<<endl;
  
  cout << setprecision(num) << "Series sum[backwards starting from 1/(n-1)]= "<< getSum(k-1, num) << endl;
  
  cout << setprecision(num) << "Series sum[backwards starting from 1/(10n)]= "<< getSum(10*k, num) << endl;

    return 0;
}
