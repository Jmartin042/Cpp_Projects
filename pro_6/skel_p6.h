///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME:
// CITYMAIL LOGIN_NAME:
// EE259 SECTION (DAY/EVE):
///////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "/mnt/ee259dir/tools/pro_5/sample_p5.h"

using namespace std;

class LINEAR_SOLVER: public MATRIX{
   public:
	LINEAR_SOLVER(int);  // constructor 1; 
			// example: s.LINEAR_SOLVER(5);
			// there are 5 equations and 5 variables;
	
	LINEAR_SOLVER(char *, int);  // constructor 2; 
			// example: s.LINEAR_SOLVER("i_f.txt",5);
			// there are 5 eqs and 5 vars in i_f.txt;

	void SOLVE_LINEAR_EQUATION(char *); // example: s.SOLVE_LINEAR_EQUATION("ASCEND");
			// solve the linear equations and
			// sort the output in ascending order;
			// if the input is "DESCEND" then the order
			// of the output is descending;
			// returns no values;

	void SOLVE_BY_MATLAB(void); // example: s.SOLVE_BY_MATLAB();
			// generate and run a MATLAB program to 
			// solve a set of linear equations;
			// returns no values;

	void INHERITED_INVERT(void); // example: s.INHERITED_INVERT();
			// perform matrix inversion on
			// the input system by inheriting
			// from PROGRAM_BANK class;
			// returns no values;

	void INVERT_BY_MATLAB(void); // example: s.INVERT_BY_MATLAB();
			// generate and run a MATLAB program to 
			// invert a matrix;
			// returns no values;
   protected:
	int n; 		// max of n is 50
	float A[50][50];
	float B[50];
};

// constructor 1
LINEAR_SOLVER::LINEAR_SOLVER(int x)
        :MATRIX(x, x) // instantiate P5_MATRIX class with dim1=x dim2=x;
{	

}

// constructor 2
LINEAR_SOLVER::LINEAR_SOLVER(char * p, int x)
        :MATRIX(x, x, p) // instantiate P5_MATRIX class with dim1=x dim2=x;
{	

}

void 
LINEAR_SOLVER::SOLVE_LINEAR_EQUATION(char * command)
{
	 
}

void
LINEAR_SOLVER::SOLVE_BY_MATLAB()
{
	// your doce goes below
	...
	
	// the last statement in this method is:
	system("/bin/csh /mnt/ee259dir/tools/pro_6/run_out_62");
}

void 
LINEAR_SOLVER::INHERITED_INVERT()
{
	
}

void
LINEAR_SOLVER::INVERT_BY_MATLAB()
{
	// your doce goes below
	...
	
	// the last statement in this method is:
	system("/bin/csh /mnt/ee259dir/tools/pro_6/run_out_63");
}
