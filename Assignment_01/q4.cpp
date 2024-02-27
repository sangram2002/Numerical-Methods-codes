#include <bits/stdc++.h>
using namespace std;

//D= Discriminant;a,b,c=constants to be given by the user
double *
calculateRoot(double a, double b, double c)
{

    static double roots[3];

    double D = b * b - 4 * a * c;

    //? what about roundoff
    roots[0] = (-b + sqrt(D)) / (2 * a);

    roots[1] = (-b - sqrt(D)) / (2 * a);

    roots[2] = D;

    return roots;
}

int main()
{

    double a, b, c, D, Root_1, Root_2, Real_part, Imaginary_part;

    double *results;

    cout << "Enter coefficients a, b and c separated with a space: " << endl;

    cin >> a >> b >> c;

    results = calculateRoot(a, b, c);
    Root_1 = *(results);
    Root_2 = *(results + 1);

    D = *(results + 2);

    // For real & distinct roots
    if (D > 0)

    {

        cout << "1st Root = " << scientific << Root_1 << " & "
             << "2nd Root =  " << scientific << Root_2;
    }

    // For repeated real roots
    else if (D == 0)

    {

        Root_1 = Root_2 = -b / (2 * a);

        cout << "1st Root = 2nd Root = " << Root_1;
    }

    // For complex roots
    else

    {

        Real_part = -b / (2 * a);

        Imaginary_part = sqrt(-D) / (2 * a);

        cout << "1st Root = " << scientific << Real_part << " + i" << Imaginary_part << " & 2nd Root = " << Real_part << " - i" << Imaginary_part;
    }

    return 0;
}
