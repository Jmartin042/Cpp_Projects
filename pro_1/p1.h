///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME:Jonathan Martinez	
// LOGIN_NAME:jmartin042
// EE259 SECTION (DAY/EVE):
///////////////////////////////////////////////////////////////
// My file   "/home/ee259d15/pro_0/p0.h" 
// professor file  "/mnt/ee259dir/tools/pro_0/sample_p0.h"

#include "/mnt/ee259dir/tools/pro_0/sample_p0.h"

using namespace std;

  class SIMPLER_GRADES: public SIMPLEST_GRADES{
   public:      // public methods for this class
        SIMPLER_GRADES(int, int); // constructor;
		// example usage: g.SIMPLER_GRADES(x, y);
		// create an object called g with x students each with y grades;

	void SIMPLER_LIST(int); // a method;
		// example usage: g.SIMPLER_LIST(x);
		// list the grades for a given exam;
		// if x is -1, list the grades for all exams (use inheritance);
		// returns no values;

	void SIMPLER_FIND(int, int); // another method;
		// example usage: g.SIMPLER_LIST(x, y);
		// list the grade of student with id of x for exam y;
		// returns no values;
   };

SIMPLER_GRADES::SIMPLER_GRADES(int x, int y)
	: SIMPLEST_GRADES(x, y) // you must call base class constructor;
{

	o_f<< "*** SIMPLER_GRADES CONSTRUCTOR INSTANTIATED A NEW OBJECT."<<endl; // your goes code below:
	
	// base class SIMPLEST_GRADES reads students grades and populates
	// protected data members; so, no need to read them again;
}

void
SIMPLER_GRADES::SIMPLER_LIST(int x)
{
	// your code goes below:
	o_f<< "*** START SIMPLER_LIST"<<endl;
	int i;
	int j;
	if(x==-1)
	{
		o_f<<"*** GRADES FOR ALL EXAMS:"<<endl;
		SIMPLEST_LIST(2);
	}
	else if(0<=x && x<e)
	{
		o_f<<"*** GRADES FOR EXAM "<<x<<":"<<endl;
		for(i =0; i < n; i++)
		{
			o_f<<id[i]<<"	";
			for(j = 0 ;j < e; j++)
			{
				if(x==j)
				{
					o_f<<exam_grades[i][j]<<endl;
				}
				else{}
			}
		}
	}
	else
	{
		o_f<<"*** INPUT ERROR"<<endl;
	}
	o_f<<"*** END SIMPLER_LIST"<<endl;
}

void
SIMPLER_GRADES::SIMPLER_FIND(int x, int y)
{
	// your code goes below:
	int i;
	int found=0;
	int found_pos;
	o_f<<"*** START SIMPLER_FIND"<<endl;
	if((y<0 || y>=e) || (x>9999 || x<0))
	{
		o_f<<"*** INPUT ERROR"<<endl;
	}
	else
	{	
		for (i = 0; i < n && found==0 ; i++)
		{
			if(id[i]==x)
			{
				found=1;
				found_pos=i;
			}
			else{}
		}
		if(found==1)
		{
			o_f<<"*** GRADE OF STUDENT WITH ID "<<x<<" FOR EXAM "<<y<<":"<<endl;
			o_f<<x<<"	"<<exam_grades[found_pos][y]<<endl;
		}	
		else
		{
		o_f<<"*** NO STUDENT WITH ID "<<x<<endl;
		o_f<<"*** ALL STUDENT IDS ARE:"<<endl;
		SIMPLEST_LIST(1);//all ids are shown from base class
		}
	}
	o_f<<"*** END SIMPLER_FIND"<<endl;
}
