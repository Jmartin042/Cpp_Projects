#include "p4.h"
// example program: main4_2.cc
int main ()
{
        OVERLOADED_GRADES g1("G1", 4,3);  

	if (g1 == 4) // this returns true;
	{
		g1.OVERLOADED_LIST(1);
	}
	else 
	{
		g1.OVERLOADED_LIST(0); // this does not execute;
	}

	if (g1 == 7) // this returns false;
	{
		g1.OVERLOADED_LIST(0); // this does not execute;
	}
	else 
	{
		g1.OVERLOADED_LIST(2);
	}

        return 0;
}
