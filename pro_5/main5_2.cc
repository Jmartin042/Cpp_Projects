//Example program: main5_2.cc
#include "p5.h"
int main ()
{
	MATRIX X(2,2,"in_5_21.txt"), Y(2,2, "in_5_22.txt"), Z(2,2);

	X.PRINT("X");
	Y.PRINT("Y");

	Z = X*Y;
	Z.PRINT("Z");
	
	Z = X+Y;
	Z.PRINT("Z");
	
	return 0;
}
