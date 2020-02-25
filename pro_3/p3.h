///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Jonathan Martinez(23261146)
// LOGIN_NAME: jmartin042
// EE259 SECTION (DAY/EVE):DAY
///////////////////////////////////////////////////////////////

//#include "/mnt/ee259dir/tools/pro_2/sample_p2.h" //centos prof file
#include "/home/ee259d15/pro_2/p2.h" // centos my file

//#include "/home/jmartin042/ee259d15/test/pro_1/p1.h" //my own computer my own file
//#include "/home/jmartin042/ee259d15/test/pro_1/sample_p1.h" //my own computer, sample file

#include "string.h"

using namespace std;

ifstream i_f_3; // declare a pointer to pin input file;

  class GRADES: public SIMPLE_GRADES{
   public:      // public methods for this class

        GRADES(int, int); // constructor;
		// example usage: g.GRADES(x, y);
		// create an object called g with x students each with y grades;

	void LIST(int); // a method;
		// example usage: b.LIST(x);
		// returns no values;

	void ALPHABETIZE(int); // a method;
		// example usage: b.ALPHABETIZE(x);
		// returns no values;

	int VERIFY(char *, char *); // another method;
		// example usage: b.VERIFY("KATE", "OGGEN");
		// returns integer;

	void REPORT(int, int, int, int);  //another method;
		// example usage: b.REPORT(w, x, y, z);
		// returns no values;

	protected:
		char firstNames[20][15]; // first names for students;
		char lastNames[20][15]; // last names for students;
   };

GRADES::GRADES(int x, int y)
	: SIMPLE_GRADES(x, y)
{
	int i;
	i_f_3.open("studentNames.txt", ios::in); // open input file;

	for(i =0; i < n; i++)
	{
		i_f_3 >> firstNames[i];
		i_f_3 >> lastNames[i];
	}
	i_f_3.close(); // close input file;
	i_f_3.clear(); // rewind file pointer to the top of the file;

	o_f << "******* GRADES CONSTRUCTOR CREATES A NEW OBJECT WITH NAMES OF "
		<< x << " STUDENTS." << endl;
}

void
GRADES::LIST(int x)
{	// your code goes below:
	o_f<<"******* START LIST"<<endl;
	int i,j;
	if(x==5)
	{
		for ( i=0; i<n; i++)
		{
			o_f<<firstNames[i]<<" "<<lastNames[i]<<"  ";
			for(j=0 ; j<e ;j++)
			{
				o_f<<exam_grades[i][j]<<" ";
			}
			o_f<<endl;
		}
	}
	else if(x==0)
	{
		for ( i=0; i<n; i++)
		{
			o_f<<firstNames[i]<<" "<<lastNames[i]<<" "<<id[i];
			o_f<<endl;
		}
	}
	else if(x==-5)
	{
		SIMPLEST_LIST(2);
	}
	else
	{
		o_f<<"******* INPUT ERROR"<<endl;
	}
	o_f<<"******* END LIST"<<endl;
}

void 
GRADES::ALPHABETIZE(int x)
{	// your code goes below:
	o_f<<"******* START ALPHABETIZE"<<endl;
	char min_name[15], temp_name[15];
	int i,j,k,min_pos, temp; 
	if(x==1)
	{
		o_f<<"******* STUDENTS SORTED IN ALPHABETICAL ORDER BASED ON LAST NAMES:"<<endl;
		o_f<<"******* START LIST"<<endl;

		for( i=0 ; i<n ; i++ )
		{
			strcpy(min_name,lastNames[i]);
			min_pos=i;
			for ( j = i; j < n; j++)
			{
				if(strcmp(min_name,lastNames[j])>0)
				{
					strcpy(min_name,lastNames[j]);
					min_pos=j;
				}
				else{}
			}
			strcpy(temp_name,lastNames[min_pos]);
			strcpy(lastNames[min_pos],lastNames[i]);
			strcpy(lastNames[i],temp_name);

			temp=id[i]; 
			id[i]=id[min_pos]; 
			id[min_pos]=temp; 

			temp=pin[i];
			pin[i]=pin[min_pos];
			pin[min_pos]=temp;

			for ( k = 0; k < e; k++)
			{
				temp=exam_grades[i][k];
				exam_grades[i][k]=exam_grades[min_pos][k];
				exam_grades[min_pos][k]=temp;
			}
		}
		LIST(5);
		o_f<<"******* END LIST"<<endl;
	}
	else
	{
		o_f<<"******* INPUT ERROR"<<endl;
	}
	o_f<<"******* END ALPHABETIZE"<<endl;
}

int 
GRADES::VERIFY(char * F, char * L)
{	// your code goes below:

	return -2; // make sure to modify this;
}

void
GRADES::REPORT(int w, int x, int y, int z)
{	// your code goes below:
	

}
