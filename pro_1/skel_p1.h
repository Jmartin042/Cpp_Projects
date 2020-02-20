///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME:
// LOGIN_NAME:
// EE259 SECTION (DAY/EVE):
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

}

void
SIMPLER_GRADES::SIMPLER_LIST(int x)
{
	// your code goes below:

}

void
SIMPLER_GRADES::SIMPLER_FIND(int x, int y)
{
	// your code goes below:

}
