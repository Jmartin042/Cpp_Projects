//
// SKELETON FOR PROJECT 7
//
///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME:
// LOGIN_NAME:
// EE259 SECTION (DAY/EVE):
///////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "/ee259/tools/pro_7/sample_p6.h"

using namespace std;

ofstream o_f_7("output_7.txt", ios::out);

class EZ_CURVE_FIT: public LINEAR_SOLVER
{
   public:
	EZ_CURVE_FIT(int); // constructor; 
		// example: s.EZ_CURVE_FIT(5);
		// there are 5 pairs of data points;

	void LS_FIT_BY_ME(char *); 
		// example: s.LS_FIT_BY_ME("data_file");
		// perform least squares fit using inheritance 
		// data is in "data_file";
		
	void LS_FIT_BY_MATLAB (char *); 
		// example: s.LS_FIT_BY_MATLAB("data_file);
		// perform least squares fit using MATLAB; 
   private:
	int np; // number of data pairs
};
 
// constructor code 
EZ_CURVE_FIT::EZ_CURVE_FIT(int x)
	:LINEAR_SOLVER(2) // call base class constructor, (we need to solve 
	   // a linear equation system of AX=B; dimension of A is 2x2) ;
{
        np = x;
}

void EZ_CURVE_FIT::LS_FIT_BY_ME(char * data_file)
{
	int i, j;
	float S1, S2, S3, S4, S5, S6, error;
	float X[15], Y[15];
	float m, b;		

	// initialize vars:
	error = S1 = S2 = S3 = S4 = S5 = S6 = 0.0;
	m = b = 0.0;

	// read X and Y values:
	ifstream input_data_file(data_file, ios::in);   
	for(i=0; i<np; i++)
        {
        	input_file >> X[i]>> Y[i];
        }
	
	// calculate the S1-S6 values:


	// write them into S_values.txt file in the format that 
	// is sutaible for sample_p6.h to read:
	ofstream out_s_values("S_values.txt", ios::out);
	
	
	// instantiate a LINEAR_SOLVER object:
	LINEAR_SOLVER L("S_values.txt",2);
	// access SOLVE_LINEAR_EQUATION (results are in output.txt file):
	L.SOLVE_LINEAR_EQUATION("UNSORTED");

	// read the results from output.txt file and populate output_7.txt file:

}

void EZ_CURVE_FIT::LS_FIT_BY_MATLAB(char * file_name)
{
   float X[50],Y[50];
   int i,j;
   
   // read data from input file:
   ifstream input_file(file_name,ios::in);
   
   for (i=0;i<np;i++)
   {
   	input_file >> X[i] >>Y[i];
   }
    
   ofstream output_file("mat_1.m",ios::out); 
   // populate mat_1.m file:

   
   // run mat_1.m file: 
   // (make sure that mat1_1.m is good before running automatically by sytem command)
   system("/bin/csh /mnt/ee259dir/tools/pro_7/run_mat_1");
}
