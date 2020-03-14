///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Uyar
// LOGIN_NAME: ee259
// EE259 SECTION (DAY/EVE): everyday and every night 
///////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_2/sample_p2.h"
//#include "/home/jmartin042/ee259d15/test/pro_2/sample_p2.h" //my own computer, sample file

#include "string.h"
//#include "sample_p2.h"

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
	: SIMPLE_GRADES(x, y) // call base class constructor (it is the rule);
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
{
	int i, j;
	o_f << "******* START LIST" << endl;
	if(x == 0)
	{
		for(i = 0; i < n; i++)
		{
			o_f << firstNames[i] << "\t" << lastNames[i]
				<< "\t" << id[i] << endl;
		}
	}
	else if(x == 5)
	{
		for(i = 0; i < n; i++)
		{
			o_f << firstNames[i] << "\t" << lastNames[i]
				<< "\t" << id[i] << "\t";
			for(j = 0; j < e; j++)
			{
				o_f << exam_grades[i][j] << " ";
			}
			o_f << endl;
		}
	}
	else if (x == -5)
	{
		SIMPLEST_LIST(2);
	}
	else
	{
		o_f << "******* INPUT ERROR" << endl;
	}
	o_f << "******* END LIST" << endl;
}

void 
GRADES::ALPHABETIZE(int x)
{
	int i, j, k, temp, min, min_pos;
	char temp_name[15], min_name[15];

	o_f << "******* START ALPHABETIZE" << endl;
	if(x == 1)
	{
		for(i = 0; i < n; i++)
		{
cout << "i " << i << endl;
			strcpy(min_name, lastNames[i]); 
			min_pos = i;
			for(j = i; j < n; j++)
			{
cout << "\tj " << j << endl;
				if(strcmp(min_name, lastNames[j]) > 0)
				{
					strcpy(min_name, lastNames[j]); 
					min_pos = j;
				}
				else{}
			}
			// swamp lastNames[i] and lastNames[min_pos]:
			strcpy(temp_name , lastNames[i]);
			strcpy(lastNames[i] , lastNames[min_pos]);
			strcpy(lastNames[min_pos] , temp_name);

			// swamp firstNames[i] and firstNames[min_pos]:
			strcpy(temp_name , firstNames[i]);
			strcpy(firstNames[i] , firstNames[min_pos]);
			strcpy(firstNames[min_pos] , temp_name); 
			// swamp id[i] and id[min_pos]:
			temp = id[i];
			id[i] = id[min_pos];
			id[min_pos] = temp;

			// swamp pin[i] and pin[min_pos]:
			temp = pin[i];
			pin[i] = pin[min_pos];
			pin[min_pos] = temp;

			// swamp exam_grades[i][*] and exam_grades[min_pos][*]:
			for(k = 0; k < e; k++)
			{
				temp = exam_grades[i][k];
				exam_grades[i][k] = exam_grades[min_pos][k];
				exam_grades[min_pos][k] = temp;
			}
		}
		o_f << "******* STUDENTS SORTED IN ALPHABETICAL ORDER "
			<< " BASED ON LAST NAMES:" << endl;
		LIST(5);
	}
	else
	{
		o_f << "******* INPUT ERROR" << endl;
	}
	o_f << "******* END ALPHABETIZE" << endl;
}

int 
GRADES::VERIFY(char * F, char * L)
{
	int i, FOUND, FOUND_POS;
	o_f << "******* START VERIFY" << endl;
	if(strlen(F) > 14 || strlen(L) > 14)
	{
		o_f <<"******* INPUT ERROR" << endl;
		o_f << "******* END VERIFY" << endl;
		return -2;
	}
	else
	{
		FOUND = 0;
		for(i = 0; i < n && FOUND == 0; i++)
		{
			if(strcmp(F, firstNames[i]) == 0 && 
					strcmp(L, lastNames[i]) == 0)
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}
		if(FOUND == 1)
		{
			o_f << "******* THERE IS A STUDENT AS " << F 
				<< " " << L << "." << endl;
			o_f << "******* END VERIFY" << endl;
			return FOUND_POS;
		}
		else
		{
			o_f << "******* NO STUDENT AS " << F 
				<< " " << L << "." << endl;
			o_f << "******* END VERIFY" << endl;
			return -1;
		}
	}
}

void
GRADES::REPORT(int w, int x, int y, int z)
{
	int i, j, limit;
	o_f << "******* START REPORT" << endl;
	if (w == 1 && x > 0 && x < 10000 && y > 0 && y < 100 && z >=0 && z < e)
	{
		SIMPLE_REPORT(x, y, z);
	}
	else if (w == 0 && x == 0 && y == 0 && z ==0)
	{
		//12345678901234567890123456789012345678901234567890
		//**********first_name_0*last_name_0****************
		//...
		//**********first_name_n-1*last_name_n-1************
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < 11; j++)
			{
				o_f << "*";
			}

			o_f << firstNames[i] << "*" << lastNames[i];
			limit = 50 - (11 + strlen(firstNames[i]) + 1 + strlen(lastNames[i]));
			cout << "limit is " << limit << endl;
			
			for (j = 0; j < limit; j++)
			{
				o_f << "*";
			}
			o_f << endl;
		}
	}
	else
	{
		o_f <<"******* INPUT ERROR" << endl;
	}
	o_f << "******* END REPORT" << endl;
}
