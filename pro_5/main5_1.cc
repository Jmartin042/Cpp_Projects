//Example program: main5_1.cc
#include "p5.h"
int main ()
{
	MATRIX X(2,2, "in_5_11.txt"), Y(2,2, "in_5_12.txt"), Z(2,2, "in_5_12.txt");

	X.PRINT("X"); 
	Y.PRINT("Y"); 
	Z.PRINT("Z"); 
	if (X < 1)
	{}
	else
	{
		X.PRINT("Y"); // should print;
	}

	Z = X + Y;

	if (Z < 5)
	{
		Z.PRINT("Z"); // should print;
	}
	else
	{}

	return 0;
}
