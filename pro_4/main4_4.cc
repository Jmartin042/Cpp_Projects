#include "p4.h"
// example program: main4_4.cc
int main ()
{
        OVERLOADED_GRADES g1("G1", 4,3), g2("G2", 4,3);  

	if(g1 == g2) // this returns true;
	{
		g2.OVERLOADED_LIST(1);
	}
	else
	{
		g2.OVERLOADED_LIST(0); // this does not execute;
	}

	g2 -= 3333; // remove student 3333 from g2;
	g2 -= 1111; // remove student 1111 from g2;
	if(g1 == g2) // this returns false;
	{
		g2.OVERLOADED_LIST(0); // this does not execute;
	}
	else
	{
		g2.OVERLOADED_LIST(2); 
	}

	g2 = g1; // assign g1 data into g2;
	if(g1 == g2) // this returns true;
	{
		g2.OVERLOADED_LIST(1);
	}
	else
	{
		g2.OVERLOADED_LIST(0); // this does not execute;
	}

        return 0;
}
