
#include <bits/stdc++.h>
using namespace std;

//To Find the 1st & 2nd derivative of the function by using central difference formula and extrapolation

//To calculate the extrapolation table
void Make_Extrapolation_Table(double Ep_matrix[10][10])
{
    int n = 10;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
		//? you should use the alternate form to control roundoff
            Ep_matrix[j][i] = ((pow(4, i) * Ep_matrix[j][i - 1]) - Ep_matrix[j - 1][i - 1]) / (pow(4, i) - 1);
        }
    }
}

int main()
{
    int n = 10;
    float x , h, pt3_1st_der, pt3_2nd_derv, pt5_1st_derv, pt5_2nd_derv;
    double x_double,h_double, Ep_matrix[10][10], h_values_1[10],h_values_2[10];
 

    //To calculate 1st & 2nd derivative using central difference formula for e^x at x=0
     cout.precision(7); //setting precision for all output
    cout.setf(ios::fixed);

    x = 0.0;
	cout<<"1st & 2nd derivative of e^x at x=0, using 3 and 5 point central difference formula for different h:"<<endl;
    cout<<"________________________________________________________________________________"<<endl;
    cout<<"\t\t   First derivative "<<"\t           Second derivative"<<endl;
	cout<<"  Spacing(h) "<<" \t3-point "<<" \t5-point "<<"\t 3-point "<<"\t 5-point"<<endl;
	cout<<"________________________________________________________________________________"<<endl;
	
	int j,temp[2] = {2,5};
	//? use 1e-6 instead of pow(10,-6)
    for (j=0,h = 1; h > pow(10, -6); h = h / temp[j],j=(j+1)%2)
    {
        pt3_1st_der = (exp(x + h) - exp(x - h)) / (2 * h);//with error = -(h^2/6)f"'(ξ) 
        pt3_2nd_derv = (exp(x - h) - (2 * exp(x)) + exp(x + h)) / (h * h);//with error = -(h^2/12)f""(ξ)
        pt5_1st_derv = (exp(x - (2 * h)) - (8 * exp(x - h)) + (8 * exp(x + h)) - exp(x + (2 * h))) / (12 * h);//with error = (h^4/30)f""'(ξ) 
        pt5_2nd_derv = (-exp(x - (2 * h)) + (16 * exp(x - h)) - (30 * exp(x)) + (16 * exp(x + h)) - exp(x + (2 * h))) / (12 * h * h);//with error = (h^4/90)f"""(ξ)

        cout << "  " << h << "\t" << pt3_1st_der << "\t"  << pt5_1st_derv << "\t"  << pt3_2nd_derv <<"\t" << pt5_2nd_derv << endl;
    }
    cout<<"________________________________________________________________________________\n"<<endl;

    //To calculate 1st & 2nd derivative using central difference formula for tan(x) at x=1.56
    x = 1.56;
    cout << "1st & 2nd derivative of tan(x) at x=1.56, using 3 and 5 point central difference formula for different h:" << endl;
    cout<<"_________________________________________________________________________________"<<endl;
    cout<<"\t\t         First derivative "<<"\t       Second derivative"<<endl;
	cout<<"  Spacing(h) "<<" \t3-point "<<" \t5-point "<<"\t 3-point "<<"\t  5-point"<<endl;
	cout<<"_________________________________________________________________________________"<<endl;
    
    for (j=0,h = 0.01; h > pow(10, -7); h = h / temp[j],j=(j+1)%2)
    {
        pt3_1st_der = (tan(x + h) - tan(x - h)) / (2 * h);//with error = -(h^2/6)f"'(ξ) 
        pt3_2nd_derv = (tan(x - h) - (2 * tan(x)) + tan(x + h)) / (h * h);//with error = -(h^2/12)f""(ξ)
        pt5_1st_derv = (tan(x - (2 * h)) - (8 * tan(x - h)) + (8 * tan(x + h)) - tan(x + (2 * h))) / (12 * h);//with error = (h^4/30)f""'(ξ)
        pt5_2nd_derv = (-tan(x - (2 * h)) + (16 * tan(x - h)) - (30 * tan(x)) + (16 * tan(x + h)) - tan(x + (2 * h))) / (12 * h * h);//with error = (h^4/90)f"""(ξ)
        cout << "  " << h << "\t" << pt3_1st_der << "\t"  << pt5_1st_derv << "\t"  << pt3_2nd_derv <<"   " << pt5_2nd_derv << endl;
    }
    
    cout<<"__________________________________________________________________________________________"<<endl;


    //To calculate 1st derivative using Richardson's extrapolation formula for e^x at x=0
    //? x,h are float while other variables are double. How will that help?
    h = 1.0;
    x = 0.0;

    for (int i = 0; i < n; i++)
    {
        Ep_matrix[i][0] = (exp(x + h) - exp(x - h)) / (2 * h);
        h_values_1[i] = h;
        h = h / 2.0;
    }

    Make_Extrapolation_Table(Ep_matrix); 

    //To print Extrapolation Table

    cout << endl;
    cout << "1st derivative of e^x at x=0 calculated using Richardson's extrapolation:" << endl;
    cout <<"________________________________________________________________________________________________________"<<endl;
    cout << "    h            T0        T1        T2        ......" << endl;
    cout <<"________________________________________________________________________________________________________"<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << h_values_1[i] << "    ";
        for (int j = 0; j <= i; j++)
        {
            cout << Ep_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //To calculate 1st derivative using Richardson's extrapolation formula for tanx at x=1.56

    h = 0.25;
    x = 1.56;

    for (int i = 0; i < n; i++)
    {
        Ep_matrix[i][0] = (tan(x + h) - tan(x - h)) / (2 * h);
        h_values_2[i] = h;
        h = h / 2.0;
        
    }

    Make_Extrapolation_Table(Ep_matrix); 

    //printing the table

    cout << endl;
    cout << "1st derivative of tan(x) at x=1.56 calculated using Richardson's extrapolation:" << endl;
    cout <<"____________________________________________________________________________________________________________________________________"<<endl;
    cout << "    h            T0        T1        T2        ......" << endl;
    cout <<"____________________________________________________________________________________________________________________________________"<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << h_values_2[i] << "   ";
        for (int j = 0; j <= i; j++)
        {
            cout << Ep_matrix[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;

    
    //To calculate 2nd derivative using Richardson's extrapolation formula for e^x at x=0
    h_double = 1.0;
    x_double = 0.0;
    for (int i = 0; i < n; i++)
    {
        Ep_matrix[i][0] = (exp(x_double + h_double) - (2 * exp(x_double)) + exp(x_double - h_double)) / (h_double * h_double);
        h_double = h_double / 2.0;
    }

    Make_Extrapolation_Table(Ep_matrix); 

    //printing the table
    cout << "2nd derivative of e^x at x=0 calculated using Richardson's extrapolation:" << endl;
    cout <<"________________________________________________________________________________________________________"<<endl;
    cout << "    h      T0        T1        T2        ......" << endl;
    cout <<"________________________________________________________________________________________________________"<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << h_values_1[i] << "    ";
        for (int j = 0; j <= i; j++)
        {
            cout << Ep_matrix[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
    
    
    //To calculate 2nd derivative using Richardson's extrapolation formula for tanx at 1.56

    //For 2nd derivative using float type yields much error so double is used.
    //? You have started with too large value of h as points are going beyond
    //? pi/2
    h_double = 0.25;
    x_double = 1.56;
    for (int i = 0; i < n; i++)
    {
        Ep_matrix[i][0] = (tan(x_double +  h_double) - (2 * tan(x_double)) + tan(x_double-  h_double)) / ( h_double *  h_double);
         h_double =  h_double / 2.0;
    }

    Make_Extrapolation_Table(Ep_matrix); 

    //printing the table
    cout << "2nd derivative of tan(x) at x=1.56 calculated using Richardson's extrapolation:" << endl;
    cout <<"_______________________________________________________________________________________________________________________________________________"<<endl;
    cout << "    h      T0        T1        T2        ......" << endl;
    cout <<"_______________________________________________________________________________________________________________________________________________"<< endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << h_values_2[i] << "    ";
        for (int j = 0; j <= i; j++)
        {
            cout << Ep_matrix[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
