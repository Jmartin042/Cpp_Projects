//
// THIS IS SAMPLE P6 
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "/mnt/ee259dir/tools/pro_5/sample_p5.h"
//#include "sample_p5.h"

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

LINEAR_SOLVER::LINEAR_SOLVER(char * p, int x)
        :MATRIX(x, x, p) // instantiate P5_MATRIX class with dim1=x dim2=x;
{	
	int i, j;
	n = x;

	ifstream input(p, ios::in);
	
	for(i=0; i<n; i++)
        {
        	B[i]=0;
        	for(j=0; j<n; j++)
        	{
        		A[i][j]=0;
        	}
        }    
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			input	>>A[i][j];
		}
	}
	for(i=0; i<n; i++)
	{
		input	>>B[i];
	}
	o_f << "++++++ P6 BEGIN ++++++"  <<endl
		<< "++++++ P6 INSTANTIATED AN OBJECT WITH "<< n<< " EQUATIONS" << endl
		<< "++++++ P6 DATA READ FROM FILE: " << in_file << endl
		<< "++++++ P6 END ++++++" << endl;
}

LINEAR_SOLVER::LINEAR_SOLVER(int x)
        :MATRIX(x, x) // instantiate P5_MATRIX class with dim1=x dim2=x;
{	
	int i, j;
	n = x;

	for(i=0; i<n; i++)
        {
        	B[i]=0;
        	for(j=0; j<n; j++)
        	{
        		A[i][j]=0;
        	}
        }    
	
	o_f << "++++++ P6 BEGIN ++++++" << endl
		<< "++++++ P6 INSTANTIATED AN OBJECT WITH "<< n<< " EQUATIONS" << endl
		<< "++++++ P6 END ++++++" << endl;
}

void 
LINEAR_SOLVER::SOLVE_LINEAR_EQUATION(char * command)
{
	 
	int col, row, i, j, k; 
	int found=1;
	float multiply, temp, sum;	
	float temp_A[50][50];
        float temp_B[50];
	float X[50];
	
	int temp_pos[50], minpos, maxpos, temp1;
	float temp_value[50], minvalue, maxvalue, temp2;

        for( col=0; col<n; col++)
        {
        	temp_B[col]=B[col];
        	for(row=0; row<n; row++)
        	{
        		temp_A[col][row]=A[col][row];
        	}
        }        		
        		
	for( col=0; col<n && found==1; col++)
	{					
		if(temp_A[col][col]==0)
	 	{
			found=0;
	 		for(i=col+1; i<n && found==0; i++)
	 		{
	 			if(temp_A[i][col] != 0)
	 			{
	 				temp=temp_B[col];
	 				temp_B[col]=temp_B[i];
	 				temp_B[i]=temp;
	 				
					for(j=0; j<n; j++)
	 				{
	 					temp=temp_A[col][j];
	 					temp_A[col][j]=temp_A[i][j];
	 					temp_A[i][j]=temp;
	 				}					
					found=1;
	 			}
	 		}
	 	}		
	 	else
		{	
			for( row=col+1; row<n; row++)
	 		{
	 			multiply= (-1*temp_A[row][col])/(temp_A[col][col]);
	 			for( i=col; i<n; i++)
	 			{
	 				temp_A[row][i]=(multiply*temp_A[col][i])+temp_A[row][i];
	 			}
	 		
	 			temp_B[row]=(multiply*temp_B[col])+temp_B[row];
	 		}
		}
	}

	if(found==0)
	{
		o_f << "++++++ P6 BEGIN ++++++" << endl
			<< "++++++ P6 MY GAUSSIAN ELIMINATION SOLUTION:" << endl
			<< "++++++ P6 EQUATION IS SINGULAR" << endl
			<< "++++++ P6 END ++++++" << endl;
	}
	else
	{	
		for(row=n-1; row>=0;row--)
		{
			sum=0;
			for( k=n-1; k>row; k--)
			{
				sum+=temp_A[row][k]*X[k];
			}
			X[row]=(temp_B[row]-sum)/temp_A[row][row];
		}
		
		if(strcmp(command, "UNSORTED")==0)
		{
			o_f << "++++++ P6 BEGIN ++++++" << endl
				<< "++++++ P6 MY GAUSSIAN ELIMINATION SOLUTION "
				<< "(UNSORTED):" << endl;
			for (i=0; i<n; i++)
			{
				//o_f << "X["<< temp_pos[i]<< "]= "
				o_f << "X["<< i << "]= "
					<< setprecision(2)
					<< setiosflags(ios::fixed | ios::showpoint)
					<< X[i] << endl;
			}
			
			o_f << "++++++ P6 END ++++++" << endl;
		}
		else if(strcmp(command, "ASCEND")==0)
		{
			for (i=0; i<n; i++)
			{
				temp_pos[i] = i;
				temp_value[i] = X[i];
			}
			
			for(i=0; i<n; i++)
			{
				minvalue = temp_value[i];
				minpos=i;
				
				for(j=i; j<n; j++)
				{
					if (temp_value[j] < minvalue)
					{
						minvalue = temp_value[j];
						minpos=j;
					}
					else {}
				}	
				temp1 = temp_pos[i];
				temp_pos[i]=temp_pos[minpos];
				temp_pos[minpos]= temp1;
					
				temp2 = temp_value[i];
				temp_value[i] = temp_value[minpos];
				temp_value[minpos] = temp2;
					
			}
			o_f << "++++++ P6 BEGIN ++++++" << endl
				<< "++++++ P6 MY GAUSSIAN ELIMINATION SOLUTION "
				<< "(SORTED IN ASCENDING ORDER):" << endl;
			for (i=0; i<n; i++)
			{
				o_f << "X["<< temp_pos[i]<< "]= "
					<< setprecision(2)
					<< setiosflags(ios::fixed | ios::showpoint)
					<< temp_value[i] << endl;
			}
			o_f << "++++++ P6 END ++++++" << endl;
		}
		else if(strcmp(command, "DESCEND")==0)
		{
			for (i=0; i<n; i++)
			{
				temp_pos[i] = i;
				temp_value[i] = X[i];
			}
			for(i=0; i<n; i++)
			{
				maxvalue = temp_value[i];
				maxpos=i;
				
				for(j=i; j<n; j++)
				{
					if (temp_value[j] > maxvalue)
					{
						maxvalue = temp_value[j];
						maxpos=j;
					}
					else {}
				}	
				temp1 = temp_pos[i];
				temp_pos[i]=temp_pos[maxpos];
				temp_pos[maxpos]= temp1;
					
				temp2 = temp_value[i];
				temp_value[i] = temp_value[maxpos];
				temp_value[maxpos] = temp2;
			}
			
			o_f << "++++++ P6 BEGIN ++++++" << endl
				<< "++++++ P6 MY GAUSSIAN ELIMINATION SOLUTION "
				<< "(SORTED IN DESCENDING ORDER):" << endl;
			for (i=0; i<n; i++)
			{
				o_f << "X["<< temp_pos[i]<< "]= "
					<< setprecision(2)
					<< setiosflags(ios::fixed | ios::showpoint)
					<< temp_value[i] << endl;
			}
			o_f << "++++++ P6 END ++++++" << endl;
		}
		else{}
	}			
}

void
LINEAR_SOLVER::SOLVE_BY_MATLAB()
{
 	ofstream matlabout_file("out_62.m", ios::out); 	
 	
 	int i, j;
 	char copying[100];
 	
 	matlabout_file<< "A=["; 	
 	for(i=0; i<n; i++)
 	{
 		matlabout_file<< A[i][0];
 		for(j=1; j<n; j++)
 		{
 			matlabout_file<< ","<< A[i][j];
 		}
 		if( i==n-1 )
 		{
 			matlabout_file<< "];"<< endl;
 		}
 		else
 		{
 			matlabout_file<< ";";
 		}
 	}
 	
 	matlabout_file<< "B=["<< B[0];
 	for(i=1; i<n; i++)
 	{
 		matlabout_file<< ";"<< B[i];
 	}
 	matlabout_file<< "];"<< endl;
 	
 	matlabout_file<< "X=inv(A)*B;" << endl
		<< "fid=fopen('output.txt','a');"<< endl
		<< "fprintf(fid,'++++++ P6 BEGIN ++++++\\n');"<< endl
		<< "fprintf(fid,'++++++ P6 RESULT FROM MATLAB (UNSORTED):\\n');"<< endl
		<< "for k=1:"<< n<< endl
		<< "fprintf(fid,'X[%d]=%6.2f\\n',k-1,X(k));"<< endl
		<< "end"<< endl
		<< "fprintf(fid,'++++++ P6 END ++++++\\n');" << endl;
	system("/bin/csh /ee259/tools/pro_6/run_out_62");
}

void 
LINEAR_SOLVER::INHERITED_INVERT()
{
	int i, j;

        o_f << "++++++ P6 BEGIN ++++++"<< endl;
	o_f << "++++++ P6 AFTER INHERITING FROM MATRIX CLASS, MY RESULT IS:"<< endl;
        MATRIX temp_m(n,n,in_file); 

	1/temp_m; // inheritence: friend function call from base class

	o_f << "++++++ P6 END ++++++"<< endl;
}

void
LINEAR_SOLVER::INVERT_BY_MATLAB()
{
	ofstream matlabout_file2("out_63.m", ios::out);
	
	int i, j;
 	
 	matlabout_file2<< "A=["; 	
 	for(i=0; i<n; i++)
 	{
 		matlabout_file2<< A[i][0];
 		for(j=1; j<n; j++)
 		{
 			matlabout_file2<< ","<< A[i][j];
 		}
 		if( i==n-1 )
 		{
 			matlabout_file2<< "];"<< endl;
 		}
 		else
 		{
 			matlabout_file2<< ";";
 		}
 	}
 	
 	matlabout_file2<< "X=inv(A);"<< endl
		<< "fid=fopen('output.txt','a');"<< endl
		<< "fprintf(fid,'++++++ P6 BEGIN ++++++\\n');"<< endl
		<< "fprintf(fid,'++++++ P6 INVERSION RESULT FROM MATLAB: \\n');"<< endl
		<< "for i=1:"<< n<< endl
		<< "for j=1:"<< n<< endl
		<< "fprintf(fid,'X[%d][%d]=%6.2f ',i-1,j-1,X(i,j));"<< endl
		<< "end"<< endl
		<< "fprintf(fid,'\\n');"<< endl
		<< "end"<< endl
		<< "fprintf(fid,'++++++ P6 END ++++++\\n');"<< endl;
		
	system("/bin/csh /ee259/tools/pro_6/run_out_63");
}
