#include "p0.h"
// example program: main0_4.cc
int main ()
{
        SIMPLEST_GRADES g(4,3);  // create an object g of class SIMPLEST_GRADES 
				// which has 4 students each with 3 grades;
	g.SIMPLEST_LIST(-1); // reverse;
	g.SIMPLEST_LIST(-2); // reverse;
	g.SIMPLEST_LIST(3); // input error;
        return 0;
}
