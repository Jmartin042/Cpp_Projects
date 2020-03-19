//Example program: main5_3.cc
#include "p5.h"
int main ()
{
	MATRIX X(2,2, "in_5_31.txt"), Y(2,2, "in_5_32.txt");

	X.PRINT("X");
	Y.PRINT("Y");
	
	X *= Y;
	
	X.PRINT("X");
	Y.PRINT("Y");
	
	return 0;
}
