//Example program: main5_4.cc
#include "p5.h"
int main ()
{
	MATRIX X(2,2, "in_5_41.txt"), Y(2,2, "in_5_42.txt"), Z(2,2);

	X.PRINT("X");
	Y.PRINT("Y");
	
	Z = X / Y;
	//Z.PRINT("Z");
	
	//Z = 3 / Y;
	//Z.PRINT("Z");

	//Z = 3 * Y;
	//Z.PRINT("Z");
	
	return 0;
}
