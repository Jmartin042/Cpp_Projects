// example program: main6_3.cc
#include "p6.h"
int main()
{
	LINEAR_SOLVER m1("in_6_3.txt",2);
	m1.INHERITED_INVERT();
	return 0;
}
