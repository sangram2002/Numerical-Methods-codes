
#include<bits/stdc++.h>
using namespace std;

int factorial(unsigned int n)
{
  if(n == 0) return 1;
  int product = 1;
    for(int i=1;i<n+1;i++) {
      product*=i;
    }
    return product;
}
int
main ()
{
  float num, prev_sum=10000.0, sum=0.0;
  int i=0;
  cout<<"Enter the value of precisumion you want(for example- 0.001,0.0001 etc.:"<<endl;
  cin >> num;
  while (abs(sum-prev_sum)>num)
    {
      prev_sum=sum;
      sum = sum + (6*factorial(2*i)*pow(0.5,2*i+1)/((2*i+1)*pow(pow(2,i)*factorial(i),2)));
      i++;
    }
  cout << "NNo. of iterations:" << i << endl;
  cout << setprecision(10)<< "value of pi:"<< sum << endl;
  return 0;
}
