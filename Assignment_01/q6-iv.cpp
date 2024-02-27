#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>

double sine(int i)
{
    if (i == 2)
        return 1/sqrt(2);
    return sqrt((1-sqrt(1-pow(sine(i-1),2)))/2);
}

double get_circumference(int i) {
    return 2*pow(2,i)*sine(i);
}
int
main ()
{
  int n, j=2;
  double eps;
  cout<<"Enter the value of precission you want(for example- 0.001,0.0001 etc.:"<<endl;
  cin >> eps;
  while (get_circumference(j+1)-get_circumference(j)>=eps)
    {
      j = j + 1;
    }
  cout << "No. of iterations:"<< j << endl;
  cout << "value of pi:"<< setprecision(10)<< get_circumference(j)/2 << endl;
  return 0;
}
