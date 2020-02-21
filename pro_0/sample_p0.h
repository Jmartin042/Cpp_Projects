///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Uyar
// LOGIN_NAME: ee259
// EE259 SECTION (DAY/EVE): day and night and always;
///////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream i_f; // declare a pointer to an input file;
ofstream o_f("output.txt", ios::out); 

  class SIMPLEST_GRADES{
   public:      // public methods for this class
        SIMPLEST_GRADES(int, int); // constructor;
		// example usage: g.SIMPLEST_GRADES(x, y);
		// create an object called g with x students each with y exams;

	void SIMPLEST_LIST(int); // a method;
		// example usage: g.SIMPLEST_LIST(x);
		// if x is 1, list the student ids;
		// if x is 2, list the student ids and exam grades;
		// if x is -1, list the student ids in reverse order;
		// if x is -2, list the student ids and exam grades in reverse order;
                // returns no values;

	void SIMPLEST_AVE(int); // another method;
		// example usage: e.SIMPLEST_AVE(x);
		// find the average grade for exam x;
                // returns no values;

   protected:	// protected var to be used by this class and its derivative
   		// classes only (not from main)
        int n;  // no of students;
        int e;  // no of exams;
	int id[20]; // an integer array to hold the ids;
        int exam_grades[20][3]; // 2-dim array to hold exam grades; 
   };
  
SIMPLEST_GRADES::SIMPLEST_GRADES(int x, int y)
{
	// your goes code below:
	int i, j;
	n = x;
	e = y;

	i_f.open("studentGrades.txt", ios::in); // open input file;

	for(i =0; i < n; i++)
	{
		i_f >> id[i];
		for(j = 0; j < e; j++)
		{
			i_f >> exam_grades[i][j];
		}
	}
	i_f.close(); // close input file;
	i_f.clear(); // rewind file pointer to the top of the file;

	o_f << "+ CONSTRUCTOR INSTANTIATED AN OBJECT WITH "
		<< x << " STUDENTS, EACH WITH " << y << " EXAMS." << endl;
}

void
SIMPLEST_GRADES::SIMPLEST_LIST(int x)
{
	int i, j;
	o_f << "+ START SIMPLEST_LIST" << endl;
	// your code goes below:
	if(x == 1)
	{
		o_f << "+ STUDENT IDS:"<< endl;
		for(i = 0; i < n; i++)
		{
			o_f << id[i] << endl;
		}

	}
	else if(x == 2)
	{
		o_f << "+ STUDENT IDS AND EXAM GRADES:" << endl;
		for(i = 0; i < n; i++)
		{
			o_f << id[i] << "\t"; 
			for(j = 0; j < e; j++)
			{
				o_f << exam_grades[i][j] << "\t";
			}
			o_f << endl;
		}
	}
	else if (x == -1)
	{
		o_f << "+ STUDENT IDS IN REVERSE ORDER:" << endl;
		for(i = n-1; i >= 0; i--)
		{
			o_f << id[i] << endl;
		}
	}
	else if (x == -2)
	{

		o_f << "+ STUDENT IDS AND EXAM GRADES IN REVERSE ORDER:" << endl;
		for(i = n-1; i >= 0; i--)
		{
			o_f << id[i] << "\t"; 
			for(j = 0; j < e; j++)
			{
				o_f << exam_grades[i][j] << "\t";
			}
			o_f << endl;
		}
	}
	else 
	{
		o_f << "+ INPUT ERROR" << endl;
	}
	o_f << "+ END SIMPLEST_LIST" << endl;
}

void
SIMPLEST_GRADES::SIMPLEST_AVE(int x)
{
	// your code goes below:
	int i;
	float ave;

	o_f << "+ START SIMPLEST_AVE" << endl;
	if (x >=0 && x <e)
	{
		for(i = 0; i <n; i++)
		{
			ave += exam_grades[i][x];
		}
		ave = ave / n;
		o_f << "+ AVERAGE FOR " << n << " STUDENTS IN EXAM "
			<< x << " IS " << setprecision (2) 
			<< setiosflags(ios::fixed | ios::showpoint)
			<< ave << "." << endl;
	}
	else
	{
		o_f << "+ INPUT ERROR" << endl;
	}
	o_f << "+ END SIMPLEST_AVE" << endl;
}
