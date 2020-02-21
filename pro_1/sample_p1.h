///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Uyar
// LOGIN_NAME: ee259
// EE259 SECTION (DAY/EVE): day and night and between;
///////////////////////////////////////////////////////////////

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
	// your goes code below:

	// base class SIMPLEST_GRADES reads students grades and populates
	// protected data members; so, no need to read them again;

	o_f << "*** SIMPLER_GRADES CONSTRUCTOR INSTANTIATED A NEW OBJECT." << endl;
}

void
SIMPLER_GRADES::SIMPLER_LIST(int x)
{
	// your code goes below:

	int i, j;
	o_f << "*** START SIMPLER_LIST" << endl;
	if (x == -1)
	{
		o_f << "*** GRADES FOR ALL EXAMS:" << endl;
		SIMPLEST_LIST(2); // use method fron base class;
	}
	else if(x > 0 && x < 10000)
	{
		o_f << "*** GRADES FOR EXAM " << x << ":" << endl;
		for(i = 0; i < n; i++)
		{
			o_f << id[i] << "\t" << exam_grades[i][x] << endl;
		}
	}
	else 
	{
		o_f << "+ INPUT ERROR" << endl;
	}
	o_f << "*** END SIMPLER_LIST" << endl;
}

void
SIMPLER_GRADES::SIMPLER_FIND(int x, int y)
{
	// your code goes below:
	int i, FOUND, FOUND_POS;

// debugging printout:
cout << "x " << x << " y " << y << " e " << e << endl;

	o_f << "*** START SIMPLER_FIND" << endl;
	if(x > 0 && x < 10000 && y >= 0 && y < e)
	{
		FOUND = 0;
		for(i = 0; i < n && FOUND == 0; i++)
		{

// debugging printout:
cout << "id[" << i << "]: " << id[i] << " x: " << x << endl; 

			if (id[i] == x)
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}

// debugging printout:
cout << "FOUND: " << FOUND << endl;

		if (FOUND == 1)
		{
			o_f << "*** GRADE OF STUDENT WITH ID " << x 
				<< " FOR EXAM " << y << ": " << endl;
			o_f << x << "\t" << exam_grades[FOUND_POS][y] << endl;
		}
		else
		{
			o_f << "*** NO STUDENT WITH ID " << x << endl;
			o_f << "*** ALL STUDENT IDS ARE:" << endl;
			SIMPLEST_LIST(1);
		}
	}
	else
	{
		o_f << "*** INPUT ERROR" << endl;
	}
	o_f << "*** END SIMPLER_FIND" << endl;
}
