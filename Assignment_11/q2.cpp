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
    int N = 64;

    vector<double> sig;

    double a =16;

    for (int i = 0; i < N; i++)
    {

         sig.push_back(exp(-2.0 * abs(-a + 2*a*i / N)));
    }

    vector<complex<double>> Fx = dft(sig);
    cout<<"DFT of g(t) = exp(-2|t|):\n"<<endl;
    for (int i = 0; i < N; i++)

    {
        cout << i <<")"<<setw(5) <<"(" <<Fx[i].real()/ static_cast<double>(N)  << " + i" << setw(12) << Fx[i].imag() / static_cast<double>(N) <<")" << endl;
      
    }
    

    return 0;
}