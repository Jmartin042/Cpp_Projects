#include "p7.h"
// example program: main7_1.cc
int main()
{
	EZ_CURVE_FIT e(5);
	e.LS_FIT_BY_ME("inputDataPoints_1.txt");
	return 0;
}
