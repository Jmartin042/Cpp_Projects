//
// SKELETON FOR PROJECT 7
//
///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME:Jonathan Martinez
// LOGIN_NAME:Jmartin042
// EE259 SECTION (DAY/EVE):
///////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "/mnt/ee259dir/tools/pro_6/sample_p6.h"

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
	np = x; // ^^ constructor 1 from p6.h
	o_f_7	<< "++++++++ P7 BEGIN ++++++" << endl
			<< "++++++++ P7 INSTANTIATED AN OBJECT WITH " << np << " DATA POINTS" << endl
			<< "++++++++ P7 END ++++++" << endl;
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
		input_data_file >> X[i]>> Y[i];
	}
	
	// calculate the S1-S6 values:
	for(i=0; i<np ; i++)
	{
		S1 += (X[i]*X[i]);
		S2 += X[i];
		S3 += (X[i]*Y[i]);
		S4 += X[i];
		S5 += 1;
		S6 += Y[i];
	}

	// write them into S_values.txt file in the format that 
	// is sutaible for sample_p6.h to read:
	ofstream out_s_values("S_values.txt", ios::out);
	
	out_s_values<<S1<<" "<<S2<<endl
				<<S4<<" "<<S5<<endl
				<<S3<<endl
				<<S6<<endl;
	
	
	// instantiate a LINEAR_SOLVER object:
	LINEAR_SOLVER L("S_values.txt",2);
	// access SOLVE_LINEAR_EQUATION (results are in output.txt file):
	L.SOLVE_LINEAR_EQUATION("UNSORTED");
	

	// read the results from output.txt file and populate output_7.txt file:
	
	string tempo;
	ifstream i_p6("output.txt" , ios::in); //declares output.txt from p6 as input(i_p6)
	for(i=0;i<12;i++)
	{
		getline(i_p6,tempo);
		// lets see what it is reading from output.txt file:
		//cout << junk << endl;	
	}
	
	i_p6 >> tempo;
	// lets see what it is reading from output.txt file after loop:
	//cout << "after loop junk " << junk << endl;	
	i_p6 >> m;
	// lets see what it is reading from output.txt file after loop:
	//cout << "m is " << m << endl;	
	i_p6 >> tempo;
	// lets see what it is reading from output.txt file after loop:
	//cout << "after loop junk " << junk << endl;	
	i_p6 >> b;
	// lets see what it is reading from output.txt file after loop:
	//cout << "b is " << b << endl;	
	
	o_f_7	<< "LEAST_SQUARE_FIT RESULT:"<<endl;
	o_f_7 	<< "USING INHERITANCE:"<<endl;
	o_f_7 	<< "MATCHING FUNCTION IS Y = "
			<< setprecision(2) << setiosflags(ios::fixed|ios::showpoint)
			<< m << " * X + "<< b << endl;
	error=0;
	for(i=0;i<np;i++)
	{
		error += pow((Y[i] - (m*X[i]) - b),2);
	}
	
	o_f_7 << "THE ERROR FROM LS_FIT_BY_ME METHOD IS "
		<< setprecision(3) << setiosflags(ios::fixed|ios::showpoint)
		<< error << endl;

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
    
   ofstream o_m_f("mat_1.m",ios::out); 
   // populate mat_1.m file:
   o_m_f<<"x=[";
   for(i=0;i<np;i++)
   {
	 o_m_f<<X[i];
	 if(i < np-1)
	 {
		o_m_f<<","; 
	 }
	 else{};
   }
   o_m_f<<"];"<<endl;
   o_m_f<<"y=["<<endl;
   for(i=0;i<np;i++)
   {
	   o_m_f<<Y[i];
	   if(i < np-1)
	   {
		   o_m_f<<","; 
	   }
	   else{};
   }
   o_m_f<<"];"<<endl;
   o_m_f<<"coef=polyfit(x,y,1);"<<endl;
   o_m_f<<"m=coef(1);"<<endl;
   o_m_f<<"b=coef(2);"<<endl;
   o_m_f<<"Y=m*x+b;"<<endl;
   o_m_f<<"matlab_error=sum((y - Y).^2);"<<endl;
   o_m_f<<"fid=fopen('output_7.txt','a');"<<endl;
   o_m_f<<"fprintf(fid,'*** RESULT FROM MATLAB\\n');"<<endl;
   o_m_f<<"fprintf(fid,'*** THE MATCHING FUNCTION IS Y=(%.3f) * X +(%.3f) \\n',m,b);"<<endl;
   o_m_f<<"fprintf(fid,'*** THE ERROR FROM MATLAB IS %.3f \\n', matlab_error);"<<endl;

   
   // run mat_1.m file: 
   // (make sure that mat1_1.m is good before running automatically by sytem command)
   system("/bin/csh /mnt/ee259dir/tools/pro_7/run_mat_1");
}
