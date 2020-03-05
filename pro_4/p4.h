///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: jonathan martinez
// CITYMAIL NAME: jmartin042
// EE259 SECTION (DAY/EVE): DAY
///////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_3/sample_p3.h" //centos prof file
//#include "/home/ee259d15/pro_2/p2.h" // centos my file

//#include "/home/jmartin042/ee259d15/test/pro_3/p3.h" //my own computer my own file
//#include "/home/jmartin042/ee259d15/test/pro_3/sample_p3.h" //my own computer, sample file

using namespace std;

  class OVERLOADED_GRADES: public GRADES{
   public:      // public methods for this class

        OVERLOADED_GRADES(char *, int, int); // constructor;
		// example usage: g.OVERLOADED_GRADES("G1", x, y);
		// create an object g with x students each with y grades;

	void OVERLOADED_LIST(int); // a method;
		// example usage: b.OVERLOADED_LIST(x);
		// returns no values;

	int operator == (int);  
		// an overloaded operator;
		// example usage: if (g == 4)
		// returns integer;

	int operator == (OVERLOADED_GRADES);  
		// another overloaded operator;
		// example usage: if (g1 == g2)
		// returns integer;

        void operator -= (int); 
		// another overloaded operator;
		// example usage: g -= 1234;
		// returns nothing;

        void operator = (OVERLOADED_GRADES); 
		// another overloaded operator;
		// example usage: g1 = g2;
		// returns nothing;

        OVERLOADED_GRADES operator + (OVERLOADED_GRADES); 
		// another overloaded operator;
		// example usage: g1+g2;
		// returns OVERLOADED_GRADES object;
   private:
	char objName[15]; // name for the object; max length 14;
   };

OVERLOADED_GRADES:: OVERLOADED_GRADES(char * O_N, int x, int y)
	: GRADES(x, y) // call base class constructor;
{ // your code goes below:

}

void
OVERLOADED_GRADES::OVERLOADED_LIST(int x)
{ // your code goes below:

}

int
OVERLOADED_GRADES::operator == (int x)  
{ // your code goes below:

	return 1; // make sure to modify;
}

int
OVERLOADED_GRADES::operator == (OVERLOADED_GRADES obj2)  
{ // your code goes below:

	return 1; // make sure to modify;
}

void
OVERLOADED_GRADES::operator -= (int x) 
{ // your code goes below:

}

void
OVERLOADED_GRADES::operator = (OVERLOADED_GRADES obj2) 
{ // your code goes below:

}

OVERLOADED_GRADES
OVERLOADED_GRADES::operator + (OVERLOADED_GRADES obj2)
{
	// declare a temporary object of class OVERLOADED_GRADES:
	OVERLOADED_GRADES obj("TempOBJ", 0, 0);
	// your code goes below:

	return obj; // return the temporary object;
}
