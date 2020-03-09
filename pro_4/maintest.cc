#include "p4.h"
// example program: main4_3.cc
int main ()
{
        OVERLOADED_GRADES g1("G1", 4,3), g2("G2", 2,3), g3("G3", 0,0);  

	//g1.OVERLOADED_LIST(1);
	//g2.OVERLOADED_LIST(1);
	//g3.OVERLOADED_LIST(1);

	g3 = g1 + g2;

	//g1.OVERLOADED_LIST(1);
	//g2.OVERLOADED_LIST(1);
	g3.OVERLOADED_LIST(1);

        return 0;
	
	
}