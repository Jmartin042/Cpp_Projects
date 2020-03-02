#include "p1.h"
// example program: main1_1.cc
int main ()
{
       SIMPLER_GRADES g(5,3);  // create an object g of class SIMPLER_GRADES 
				// which has 5 students each with 3 grades;
	//g.SIMPLER_FIND(0, 0); // input error;
	//g.SIMPLER_FIND(3333, 3); // inut error;
	//g.SIMPLER_FIND(3333, -1); // inut error;
	//g.SIMPLER_FIND(1234, -1); // inut error;
	g.SIMPLER_LIST(3); // input error;
	//g.SIMPLER_LIST(-2); // input error;
        return 0;
}
