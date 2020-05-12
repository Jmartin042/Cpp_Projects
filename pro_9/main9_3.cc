#include "p9.h"
// example program: main9_3.cc
int main ()
{
        IMAGE_PROC A1(20, "image_num.txt", 3, "filter_num.txt");
			// creates object called A1 for a 20x20 image
			// and a 3x3 filter;
	A1.PRINT("ALL"); 
	A1.LOCATE(); // find the occurrences of filter in image;
	return 0;
}
