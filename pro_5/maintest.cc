//Example program: main5_4.cc
#include "p5.h"
int main ()
{
	MATRIX X(2,3, "in_test23.txt"), Y(3,2, "in_test32.txt"),Z(2,2); 
	// X(2,3, "in_test23.txt") and Y(3,2, "in_test32.txt") are examples of constructor 2 being used
	
	X.PRINT("X");
	Y.PRINT("Y");
	
	Z = X * Y; //test for (2 by 3 matrix) * (3 by 2 matrix) = (2 by 2 matrix)
	Z.PRINT("Z");

	MATRIX A(3,3,"in_test33.txt"), B(3,3), C(3,3);

	A.PRINT("A");

	B = 1/A; //B = A^(-1)
	B.PRINT("B");

	C = A*B; // A * A^(-1) = identity matrix

	C.PRINT("C");
	
	return 0;
}
