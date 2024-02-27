#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>

double sine(int k)
{
    if (k == 2)
        return 1/sqrt(2);
    return sqrt((1-sqrt(1-pow(sine(k-1),2)))/2);
}

double getArea(int i) {
    return 2*pow(2,i)*sine(i);
}

int
main ()
{
  int i=2;
  double epsilon;
  cout<<"Enter the value of precission you want(for example- 0.001,0.0001 etc.:"<<endl;
  cin >> epsilon;
  while (getArea(i+1)- getArea(i)>=epsilon)
    {
      i = i + 1;
    }
  cout << "No. of iterations:"<< i << endl;
  cout << "value of pi:"<< setprecision(10)<< getArea(i)/2 << endl;
  return 0;
}
