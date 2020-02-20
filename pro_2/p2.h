///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME:Jonathan Martinez
// LOGIN_NAME:jmartin042
// EE259 SECTION (DAY/EVE):DAY
///////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_1/sample_p1.h"
//#include "/home/ee259d15/pro_1/p1.h"
using namespace std;

ifstream i_f_2; // declare a pointer to pin input file;

  class SIMPLE_GRADES: public SIMPLER_GRADES{
   public:      // public methods for this class

        SIMPLE_GRADES(int, int); // constructor;
		// example usage: g.SIMPLE_GRADES(x, y);
		// create an object called g with x students each with y grades;

	void SIMPLE_SORT(int); // a method;
		// example usage: b.SIMPLE_SORT(x);
		// if x is 1, sort students in ascending order;
		// returns no values;

	void SIMPLE_MAX(int); // another method;
		// example usage: b.SIMPLE_MAX(x);
		// find student(s) received max grade for exam x;
		// returns no values;

	int SIMPLE_FIND(int, int);  //another method;
		// example usage: b.SIMPLE_FIND(x, y);
		// search student id x and pin y;
		// returns index for the found student;

	int SIMPLE_REPORT(int, int, int);  //another method;
		// example usage: b.SIMPLE_REPORT(x, y, z);
		// for student id x and pin y, report grade in exam z;
		// returns no values;
	protected:
		int pin[20]; // pin values for students;
   };

SIMPLE_GRADES::SIMPLE_GRADES(int x, int y)
	: SIMPLER_GRADES(x, y)
{
	int i;
	// below, open input file for pin and read its contents:
	i_f.open("studentPins.txt", ios::in); // open input file;
	for(i =0; i < n; i++)
	{
		i_f >> pin[i];
	}
	i_f.close(); // close input file;
	i_f.clear(); // rewind file pointer to the top of the file;	
	o_f << "+++++ SIMPLE_GRADES CONSTRUCTOR CREATES A NEW OBJECT WITH PIN VALUES."<< endl;

}

void 
SIMPLE_GRADES::SIMPLE_SORT(int x)
{
	// your code goes below:
	int i,j,k,temp,min,min_pos;
	o_f << "+++++ START SIMPLE_SORT"<< endl;
	if(x==1)
	{
		o_f << "+++++ STUDENTS SORTED IN ASCENDING ORDER BASED ON IDS:"<< endl;
		for ( i = 0; i < n; i++)// goes through ent
		{
			min=id[i];
			min_pos=i;
			for ( j = i; j < n; j++)
			{
				if(min>id[j])
				{
					min=id[j];
					min_pos=j;
				}
				else{}
			}
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
		SIMPLEST_LIST(2);
	}
	else
	{
		o_f << "+++++ INPUT ERROR"<< endl;
	}
	o_f << "+++++ END SIMPLE_SORT"<< endl;
}

void 
SIMPLE_GRADES::SIMPLE_MAX(int x) // another method;
{
	// your code goes below:
	int max,i;
	o_f<<"+++++ START SIMPLE_MAX"<<endl;
	if(x<0 || x>e)
	{
		o_f<<"+++++ INPUT ERROR"<<endl;	
	}
	else
	{
		max=exam_grades[0][x];
		for ( i = 1; i < e; i++)//finds max and places it into max
		{		
			if(max<exam_grades[i][x])
			{
				max=exam_grades[i][x];
			}
			else{}
		}
		o_f<<"+++++ MAX GRADE FOR EXAM "<<x<<" IS "<<max<<"."<<endl;
	}
	o_f<<"+++++ END SIMPLE_MAX"<<endl;
}

int 
SIMPLE_GRADES::SIMPLE_FIND(int x, int y)  //another method;
{
	// your code goes below:
	o_f<<"+++++ START SIMPLE_FIND"<<endl;
	int i, id_pos, pin_pos,k;
	if((x<0 || x>9999)||(y<0||y>100))
	{
		o_f<<"+++++ INPUT ERROR"<<endl;
		k=-2;
	}
	else
	{
		for (i = 0; i < n; i++)//finds ID and pin positions within array
		{
			if(x==id[i])
			{
				id_pos=i;
			}
			else{}
			if(y==pin[i])
			{
				pin_pos=i;
			}
			else{}
		}
		if(id_pos==pin_pos)// ID and pin postions must match for positive ID
		{
			o_f<<"+++++ THERE IS A STUDENT WITH ID "<<x<<"."<<endl;
		}
		else
		{
			o_f<<"+++++ NO STUDENT WITH ID "<<x<<"."<<endl;
			k=-1;
		}
	}
	o_f<<"+++++ END SIMPLE_FIND"<<endl;
	return k; // make sure to modify this;
}

int
SIMPLE_GRADES::SIMPLE_REPORT(int x, int y, int z)
{
	// your code goes below:
	o_f<<"+++++ START SIMPLE_REPORT"<<endl;
	int i,id_pos, pin_pos,k;
	if(( x<0 || x>9999 )||( y<0 || y>100 )||( z<0 || z>=e ))
	{
		o_f<<"+++++ INPUT ERROR"<<endl;
		k=-2;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			if(x==id[i])
			{
				id_pos=i;
			}
			else{}
			if(y==pin[i])
			{
				pin_pos=i;
			}
			else{}
		}
		if(id_pos==pin_pos)// if postions match we display ID, exam # and grade of exam.
		{
			o_f<<"+++++ GRADE OF STUDENT "<<x<<" FOR EXAM "<<z<<" IS "<< exam_grades[pin_pos][z]<<"."<<endl;
			k=pin_pos;
		}
		else
		{
			o_f<<"+++++ NO STUDENT WITH ID "<<x<<"."<<endl;
			o_f<<"+++++ ALL STUDENT IDS ARE:"<<endl;
			SIMPLEST_LIST(1);
			k=-1;
		}
	}
	o_f<<"+++++ END SIMPLE_REPORT"<<endl;
	return k; // make sure to modify this;
}
