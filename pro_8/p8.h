///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Jonathan Martinez
// LOGIN_NAME: jmartin042
// EE259 SECTION (DAY/EVE): DAY
///////////////////////////////////////////////////////////////
//
//THIS IS SAMPLE P8
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctype.h>

using namespace std;

ofstream o_f_8("output_8.txt", ios::out);

class EZ_DIFF_INTEGRATE
{
   public:
	EZ_DIFF_INTEGRATE(char *); // constructor; 
		// example: s.EZ_DIFF_INTEGRATE("in.txt");
		// input data file is given;

	void EZ_DIFF_BY_ME(float, float, int);
		// example: s.EZ_DIFF_BY_ME(a, b, n);
		// differentiate the function defined in input file;
		
	void EZ_INTEG_BY_ME(float, float, int);
		// example: s.EZ_INTEG_BY_ME(a, b, n);
		// integrate the function defined in input file;
		
   private:
	int np; // number of data pairs
	char func_type[10]; // sin, cos, or poly
	int exp; // exponent of sin or cos 
	int arg; // argument to include in function
};

EZ_DIFF_INTEGRATE::EZ_DIFF_INTEGRATE(char * in_fn)
{
	char TYPE[10];
	char char_tempo[10]; // temp var to hold a string;
	int i_tempo; // temp var to hold an integer;

	o_f_8 << "CONSTRUCTOR WITH INPUT FILE: " << in_fn << endl;
	cout << "CONSTRUCTOR WITH INPUT FILE: " << in_fn << endl;
	// start parsing the input:
	ifstream i_f(in_fn, ios::in);

	////
	int error=0;
	char var [10];
	i_f >> func_type;
	i_f >> char_tempo;
	if(strcmp(func_type,"sin")==0 || strcmp(func_type,"cos")==0)
	{
		if (strcmp(char_tempo,"**")==0)
		{
			i_f >> exp;
			i_f >> char_tempo;
			i_f >> arg;
			i_f >> char_tempo;
			i_f >> var;
		}
		else if (strcmp(char_tempo,"(")==0)
		{
			i_f >> arg;
			exp=1;
			i_f >> char_tempo;
			i_f >> var;
		}
		o_f_8 << "FUNCTION IS PARSED AS: " << func_type << " ** " << exp << "	"<< arg << var << endl;
	}
	else
	{
	o_f_8 << "INPUT ERROR: NOT SIN OR COS" << endl;
	}
	////
}

void
EZ_DIFF_INTEGRATE::EZ_DIFF_BY_ME(float a , float b, int n)
{
	int i;
	float x_new, x_old;
	float x[30]; // x coordinate;
	float df[30]; // first derivative;
	
	////
	int minimum=0;
	int maximum=0;
	////

	if (strcmp(func_type,"sin") == 0)
	{
		// your code to compute differentiation for sin:

		////
		x_old=a;
		x_new=a+((b-a)/n);
	
		for (i=0; i<n; i++)
		{
			df[i]=( pow(sin(arg*x_new),exp)- pow(sin(arg*x_old),exp) ) / (fabs(x_old - x_new));
			x_new+=((b-a)/n);
			x_old+=((b-a)/n);
		}
		////
		
	}
	else if (strcmp(func_type,"cos") == 0)
	{
		// your code to compute differentiation for cos:

		////
		x_old=a;
		x_new=a+((b-a)/n);
	
		for (i=0; i<n; i++)
		{
			df[i]=( pow(cos(arg*x_new),exp)- pow(cos(arg*x_old),exp) ) / (fabs(x_old - x_new));
			x_new+=((b-a)/n);
			x_old+=((b-a)/n);
		}
		////

	}
	
	// report extreme points:

	////
	for (i=0; i<n-1; i++)
	{
		
		if( (df[i]>0 && df[i+1]<0) || (df[i]==0 && df[i+1]<0) )
		{
			o_f_8 << "*** THERE IS AN EXTREME POINT*** df[" << i << "]: " << df[i] << "	df[" << i+1 << "]: " <<  df[i+1]<< endl;
			maximum++;
		}
		else if( (df[i]<0 && df[i+1]>0) || (df[i]==0 && df[i+1]>0) )
		{
			o_f_8 << "*** THERE IS AN EXTREME POINT*** df[" << i << "]: " << df[i] << "	df[" << i+1 << "]: " <<  df[i+1]<< endl;
			minimum++;
		}
	}
	o_f_8 << "THERE ARE " << minimum << " MINIMUMS AND " << maximum << " MAXIMUMS FOR THIS " << func_type << " FUNCTION " << endl;
	o_f_8 << "IN THE INTERVAL OF " << a << " AND " << b << " WITH " << n << " POINTS." << endl;
	////

}

void
EZ_DIFF_INTEGRATE::EZ_INTEG_BY_ME(float a , float b, int n)
{
	int i;
	float x_new, x_old;
	float x[30]; // x coordinate;
	float df[30]; // first derivative;
	float ddf[30]; // second derivative;
	float integral = 0.0;
	float coeff = 0.0;
	float new_term = 1.0;
	
	////
	float MiddleTerm = 0.0;
	float height=(b-a)/n;
	////

	if (strcmp(func_type,"sin") == 0)
	{
		// your code to compute integration for sin:
		
		////
		for (i=1; i<=n-1; i++)
		{
			MiddleTerm+=fabs(pow(sin(arg*(a+i*height)),exp));
		}
		integral=(height/2)*( fabs(pow(sin(arg*a),exp)) + (2*MiddleTerm) + fabs(pow(sin(arg*b),exp)) );
		////
	}
	else if (strcmp(func_type,"cos") == 0)
	{
		// your code to compute integration for cos:
		
		////
		for (i=1; i<=n-1; i++)
		{
			MiddleTerm+=fabs(pow(cos(arg*(a+i*height)),exp));
		}
		integral=(height/2)*( fabs(pow(cos(arg*a),exp)) + (2*MiddleTerm) + fabs(pow((cos(arg*b)),exp)) );
		////
	}

	////
	o_f_8 << "THE INTEGRATION OF THIS " << func_type << " FUNCTION " << endl;
	o_f_8 << "IN THE INTERVAL OF " << a << " AND " << b << " WITH " << n << " POINTS" << " IS "<< integral << endl;
	////
}
