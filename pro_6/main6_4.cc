// example program: main6_4.cc
#include "p6.h"
int main()
{
	LINEAR_SOLVER m1("in_6_4.txt",2);
	m1.INVERT_BY_MATLAB();
	return 0;
}
