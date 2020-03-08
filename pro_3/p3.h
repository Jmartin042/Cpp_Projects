///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Jonathan Martinez(23261146)
// LOGIN_NAME: jmartin042
// EE259 SECTION (DAY/EVE):DAY
///////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_2/sample_p2.h" //centos prof file
//#include "/home/ee259d15/pro_2/p2.h" // centos my file

//#include "/home/jmartin042/ee259d15/test/pro_2/p2.h" //my own computer my own file
//#include "/home/jmartin042/ee259d15/test/pro_2/sample_p2.h" //my own computer, sample file

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
			o_f<<firstNames[i]<<" "<<lastNames[i]<<"   "<<id[i]<<"  ";
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
			o_f<<firstNames[i]<<" "<<lastNames[i]<<"   "<<id[i];
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

		for( i=0 ; i<n ; i++ )
		{
			strcpy(min_name,lastNames[i]);
			min_pos=i;
			for ( j = i; j < n; j++) //sorts by last name only
			{
				if(strcmp(min_name,lastNames[j])>0)
				{
					strcpy(min_name,lastNames[j]);
					min_pos=j;
				}
				else{}
			}
			strcpy(temp_name,firstNames[min_pos]); // swaps are performed for firstnames, lastnames, ids, pins and grades
			strcpy(firstNames[min_pos],firstNames[i]);
			strcpy(firstNames[i],temp_name);

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
	}
	else
	{
		o_f<<"******* INPUT ERROR"<<endl;
	}
	o_f<<"******* END ALPHABETIZE"<<endl;
}

int 
GRADES::VERIFY( char*F, char*L)
{	// your code goes below:
	o_f<<"******* START VERIFY"<<endl;
	int i,j, found,k;
	if (strlen(F)>16 || strlen(L)>16)
	{
		o_f<<"******* INPUT ERROR"<<endl;
		k=-2;
	}
	else
	{
		found=0;
		for(i=0;i<n && found==0 ;i++)
		{
			if( (strcmp(firstNames[i],F)==0) && (strcmp(lastNames[i],L)==0) )
			{
				found=1;
				k=i;
			}
			else
			{
				k=-1;
			}
		}
		if(found==1)
		{
			o_f<<"******* THERE IS A STUDENT AS "<<F<<" "<<L<<"."<<endl;
		}
		else
		{
			o_f<<"******* NO STUDENT AS "<<F<<" "<<L<<"."<<endl;
		}
	}
	o_f<<"******* END VERIFY"<<endl;
	return k; // make sure to modify this;
}

void
GRADES::REPORT(int w, int x, int y, int z)
{	// your code goes below:
	// x is ID, y is pin, z is exam, w is an additional parameter
	o_f<<"******* START REPORT"<<endl;
	int i,j;// checks the ranges for x,y,z and checks for valid w, w can be 1 and 0 but only when the rest are zero as well
	if( x<0 || x>=9999 || y<0 || y>=100 || z<0 || z>=e || w>1|| w<0 || (w==0 &&( w!=x || w!=y || w!=z)))
	{
		o_f<<"******* INPUT ERROR"<<endl;
	}
	else if(x==0 && y==0 && z==0 && w==0)
	{
		for(i=0;i<n;i++)
		{	
			o_f<<"***********";
			
			o_f<<firstNames[i]<<"*"<<lastNames[i];
			for(j=0;j<(38 -strlen(firstNames[i]) - strlen(lastNames[i]) );j++)
			{
				o_f<<"*";
			}
			o_f<<endl;
		}
	}
	else if(w==1)
	{
		SIMPLE_REPORT(x,y,z);
	}
	o_f<<"******* END REPORT"<<endl;
}
