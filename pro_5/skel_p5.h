///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME:
// LOGIN_NAME:
// EE259 SECTION (DAY/EVE):
///////////////////////////////////////////////////////////////
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "/mnt/ee259dir/tools/pro_5/inversion.h"

using namespace std;

ofstream o_f("output.txt", ios::out);

class MATRIX: public PROGRAM_BANK{

	// there are two friend functions:
	friend MATRIX operator / (int, MATRIX); 
			// FRIEND FUNCTION; example: 5 / X;
			// Compute inverse of X using INHERITANCE;
			// Multiply each element of inverted matrix by 5; 
			// store the results into a temp MATRIX;
			// return the temp MATRIX;
	
	friend MATRIX operator * (int, MATRIX); 
			// FRIEND FUNCTION; example: 5 * X;
			// each element of the matrix X is 
			// multiplied by 5;
			// store the results into a temp MATRIX;
			// return the temp MATRIX;

	public:	// public interfaces for this class
	
	  MATRIX (int, int); // constructor;
			// example: MATRIX X(d1,d2);
			// creates a matrix object with
			// private variables dim1 = d1 and dim2 = d2
			// and initializes each element to 0;
  
	  MATRIX(int, int, char *); // constructor;
			// example: MATRIX X(d1,d2,"in_name");
			// read the elements of the matrix
			// from a given file in_name; d1 and d2 are 
			// the two dimensions of the matrix;
				
	  void PRINT(char *);	// example: X.PRINT("W");
			// print the elements of the matrix X
			// into output.txt file;
			// returns no values;

	  int  operator < (int); //example: if( X < b)
			// check if the minimum element of the matrix X
			// is less than b
			// returns 1 if so; returns 0 otherwise;
	
	  void operator = (MATRIX ); // example X = Y;
			// Copy Y to X;
			// returns no values;		
		
	  void operator += (MATRIX);  // example: X += Y;
                        // matrix addition;
                        // store the results in X;
			// values of Y remain unchanged;
			// returns no values;
		
	  void operator *= (MATRIX); // example: X *= Y;
			// matrix multiplication;
			// store the results in X;
			// values of Y remain unchanged;
			// returns no values;

	  MATRIX operator + (MATRIX); // example: X + Y;
			// Create a temp matrix object; 
			// add each element of Y to each element of X;
			// return this temp matrix object;
			// values of X and Y remain unchanged;

	  MATRIX operator * (MATRIX); // example: X * Y;
			// matrix multiplication;
			// store the results into a temp matrix
			// and return this temp matrix;
			// values of Y remain unchanged;

	  MATRIX operator / (MATRIX); // example: X / Y;
			// get inverse of Y and multiply it with X;
			// put the results into a temp MATRIX
			// and return temp MATRIX;
			// X and Y remain unchanged;
			// USE INHERITENCE FOR MATRIX INVERSION;
	
	protected:
  	  int dim1, dim2; // dimensions of the matrix;
			// if dim2 is 1, a vector (no need for special
			// handling of vectors; everything should work
			// for both matrices and vectors)

  	  double A[20][20]; // 2 dimensional array for the matrix elements;
	  char in_file[11]; // hold the input file name
 };


// FIRST CONSTRUCTOR
MATRIX::MATRIX(int d1, int d2)
        :PROGRAM_BANK(d1) // CALL THE CONSTRUCTOR OF THE BASE CLASS
{
	 // your constructor code goes below:
     int i, j;
     dim1 = d1;
     dim2 = d2;
     
     if(d1 < 0 || d1 > 20 || d2< 0 || d2 >20)
     {
	  return;
     }
     else
     {
     	for (i= 0; i < dim1; i++)
     	{
         	for (j= 0; j < dim2; j++)
         	{
             		A[i][j] = 0;
         	}
     	}
     }
}

// SECOND CONSTRUCTOR
MATRIX::MATRIX(int d1, int d2, char * file_name)
        :PROGRAM_BANK(d1, file_name) // CALL THE CONSTRUCTOR OF THE BASE CLASS
{
	int i, j;
	o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
           
	if(d1 < 0 || d1 > 20 || d2< 0 || d2 >20)
	{
		o_f <<"+++ P5_OUTPUT >>> INPUT ERROR" 
           	       << endl
           	       <<"+++ P5_OUTPUT >>> UNABLE TO CREATE MATRIX" 
           	       << endl
           	       <<"+++ P5_OUTPUT >>> EXITING PROGRAM" 
           	       << endl
          	       << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" 
          	       << endl;
           //exit (1);
		return;
	}    
	else
	{
		dim1 = d1;
		dim2 = d2;
		// copy the input file name to private variable in_file
		strcpy(in_file, file_name);

		//define the input_filein this current block
		ifstream input_file(in_file, ios::in);

		for (i =0; i < dim1; i++)
		{
			for(j = 0; j < dim2; j++)
			{
				input_file >> A[i][j];
			}
		}
		input_file.close(); // close input file;
		input_file.clear(); // rewind file pointer to the top of the file;
		o_f <<"+++ P5_OUTPUT >>> CREATED A " << dim1 <<" X " << dim2 
			<<" MATRIX FROM " << in_file << endl;
	} 
	o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}

// friend function
MATRIX operator / (int c, MATRIX a_matrix_obj)
{ // your code goes below:
	MATRIX temp_matrix_obj(a_matrix_obj.dim1, a_matrix_obj.dim2);
     
	return temp_matrix_obj;
}

// friend function
MATRIX operator * (int c, MATRIX a_matrix_obj)
{ // your code goes below:
     MATRIX temp_matrix_obj(a_matrix_obj.dim1, a_matrix_obj.dim2);
     
     return temp_matrix_obj;
}

void
MATRIX::PRINT(char * NAME)
{ // your code goes below:

}

int
MATRIX::operator < (int b)
{ // your code goes below:

        return 0; // make sure to modify this in your code
}

void
MATRIX::operator = (MATRIX  a_matrix)
{ // your code goes below:

}

void
MATRIX::operator += (MATRIX a_matrix)
{ // your code goes below:

}

void
MATRIX::operator *= (MATRIX a_matrix)
{ // your code goes below:

}

MATRIX
MATRIX::operator + (MATRIX a_matrix)
{
        MATRIX temp_matrix(dim1, dim2);
	// your code goes below:


        return temp_matrix;
}

MATRIX
MATRIX::operator * (MATRIX a_matrix)
{
        MATRIX temp_matrix(dim1, dim2);
	// your code goes below:


        return temp_matrix;
}

MATRIX
MATRIX::operator / (MATRIX a_matrix)
{
        MATRIX temp_matrix(dim1, dim2);
	// your code goes below:

        return temp_matrix;
}
