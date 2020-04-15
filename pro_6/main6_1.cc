// example program: main6_1.cc
#include "p6.h"
int main()
{       //LINEAR_SOLVER s(2);
	LINEAR_SOLVER s("in_6_1.txt",2);
        s.SOLVE_LINEAR_EQUATION("DESCEND");
        return 0;
}
