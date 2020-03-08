#include "p3.h"
// example program: main3_2.cc
int main ()
{
        GRADES g(4,3);  // create an object g of class SIMPLE_GRADES 
				// which has 4 students each with 3 grades;
	//g.LIST(-1); // alphabetize;
	//g.ALPHABETIZE(1);
	g.VERIFY("MONALISA", "SCHONBRUN"); // verify student;
	//g.VERIFY("JONATHAN", "RAYA"); // no such student;
	//g.VERIFY("ASILEM", "RAYA");
	//g.REPORT(0, 0, 0, 0); // report the grade for id 3333 pin 33 exam 0;
	//g.REPORT(0, 0, 0, 0); // report all grades;
        return 0;
}
