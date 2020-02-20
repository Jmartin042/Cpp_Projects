///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME:
// LOGIN_NAME:
// EE259 SECTION (DAY/EVE):
///////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_1/sample_p1.h"

using namespace std;

ifstream i_f_2; // declare a pointer to pin input file;

  class SIMPLE_GRADES: public SIMPLER_GRADES{
   public:      // public methods for this class

        SIMPLE_GRADES(int, int); // constructor;
		// example usage: g.SIMPLE_GRADES(x, y);
		// create an object called g with x students each with y grades;

	void SIMPLE_SORT(int); // a method;
		// example usage: b.SIMPLE_SORT(x);
		// if x is 1, sort students in ascending order;
		// returns no values;

	void SIMPLE_MAX(int); // another method;
		// example usage: b.SIMPLE_MAX(x);
		// find student(s) received max grade for exam x;
		// returns no values;

	int SIMPLE_FIND(int, int);  //another method;
		// example usage: b.SIMPLE_FIND(x, y);
		// search student id x and pin y;
		// returns index for the found student;

	int SIMPLE_REPORT(int, int, int);  //another method;
		// example usage: b.SIMPLE_REPORT(x, y, z);
		// for student id x and pin y, report grade in exam z;
		// returns no values;
	protected:
		int pin[20]; // pin values for students;
   };

SIMPLE_GRADES::SIMPLE_GRADES(int x, int y)
	: SIMPLER_GRADES(x, y)
{
	int i;
	// below, open input file for pin and read its contents:

}

void 
SIMPLE_GRADES::SIMPLE_SORT(int x)
{
	// your code goes below:
}

void 
SIMPLE_GRADES::SIMPLE_MAX(int x) // another method;
{
	// your code goes below:

}

int 
SIMPLE_GRADES::SIMPLE_FIND(int x, int y)  //another method;
{
	// your code goes below:

	return -1; // make sure to modify this;
}

int
SIMPLE_GRADES::SIMPLE_REPORT(int x, int y, int z)
{
	// your code goes below:

	return -1; // make sure to modify this;
}
