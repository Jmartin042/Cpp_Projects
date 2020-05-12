///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: 
// CITYMAIL NAME: 
// EE259 LOGIN NAME: 
// EE259 SECTION (DAY/EVE): 
///////////////////////////////////////////////////////////////
//
//THIS IS P9
//
#include <iostream>
#include <fstream>
#include <string.h>
#include <thread>
using namespace std;

// global variables
ofstream out_f ("output_9.txt", ios::out);
int result[400];
int result_x[400];
int result_y[400];
int image[20][20]; // image file;
int filter[5][5]; // filter file;

#include "thread.h"

class IMAGE_PROC{
	public:	// public methods for this class
	  IMAGE_PROC (int, char *, int, char *);  // constructor;
			// example: IMAGE_PROC A1(20, "image_num.txt", 3, "filter_num.txt");
			// creates object A1 for a 20x20 image and a 3x3 filter;
  
	  void PRINT(char *);	// example: A1.PRINT("ALL");
			// print the elements of image, filter or both;
			// returns no values;

	  void COUNT(); // example: A1.COUNT();
			// find number of occurrences of filter in image data;
			// returns no values;
	
	  void LOCATE(); // example: A1.LOCATE();
			// report locations of filter occurrences in image data;
			// returns no values;

	private:
  	  int n;	// dimension of image file;
	  int f;	// dimension of filter image;
	  char im_file[11]; // name of image file;
	  char filt_file[11]; // name of filter file;
 };

IMAGE_PROC::IMAGE_PROC (int x, char * f1, int y, char * f2)  // constructor;
{
	int i, j;

	n = x;
	f = y;
	strcpy(im_file, f1);
	strcpy(filt_file, f2);
	ifstream im_f(f1, ios::in);
	ifstream filt_f(f2, ios::in);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			im_f >> image[i][j];
		}
	}

	for(i = 0; i < f; i++)
	{
		for(j = 0; j < f; j++)
		{
			filt_f >> filter[i][j];
		}
	}
	// your output messages from constructor here:

}
  
void
IMAGE_PROC::PRINT(char * cmd)	// example: A1.PRINT("ALL");
{
	// your code goes below:

}

void
IMAGE_PROC::COUNT() 
{
	// your code goes below:

}
	
void
IMAGE_PROC::LOCATE() 
{
	// your code goes below:

}
