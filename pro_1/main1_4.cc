#include "p1.h"
// example program: main1_4.cc
int main ()
{
        SIMPLER_GRADES g(4,3);  // create an object g of class SIMPLER_GRADES 
				// which has 4 students each with 3 grades;
	g.SIMPLER_FIND(3333, 1); // student id 3333 exam 1;g.SIMPLER_FIND(3333, 1);
	g.SIMPLER_FIND(3322, 1); // no such student; g.SIMPLER_FIND(3322, 1);
        return 0;
}
