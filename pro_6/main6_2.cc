// example program: main6_2.cc
#include "p6.h"
int main()
{       LINEAR_SOLVER s("in_6_2.txt", 2);
        s.SOLVE_BY_MATLAB();
        return 0;
}
