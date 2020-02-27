///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Uyar
// LOGIN_NAME: ee259
// EE259 SECTION (DAY/EVE): day and night 
///////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_1/sample_p1.h"

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
	i_f_2.open("studentPins.txt", ios::in); // open input file;

	for(i =0; i < n; i++)
	{
		i_f_2 >> pin[i];
	}
	i_f_2.close(); // close input file;
	i_f_2.clear(); // rewind file pointer to the top of the file;

	o_f << "+++++ SIMPLE_GRADES CONSTRUCTOR CREATES A NEW OBJECT WITH PIN VALUES." << endl;
}

void 
SIMPLE_GRADES::SIMPLE_SORT(int x)
{
	int i, j, k, temp, min, min_pos;
	o_f << "+++++ START SIMPLE_SORT" << endl;
	if(x == 1)
	{
		for(i = 0; i < n; i++)
		{
			min = id[i];
			min_pos = i;
			for(j = i; j < n; j++)
			{
				if(min > id[j])
				{
					min = id[j];
					min_pos = j;
				}
				else{}
			}
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
		o_f << "+++++ STUDENTS SORTED IN ASCENDING ORDER BASED ON IDS:" << endl;
		SIMPLEST_LIST(2);
	}
	else
	{
		o_f << "+++++ INPUT ERROR" << endl;
	}
	o_f << "+++++ END SIMPLE_SORT" << endl;
}

void 
SIMPLE_GRADES::SIMPLE_MAX(int x) // another method;
{
	int i, max;

	o_f << "+++++ START SIMPLE_MAX" << endl;
	if(x >=0 && x < e)
	{
		max = exam_grades[0][x];
		for(i = 0; i < n; i++)
		{
			if (max < exam_grades[i][x])
			{
				max = exam_grades[i][x];
			}
			else{}
		}

		o_f << "+++++ MAX GRADE FOR EXAM " << x << " IS "
			<< max << "." << endl;
	}
	else
	{
		o_f << "+++++ INPUT ERROR" << endl;
	}
	o_f << "+++++ END SIMPLE_MAX" << endl;
}

int 
SIMPLE_GRADES::SIMPLE_FIND(int x, int y)  //another method;
{
	int i, FOUND, FOUND_POS;

	o_f << "+++++ START SIMPLE_FIND" << endl;
	if(x >0 && x < 10000 && y > 0 && y < 100)
	{
		FOUND = 0;
		for(i = 0; i < n && FOUND == 0; i++)
		{
cout << " id[" << i << "] " << id[i] << "\tpin[" << i << "] " << pin[i] << endl;
			if(id[i] == x && pin[i] == y)
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}
cout << " FOUND IS " << FOUND << endl;
		if (FOUND == 1)
		{
			o_f << "+++++ THERE IS A STUDENT WITH ID " 
				<< x << "." << endl;
			o_f << "+++++ END SIMPLE_FIND" << endl;
			return FOUND_POS;
		}
		else
		{
			o_f << "+++++ NO STUDENT WITH ID " 
				<< x << "." << endl;
			o_f << "+++++ END SIMPLE_FIND" << endl;
			return -1;
		}
	}
	else
	{
		o_f << "+++++ INPUT ERROR" << endl;
		o_f << "+++++ END SIMPLE_FIND" << endl;
		return -2;
	}
}

int
SIMPLE_GRADES::SIMPLE_REPORT(int x, int y, int z)
{
	int i, FOUND, FOUND_POS;

	o_f << "+++++ START SIMPLE_REPORT" << endl;
	if(x > 0 && x < 10000 && y > 0 && y < 100 && z >=0 && z < e)
	{
		FOUND = 0;
		for(i = 0; i < n && FOUND == 0; i++)
		{
			if(id[i] == x && pin[i] == y)
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}
		if(FOUND == 1)
		{
			o_f << "+++++ GRADE OF STUDENT "
				<< x << " FOR EXAM " << z 
				<< " IS " << exam_grades[FOUND_POS][z] 
				<< "." << endl;
			o_f << "+++++ END SIMPLE_REPORT" << endl;
			return FOUND_POS;
		}
		else
		{
			o_f << "+++++ NO STUDENT WITH ID " 
				<< x << "." << endl;
			o_f << "+++++ ALL STUDENT IDS ARE:" << endl;
			SIMPLEST_LIST(1);
			o_f << "+++++ END SIMPLE_REPORT" << endl;
			return -1;
		}
	}
	else
	{
		o_f << "+++++ INPUT ERROR" << endl;
		o_f << "+++++ END SIMPLE_REPORT" << endl;
		return -2;
	}
}
