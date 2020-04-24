#include "p7.h"
// example program: main7_2.cc
int main()
{
	EZ_CURVE_FIT C(5);
	C.LS_FIT_BY_MATLAB("inputDataPoints_2.txt");
	return 0;
}
