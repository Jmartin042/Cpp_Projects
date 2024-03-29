///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Jonathan Martinez
// CITYMAIL NAME: Jmartin042
// EE259 LOGIN NAME: d15
// EE259 SECTION (DAY/EVE): DAY
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
	
	out_f 	<< "+++ P9 START +++++++++++++++++++++++++++++++++++++++++"<<endl
			<< "+++ P9_OUTPUT >>> CREATED AN IMAGE_PROC OBJECT"<<endl
			<< "+++ P9_OUTPUT >>> IMAGE FILE IS "<<f1<<" WITH SIZE OF "<<n<<" X "<<n<<endl
			<< "+++ P9_OUTPUT >>> FILTER FILE IS "<<f2<<" WITH SIZE OF "<<f<<" X "<<f<<endl
			<< "+++ P9 END +++++++++++++++++++++++++++++++++++++++++++"<<endl;

}
  
void
IMAGE_PROC::PRINT(char * cmd)	// example: A1.PRINT("ALL");
{
	// your code goes below:
	out_f << "+++ P9 START +++++++++++++++++++++++++++++++++++++++++" <<endl;
	int i, j; 
	if( strcmp(cmd,"ALL")==0 || strcmp(cmd,"IMAGE")==0 || strcmp(cmd,"FILTER")==0 )
	{
			
		if( strcmp(cmd,"ALL")==0 || strcmp(cmd,"IMAGE")==0 )
		{
			out_f << "+++ P9_OUTPUT >>> IMAGE IS:" <<endl;
			for(i = 0; i < n; i++)
			{
				for(j = 0; j < n; j++)
				{
					out_f << image[i][j]<<" ";
				}
				out_f <<endl;
			}
		}
		else{}
		
		if( strcmp(cmd,"ALL")==0 || strcmp(cmd,"FILTER")==0)
		{
			out_f << "+++ P9_OUTPUT >>> FILTER IS:" <<endl;
			for(i = 0; i < f; i++)
			{
				for(j = 0; j < f; j++)
				{
					out_f << filter[i][j]<<" ";
				}
				out_f <<endl;
			}
		}
		else{}
	}
	else 
	{
		out_f << "+++ P9_OUTPUT >>> INPUT ERROR." <<endl;
	}
	out_f << "+++ P9 END +++++++++++++++++++++++++++++++++++++++++++" <<endl;
}

void
IMAGE_PROC::COUNT() 
{
	// your code goes below:
	
	out_f<< "+++ P9 START +++++++++++++++++++++++++++++++++++++++++" <<endl;
	//counts the instances of filter within image
	int i,j;
	int num_threads = n*n;
	std::thread t[num_threads];
	int id=0;
	int sum = 0;
	int read_success =0;
	
	for ( i=0 ;i<num_threads ;i++ )
	{
		result[i]=0;
	}
	
	for( i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			t[id] = std::thread(call_from_thread, id, i, j, n, f);
			id++;  
		}
	}
	for(i= 0; i < num_threads; i++)
	{
		t[i].join();
	}
	for(i = 0; i < num_threads; i++)
	{
		sum+=result[i];
	}
	
	out_f 	<<"+++ P9_OUTPUT >>> THERE ARE "<<sum<<" MATCHES OF FILTER IN IMAGE."<<endl
			<<"+++ P9 END +++++++++++++++++++++++++++++++++++++++++++" <<endl;
			
}
	
void
IMAGE_PROC::LOCATE() 
{
	// your code goes below:
	out_f<< "+++ P9 START +++++++++++++++++++++++++++++++++++++++++" <<endl;
	//counts the instances of filter within image and locates their positisons
	int i,j;
	int num_threads = n*n;
	std::thread t[num_threads];
	int id=0;
	int sum = 0;
	int read_success =0;
	
	for ( i=0 ;i<num_threads ;i++ )
	{
		result[i]=0;
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			t[id]=std::thread(call_from_thread,id,i,j,n,f);
			id++;
		}
	}
	
	for(i = 0; i < num_threads; i++)
	{
		t[i].join();
	}
	for(i = 0; i < num_threads; i++)
	{
		sum+=result[i];
	}
	out_f << "+++ P9_OUTPUT >>> THERE ARE " << sum << " MATCHES OF FILTER IN IMAGE AS FOLLOWS:" <<endl;
	
	for(i = 0; i < num_threads; i++)
	{
		if ( result[i]==1)
		{
			out_f << "+++ P9_OUTPUT >>> MATRIX LOCATION [" << result_x[i] << "," << result_y[i] << "]" <<endl;
		}
	}
	
	
	out_f << "+++ P9 END +++++++++++++++++++++++++++++++++++++++++++" <<endl;

	
}
