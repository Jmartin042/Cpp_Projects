#include "p8.h"
// example program: main8_3.cc
int main()
{
	EZ_DIFF_INTEGRATE e("/ee259/tools/pro_8/input_8_3.txt"); // constructor; 
	e.EZ_DIFF_BY_ME(-5, 5, 20);
	//e.EZ_DIFF_BY_ME("sin", -5, 5, 20);
	//e.EZ_DIFF_BY_ME("cos", -5, 5, 20);
	//e.EZ_DIFF_BY_ME("sin", 0, 90, 10);
	//e.EZ_DIFF_BY_ME("x", 0, 10, 10);
	//e.EZ_DIFF_BY_ME("x", -5, 5, 20);
	return 0;
}
