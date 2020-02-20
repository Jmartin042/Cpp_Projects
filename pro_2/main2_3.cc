#include "p2.h"
// example program: main2_3.cc
int main ()
{
        SIMPLE_GRADES g(4,3);  // create an object g of class SIMPLE_GRADES 
				// which has 4 students each with 3 grades;
	g.SIMPLEST_LIST(2); // use method from base class;
	g.SIMPLE_MAX(2); // find max in exam 2;
        return 0;
}
