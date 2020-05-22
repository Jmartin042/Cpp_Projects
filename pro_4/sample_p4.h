///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Umit Uyar
// CITYMAIL NAME: ee259
// EE259 SECTION (DAY/EVE): Day and Evening 
///////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_3/sample_p3.h"

using namespace std;

  class OVERLOADED_GRADES: public GRADES{
   public:      // public methods for this class

        OVERLOADED_GRADES(char *, int, int); // constructor;
		// example usage: g.OVERLOADED_GRADES("G1", x, y);
		// create an object g with x students each with y grades;

	void OVERLOADED_LIST(int); // a method;
		// example usage: b.OVERLOADED_LIST(x);
		// returns no values;

	int operator == (int);  
		// an overloaded operator;
		// example usage: if (g == 4)
		// returns integer;

	int operator == (OVERLOADED_GRADES);  
		// another overloaded operator;
		// example usage: if (g1 == g2)
		// returns integer;

        void operator -= (int); 
		// another overloaded operator;
		// example usage: g -= 1234;
		// returns nothing;

        void operator = (OVERLOADED_GRADES); 
		// another overloaded operator;
		// example usage: g1 = g2;
		// returns nothing;

        OVERLOADED_GRADES operator + (OVERLOADED_GRADES); 
		// another overloaded operator;
		// example usage: g1+g2;
		// returns OVERLOADED_GRADES object;
   private:
	char objName[15]; // name for the object; max length 14;
   };

OVERLOADED_GRADES:: OVERLOADED_GRADES(char * O_N, int x, int y)
	: GRADES(x, y)
{
	strcpy (objName, O_N);

  	o_f << "+++++++++ OVERLOADED_GRADES OBJECT IS CREATED WITH "
		<< x << " STUDENTS EACH WITH " << y << " EXAMS." << endl;
}

void
OVERLOADED_GRADES::OVERLOADED_LIST(int x)
{
  	o_f << "+++++++++ START OVERLOADED_LIST" << endl;
  	o_f << "+++++++++ ELEMENTS OF " << objName << ":" << endl;
cout << "x is " << x << " obj is " << objName << " n " << n << " e " << e << endl;
	if(x == 0)
	{
		LIST(1);
	}
	else if(x == 1)
	{
		LIST(5);
	}
	else if(x == 2)
	{
		LIST(-5);
	}
	else
	{
  		o_f << "+++++++++ INPUT ERROR" << endl;
	}
  	o_f << "+++++++++ END OVERLOADED_LIST" << endl;
}

int
OVERLOADED_GRADES::operator == (int x)  
{
  	o_f << "+++++++++ START OVERLOADED OPERATOR ==" << endl;
	if(n == x)
	{
  		o_f << "+++++++++ RETURNING TRUE FOR " << objName << endl;
  		o_f << "+++++++++ END OVERLOADED OPERATOR ==" << endl;
		return 1;
	}
	else
	{
  		o_f << "+++++++++ RETURNING FALSE FOR " << objName << endl;
  		o_f << "+++++++++ END OVERLOADED OPERATOR ==" << endl;
		return 0;
	}
}

int
OVERLOADED_GRADES::operator == (OVERLOADED_GRADES obj2)  
{
  	o_f << "+++++++++ START OVERLOADED OPERATOR ==" << endl;
	if(n ==  obj2.n)
	{
  		o_f << "+++++++++ RETURNING TRUE FOR " << objName 
			<< " AND " << obj2.objName << endl;
  		o_f << "+++++++++ END OVERLOADED OPERATOR ==" << endl;
		return 1;
	}
	else
	{
  		o_f << "+++++++++ RETURNING FALSE FOR " << objName 
			<< " AND " << obj2.objName << endl;
  		o_f << "+++++++++ END OVERLOADED OPERATOR ==" << endl;
		return 0;
	}
}

void
OVERLOADED_GRADES::operator -= (int x) 
{
	int i, j, ret_val;

	o_f << "+++++++++ START OVERLOADED OPERATOR -=" << endl;
	if (x <= 0 || x >= 10000)
	{
		o_f << "+++++++++ INPUT ERROR" << endl;
	}
	else
	{
		ret_val = SIMPLER_FIND(x, 0);
		if (ret_val == -1)
		{
			o_f << "+++++++++ NO STUDENT WITH ID "
				<< x << " IN " << objName << endl;
		}
		else
		{
			for(i = ret_val; i < n-1; i++)
			{
				id[i] = id[i+1];
				pin[i] = pin[i+1];
				for(j = 0; j < e; j++)
				{
					exam_grades[i][j] = exam_grades[i+1][j];
				}
				strcpy(firstNames[i], firstNames[i+1]);
				strcpy(lastNames[i], lastNames[i+1]);
			}
			n--; // decrement n;
			o_f << "+++++++++ STUDENT WITH ID " << x 
				<< " IS REMOVED FROM " << objName << endl;
			o_f << "+++++++++ NOW THERE ARE " << n 
				<< " STUDENTS" << endl;
		}

	}
  	o_f << "+++++++++ END OVERLOADED OPERATOR -=" << endl;
}

void
OVERLOADED_GRADES::operator = (OVERLOADED_GRADES obj2) 
{
	int i, j;
  	o_f << "+++++++++ START OVERLOADED OPERATOR =" << endl;

	n = obj2.n; 
	e = obj2.e; 
	for(i = 0; i < n; i++)
	{
		id[i] = obj2.id[i];
		pin[i] = obj2.pin[i];
		
		for(j = 0; j < e; j++)
		{
			exam_grades[i][j] = obj2.exam_grades[i][j];
		}
		strcpy(firstNames[i], obj2.firstNames[i]);
		strcpy(lastNames[i], obj2.lastNames[i]);
	}
	o_f << "+++++++++ ELEMENTS IN " << obj2.objName 
		<< " ARE ASSIGNED TO " << objName << endl;
  	o_f << "+++++++++ END OVERLOADED OPERATOR =" << endl;
}

OVERLOADED_GRADES
OVERLOADED_GRADES::operator + (OVERLOADED_GRADES obj2)
{
	int i, j;
	OVERLOADED_GRADES obj("TempOBJ", 0, 0);

	obj.e = e;
  	o_f << "+++++++++ START OVERLOADED OPERATOR +" << endl;
	for(i = 0; i < n; i++)
	{
		obj.id[i] = id[i];
		obj.pin[i] = pin[i];
		for(j = 0; j < e; j++)
		{
			obj.exam_grades[i][j] = exam_grades[i][j];
		}
		strcpy(obj.firstNames[i], firstNames[i]);
		strcpy(obj.lastNames[i], lastNames[i]);
	}
	obj.n = n;
	o_f << "+++++++++ " << n << " ELEMENTS IN " << objName 
		<< " ARE ADDED TO " << obj.objName << endl;

	for(i = 0; i < obj2.n; i++)
	{
		obj.id[i+n] = obj2.id[i];
		obj.pin[i+n] = obj2.pin[i];
		
		//for(j = 0; j < obj2.e; j++)
		for(j = 0; j < e; j++)
		{
			obj.exam_grades[i+n][j] = obj2.exam_grades[i][j];
		}
		strcpy(obj.firstNames[i+n], obj2.firstNames[i]);
		strcpy(obj.lastNames[i+n], obj2.lastNames[i]);
	}
	obj.n += obj2.n;
	obj.e = e;
	o_f << "+++++++++ " << obj2.n << " ELEMENTS IN " << obj2.objName 
		<< " ARE ADDED TO " << obj.objName << endl;
	o_f << "+++++++++ RETURNING " << obj.objName 
		<< " WITH " << obj.n << " STUDENTS" << endl;
  	o_f << "+++++++++ END OVERLOADED OPERATOR +" << endl;
cout << "returning from +: obj.objName " << obj.objName 
	<< " obj.n " << obj.n << " obj.e " << obj.e << endl;
	return obj;
}
