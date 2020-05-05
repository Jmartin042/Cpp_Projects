#include "p8.h"
// example program: main8_3.cc
int main()
{
	EZ_DIFF_INTEGRATE e("input_8_3.txt"); // constructor; 
	e.EZ_INTEG_BY_ME(-5, 5, 20);
	return 0;
}
