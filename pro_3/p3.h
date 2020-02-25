///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: 
// LOGIN_NAME: 
// EE259 SECTION (DAY/EVE): 
///////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_2/sample_p2.h"
#include "string.h"

using namespace std;

ifstream i_f_3; // declare a pointer to pin input file;

  class GRADES: public SIMPLE_GRADES{
   public:      // public methods for this class

        GRADES(int, int); // constructor;
		// example usage: g.GRADES(x, y);
		// create an object called g with x students each with y grades;

	void LIST(int); // a method;
		// example usage: b.LIST(x);
		// returns no values;

	void ALPHABETIZE(int); // a method;
		// example usage: b.ALPHABETIZE(x);
		// returns no values;

	int VERIFY(char *, char *); // another method;
		// example usage: b.VERIFY("KATE", "OGGEN");
		// returns integer;

	void REPORT(int, int, int, int);  //another method;
		// example usage: b.REPORT(w, x, y, z);
		// returns no values;

	protected:
		char firstNames[20][15]; // first names for students;
		char lastNames[20][15]; // last names for students;
   };

GRADES::GRADES(int x, int y)
	: SIMPLE_GRADES(x, y)
{
	int i;
	i_f_3.open("studentNames.txt", ios::in); // open input file;

	for(i =0; i < n; i++)
	{
		i_f_3 >> firstNames[i];
		i_f_3 >> lastNames[i];
	}
	i_f_3.close(); // close input file;
	i_f_3.clear(); // rewind file pointer to the top of the file;

	o_f << "******* GRADES CONSTRUCTOR CREATES A NEW OBJECT WITH NAMES OF "
		<< x << " STUDENTS." << endl;
}

void
GRADES::LIST(int x)
{	// your code goes below:

}

void 
GRADES::ALPHABETIZE(int x)
{	// your code goes below:


}

int 
GRADES::VERIFY(char * F, char * L)
{	// your code goes below:

	return -2; // make sure to modify this;
}

void
GRADES::REPORT(int w, int x, int y, int z)
{	// your code goes below:
	

}
