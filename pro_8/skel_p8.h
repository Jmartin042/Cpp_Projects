///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: UMIT UYAR
// LOGIN_NAME: ee259
// EE259 SECTION (DAY/EVE): BOTH
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

}

void
EZ_DIFF_INTEGRATE::EZ_DIFF_BY_ME(float a , float b, int n)
{
	int i;
	float x_new, x_old;
	float x[30]; // x coordinate;
	float df[30]; // first derivative;
	
	if (strcmp(func_type,"sin") == 0)
	{
		// your code to compute differentiation for sin:

	}
	else if (strcmp(func_type,"cos") == 0)
	{
		// your code to compute differentiation for cos:

	}

	// report extreme points:

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
	
	if (strcmp(func_type,"sin") == 0)
	{
		// your code to compute integration for sin:

	}
	else if (strcmp(func_type,"cos") == 0)
	{
		// your code to compute integration for cos:

	}
}
