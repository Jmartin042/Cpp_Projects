///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME:Jonathan Martinez
// LOGIN_NAME:jmarin042
// EE259 SECTION (DAY/EVE):DAY
///////////////////////////////////////////////////////////////
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "/mnt/ee259dir/tools/pro_5/inversion.h"
//#include "/home/jmartin042/ee259d15/test/pro_5/inversion.h" //my own computer my own file

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
		o_f <<"+++ P5_OUTPUT >>> INPUT ERROR" << endl;
        o_f <<"+++ P5_OUTPUT >>> UNABLE TO CREATE MATRIX" << endl;
        o_f <<"+++ P5_OUTPUT >>> EXITING PROGRAM" << endl;
        o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++"<< endl;
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
	
	MATRIX temp_matrix_obj(a_matrix_obj.dim1, a_matrix_obj.dim2); //constructor1, temp matrix takes on dimensions of a_matrix_obj

	o_f<<"+++ P5 START +++++++++++++++++++++++++++++++++++++++++"<<endl;

	int i,j,k;
	a_matrix_obj.INVERT_MATRIX("OUT_5_TEMP.txt"); //inverts a_matrix_obj, places into txt file
	ifstream input_file("OUT_5_TEMP.txt",ios::in); //declares the txt file as source of input when used with input_file >>

	MATRIX INV_MATRIX(20, 20); //create new matrix with new name "INV_MATRIX"
	
	INV_MATRIX.dim1=a_matrix_obj.dim1; //match the dimensions
	INV_MATRIX.dim2=a_matrix_obj.dim2;

	for(i=0;i<INV_MATRIX.dim1;i++)//fills INV_MATRIX with elements from the txt file
	{
		for(j=0;j<INV_MATRIX.dim2;j++)
		{
			input_file >> INV_MATRIX.A[i][j]; 
		}
	}
	for (i=0;i<INV_MATRIX.dim1;i++) // multiplies the inv_matrix by c
    {  		
		for(j=0;j<INV_MATRIX.dim2;j++)
     	{
     		temp_matrix_obj.A[i][j]=c * INV_MATRIX.A[i][j];
     	}	
	}
	o_f<<"+++ P5_OUTPUT >>> THE RESULT OF FRIEND FUNCTION FOR OPERATOR / IS:"<<endl;
	for(i = 0; i < temp_matrix_obj.dim1; i++)
    {
    	for(j = 0; j < temp_matrix_obj.dim2; j++)
    	{
           o_f <<setprecision (2) << setiosflags(ios::fixed | ios::showpoint) <<temp_matrix_obj.A[i][j] << " ";                       
        }
        o_f << endl;
    }
    o_f<<"+++ P5 END +++++++++++++++++++++++++++++++++++++++++++"<<endl;
     
	return temp_matrix_obj; 
}

// friend function
MATRIX operator * (int c, MATRIX a_matrix_obj)
{ // your code goes below:
    MATRIX temp_matrix_obj(a_matrix_obj.dim1, a_matrix_obj.dim2);// constructor 1,  new temp_matrix_obj takes on dimensions from a_matrix_obj
	int i,j;
	o_f <<"+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
	  
	for(i=0;i<a_matrix_obj.dim1;i++) //multiplies a_matrix_obj by c, element by element  
	{
	  	for(j=0;j<a_matrix_obj.dim2;j++)
	  	{
	  		temp_matrix_obj.A[i][j]=c*a_matrix_obj.A[i][j];
	  	}
	}
	o_f<<"+++ P5_OUTPUT >>> THE RESULT OF FRIEND FUNCTION FOR OPERATOR * IS:"<<endl;
	for(i=0;i<temp_matrix_obj.dim1;i++)
	{
		for(j=0;j<temp_matrix_obj.dim2;j++)
	  	{
	  		o_f <<setprecision (2) << setiosflags (ios::fixed | ios::showpoint)<<temp_matrix_obj.A[i][j] <<" ";	
	  	}
	  	o_f<<endl;
	}
	o_f <<"+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
	 
     return temp_matrix_obj;
}

void
MATRIX::PRINT(char * NAME)
{ // your code goes below:
	o_f<< "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
	o_f << "+++ P5_OUTPUT >>> CONTENTS OF MATRIX " << NAME << " IS:" << endl;
	int i, j;
	for (i=0; i<dim1 ;i++)//simple output code into output.txt
	{
		for(j=0;j<dim2;j++)
		{
			o_f << setprecision(2) << setiosflags(ios::fixed |ios::showpoint) << A[i][j] << " ";
		}
		o_f<<endl;
	}
	o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;

}

int
MATRIX::operator < (int b)
{ // your code goes below:

	o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
	int i,j,FOUND=0,k;
	for (i=0; i<dim1 && FOUND==0; i++)
	{
		for ( j=0; j<dim2 && FOUND==0; j++)// checks if any element in base matrix is <b
		{
			if (A[i][j]<b)
			{
				FOUND=1;
			}
		}
	}
	if (FOUND==1)
	{
		o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR < RETURNING TRUE" << endl;
		k= 1;
	}
	else if (FOUND==0)
	{
		o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR < RETURNING FALSE" << endl;
		k= 0;
	}
	else{}
	o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
	return k; // make sure to modify this in your code
}

void
MATRIX::operator = (MATRIX  a_matrix)
{ // your code goes below:
	o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
	int i,j;
	if ( dim1==a_matrix.dim1 && dim2==a_matrix.dim2 )// checks if base matrix and a_matrix are same dimensions
	{
		for ( i=0; i<dim1; i++)
		{
			for ( j=0; j<dim2; j++)// copies a_matrix into base matrix
			{
				A[i][j]=a_matrix.A[i][j];
			}
		}
		o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR = COMPLETED" << endl;
	}
	else 
	{
		o_f	<< "+++ P5_OUTPUT >>> ERROR" << endl
			<< "+++ P5_OUTPUT>>> INCOMPATIBLE MATRICES" << endl;
		
	}
	o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;

}

void
MATRIX::operator += (MATRIX a_matrix)
{ // your code goes below:
	int i,j;
	o_f<<"+++ P5 START +++++++++++++++++++++++++++++++++++++++++"<<endl;
	if(dim1==a_matrix.dim1 && dim2==a_matrix.dim2)// checks dimensions
	{
		for(i=0;i<dim1;i++)// adds base matrix and a_matrix and overides into base matrix
		{
			for(j=0;j<dim2;j++)
			{
				A[i][j]=A[i][j]+a_matrix.A[i][j];
			}
		}
		o_f<<"+++ P5_OUTPUT >>> OVERLOADED OPERATOR += COMPLETED"<<endl;
	}
	else
	{
		o_f	<<"+++ P5_OUTPUT >>> ERROR"<<endl
			<<"+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES"<<endl;
	}
	o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void
MATRIX::operator *= (MATRIX a_matrix)
{ // your code goes below:
	o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
	
	int i,j,k;
	if(dim2==a_matrix.dim1)//checks for compatible dimensions to perform matrix multiplication
    {
		MATRIX temp_matrix(dim1,a_matrix.dim2); //constructor 1,new temp matrix takes on dimension dim1 from base array, and dim2 from a_matrix
     
     	for (i=0;i<dim1;i++) //MATRIX MULTIPLICATION of base matrix and a_matrix into temp_matrix
     	{
     		for(j=0;j<a_matrix.dim2;j++)
     		{
     			for(k=0;k<dim2;k++)
     			{
     				temp_matrix.A[i][j]=temp_matrix.A[i][j]+A[i][k]*a_matrix.A[k][j];
     			}
     		}
     	}
     	dim1=temp_matrix.dim1; //overrides the base matrix dimension values with values from temp_matrix
     	dim2=temp_matrix.dim2;
     	for(i=0;i<dim1;i++)  //overrides base matrix with temp_matrix
     	{
     		for(j=0;j<dim2;j++)
     		{
     			A[i][j]=temp_matrix.A[i][j];
     		}
     	}

     	o_f<<"+++ P5_OUTPUT >>> OVERLOADED OPERATOR *= COMPLETED"<<endl;
     
    }
    else if(dim2!=a_matrix.dim1)
	{
		o_f	<<"+++ P5_OUTPUT >>> ERROR" << endl
			<<"+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES"<< endl;
	}
	 o_f<<"+++ P5 END +++++++++++++++++++++++++++++++++++++++++++"<<endl;
}

MATRIX
MATRIX::operator + (MATRIX a_matrix)
{
	MATRIX temp_matrix(dim1, dim2);
	// your code goes below:
    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
	
	if ( dim1==a_matrix.dim1 && dim2==a_matrix.dim2 )// checks for correct dimensions to perform matrix addition
	{	
		for (int i=0; i<dim1; i++)// copies result of the addition into temp_matrix
		{
			for (int j=0; j<dim2; j++)
			{
				temp_matrix.A[i][j]=A[i][j]+a_matrix.A[i][j];
			}
		}
		o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR + COMPLETED" << endl;// does not override base matrix
		o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
		return temp_matrix;
	}
	else
	{
		o_f << "+++ P5_OUTPUT >>> ERROR" << endl;
		o_f << "+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES" << endl;
		o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
	}

        return temp_matrix;
}

MATRIX
MATRIX::operator * (MATRIX a_matrix)
{
        MATRIX temp_matrix(dim1, dim2);//constuctor 1, new temp_matrix takes on dimensions from base matrix
	// your code goes below:

	 int i,j,k;
	 o_f <<"+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;

     if(dim2==a_matrix.dim1)//checks for correct dimensions to perform matrix multiplication
     {
     	temp_matrix.dim1=dim1;// if correct temp_matrix has these corresponding dimensions for further use
     	temp_matrix.dim2=a_matrix.dim2;

     	for (i=0;i<temp_matrix.dim1;i++)//MATRIX MULTIPLICATION if base matrix and a_matrix into temp_matrix
     	{
     		for(j=0;j<temp_matrix.dim2;j++)
     		{
     			for(k=0;k<dim2;k++)
     			{
     				temp_matrix.A[i][j]=temp_matrix.A[i][j]+A[i][k]*a_matrix.A[k][j];
     			}
     		}
     	
     	}
     	o_f	<<"+++ P5_OUTPUT >>> OVERLOADED OPERATOR * COMPLETED"<<endl //does not override base matrix
			<<"+++ P5 END +++++++++++++++++++++++++++++++++++++++++++"<<endl;
     
     }
     else if(dim2!=a_matrix.dim1)
     {
		o_f <<"+++ P5_OUTPUT >>> ERROR" << endl
			<<"+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES"<< endl
			<<"+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
     }
     
        return temp_matrix;
}

MATRIX
MATRIX::operator / (MATRIX a_matrix)
{
    MATRIX temp_matrix(dim1, a_matrix.dim2); //uses constructor 1, temp_matrix takes on dim1 from base and dim2 from a_matrix
	// your code goes below:

	a_matrix.INVERT_MATRIX("OUT_5_TEMP.txt"); //inverts a_matrix, places into txt file OUT_5_TEMP.txt

	MATRIX INV_MATRIX(a_matrix.dim1, a_matrix.dim2,"OUT_5_TEMP.txt"); //uses constructor 2, create new matrix with name "INV_MATRIX" which is populated from OUT_5_TEMP.txt and takes on a_matrix dimensions
	
	int i,j,k;
	o_f<<"+++ P5 START +++++++++++++++++++++++++++++++++++++++++"<<endl;
	if(dim2==INV_MATRIX.dim1)
	{
     	for (i=0;i<dim1;i++)//MATRIX MULTIPLICATION OF BASE MATRIX AND INV OF a_matrix into temp_matrix
     	{
     		for(j=0;j<a_matrix.dim2;j++)
     		{
     			for(k=0;k<INV_MATRIX.dim2;k++)
     			{
     				temp_matrix.A[i][j]=temp_matrix.A[i][j]+A[i][k]*INV_MATRIX.A[k][j];
     			}
     		}
     	
     	}
     	o_f<<"+++ P5_OUTPUT >>> OVERLOADED OPERATOR / COMPLETED"<<endl;
     	o_f<<"+++ P5_OUTPUT >>> THE RESULT OF X/Y OPERATION IS:"<<endl;

     	for ( i = 0; i < temp_matrix.dim1; i++)
         {
             for ( j= 0; j < temp_matrix.dim2; j++)
             {
			o_f <<setprecision(2) << setiosflags(ios::fixed | ios::showpoint) 
				<< temp_matrix.A[i][j] << " ";
             }
             o_f << endl;
         }
     	
	}
	else if(dim2!=INV_MATRIX.dim1)
	{
		o_f<<"+++ P5_OUTPUT >>> ERROR"<<endl;
		o_f<<"+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES"<<endl;
	}
	o_f<<"+++ P5 END +++++++++++++++++++++++++++++++++++++++++++"<<endl;

        return temp_matrix;
}
