#include "p3.h"
// example program: main3_4.cc
int main ()
{
        GRADES g(4,3);  // create an object g of class SIMPLE_GRADES 
				// which has 4 students each with 3 grades;
	g.VERIFY("KATE", "OGGEN"); // verify student;
	g.VERIFY("ASILEM", "RAYA"); // no such student;

        return 0;
}
