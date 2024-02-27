#include <bits/stdc++.h>

using namespace std;

vector<complex<double>> dft(vector<double> X)
{
    int N = X.size();

    int K = N;

    complex<double> intSum;

    vector<complex<double>> output;
    output.reserve(K);
    for (int k = 0; k < K; k++)
    {
        intSum = complex<double>(0, 0);

        for (int n = 0; n < N; n++)

        {

            double realPart = cos((2*M_PI / N) *k*n);
            double imagPart = sin((2*M_PI / N) *k*n);
            complex<double> w(realPart, imagPart);
            intSum += X[n] * w;
        }

        output.push_back(intSum);
    }
    return output;
}

int main()
{
    int N = 256;

    vector<double> sig;

    double f = 60;

    for (int i = 0; i < N; i++)
    {

         sig.push_back(sin(2 * M_PI * f * i / N));
    }

    vector<complex<double>> Fx = dft(sig);
    cout<<"For f=60:\n"<<endl;
    for (int i = 0; i < N; i++)

    {
	    //? why are you dividing by N
        cout << i <<")"<<Fx[i].real()/ static_cast<double>(N)  << " + i(" <<  Fx[i].imag() / static_cast<double>(N) <<")" << endl;
      
    }
    
    f = 60.5;

    for (int i = 0; i < N; i++)
    {
	    //? push_back has added to the previous array making it 512 in
	    //? size. You are getting a totally wrong result

       sig.push_back(sin(2 * M_PI * f * i / N)*(1/2.0)*(1.0-cos(2.0 * M_PI * i / N)));

    }

     vector<complex<double>> Fx2 = dft(sig);
    cout<<"\nFor f=60.5:\n"<<endl;
    for (int i = 0; i < N; i++)

    {
        cout << i <<")"<<Fx2[i].real()/ static_cast<double>(N)  << " + i(" << Fx2[i].imag() / static_cast<double>(N) <<")" << endl;
      
    }

    return 0;
}
