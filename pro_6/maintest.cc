// example program: main6_4.cc
#include "p6.h"
int main()
{
	LINEAR_SOLVER m1("intest_33.txt",3);

	m1.SOLVE_LINEAR_EQUATION("NONE");
	m1.SOLVE_LINEAR_EQUATION("ASCEND");
	m1.SOLVE_LINEAR_EQUATION("DESCEND");

	//m1.SOLVE_BY_MATLAB();
	return 0;
}
