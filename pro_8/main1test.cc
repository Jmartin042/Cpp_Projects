#include "p8.h"
// example program: main8_1.cc
int main()
{
	EZ_DIFF_INTEGRATE e("input_8_1.txt"); // constructor; 

	e.EZ_DIFF_BY_ME(-5, 5, 20);
	return 0;
}
