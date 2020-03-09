///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: jonathan martinez
// CITYMAIL NAME: jmartin042
// EE259 SECTION (DAY/EVE): DAY
///////////////////////////////////////////////////////////////

//#include "/mnt/ee259dir/tools/pro_3/sample_p3.h" //centos prof file
//#include "/home/ee259d15/pro_3/p3.h" // centos my file

#include "/home/jmartin042/ee259d15/test/pro_3/p3.h" //my own computer my own file
//#include "/home/jmartin042/ee259d15/test/pro_3/sample_p3.h" //my own computer, sample file

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
	: GRADES(x, y) // call base class constructor;
{ // your code goes below:

	strcpy(objName,O_N);
	o_f<<"+++++++++ OVERLOADED_GRADES OBJECT IS CREATED WITH "<<x<<" STUDENTS EACH WITH "<<y<<" EXAMS."<<endl;
}

void
OVERLOADED_GRADES::OVERLOADED_LIST(int x)
{ // your code goes below:

	o_f<<"+++++++++ START OVERLOADED_LIST"<<endl;
	o_f<<"+++++++++ ELEMENTS OF "<<objName<<":"<<endl;

	if(x==0)
	{
		LIST(0);
	}
	else if(x==1)
	{
		LIST(5);
	}
	else if(x==2)
	{
		LIST(-5);
	}

	o_f<<"+++++++++ END OVERLOADED_LIST"<<endl;
}

int
OVERLOADED_GRADES::operator == (int x)  
{ // your code goes below:
	o_f<<"+++++++++ START OVERLOADED OPERATOR =="<<endl;
	int k;
	if(n==x)
	{
		o_f<<"+++++++++ RETURNING TRUE FOR "<<objName<<endl;
		k=1;
	}
	else
	{
		o_f<<"+++++++++ RETURNING FALSE FOR "<<objName<<endl;
		k=0;
	}

	o_f<<"+++++++++ END OVERLOADED OPERATOR =="<<endl;

	return k; // make sure to modify;
}

int
OVERLOADED_GRADES::operator == (OVERLOADED_GRADES obj2)  
{ // your code goes below:

	o_f<<"+++++++++ START OVERLOADED OPERATOR =="<<endl;
	int k;
	if(n==obj2.n)
	{
		k=1;
		o_f<<"+++++++++ RETURNING TRUE FOR "<<objName<<" AND "<<obj2.objName<<endl;
	}
	else
	{
		k=0;
		o_f<<"+++++++++ RETURNING FALSE FOR "<<objName<<" AND "<<obj2.objName<<endl;
	}

	o_f<<"+++++++++ END OVERLOADED OPERATOR =="<<endl;
	return k; // make sure to modify;
}

void
OVERLOADED_GRADES::operator -= (int x) 
{ // your code goes below:
	int k,i,j,found=0,found_pos;
	o_f<<"+++++++++ START OVERLOADED OPERATOR -="<<endl;
	
	if(x>=9999 || x<=0)
	{
		o_f<<"+++++++++ INPUT ERROR"<<endl;
	}
	else
	{
		SIMPLER_FIND(x,0);
		
		for (i = 0; i < n && found==0 ; i++)
		{
			if(id[i]==x)
			{
				found=1;
				found_pos=i;
			}
			else{}
		}
		if(found==1)
		{
			for(i=found_pos;i<n-1;i++) //removes all data from student with id x
			{
				id[i]=id[i+1];

				for (j = 0; j < e; j++)
				{
					exam_grades[i][j]=exam_grades[i+1][j];
				}

				pin[i]=pin[i+1];
				strcpy(firstNames[i], firstNames[i+1]);
				strcpy(lastNames[i], lastNames[i+1]);
			}
			n--;
			o_f<<"+++++++++ STUDENT WITH ID "<<x<<" IS REMOVED FROM "<<objName<<endl;
			o_f<<"+++++++++ NOW THERE ARE "<<n<<" STUDENTS"<<endl;
		}
		else
		{
			o_f<<"+++++++++ NO STUDENT WITH ID "<<x<<" FROM "<<objName<<endl;
		}		
	}
	o_f<<"+++++++++ END OVERLOADED OPERATOR -="<<endl;
}

void
OVERLOADED_GRADES::operator = (OVERLOADED_GRADES obj2) 
{ // your code goes below:
	o_f<<"+++++++++ START OVERLOADED OPERATOR ="<<endl; //copies object obj2 into refrence obj
	int i,j;
	n=obj2.n;
	e=obj2.e;

	for(i=0;i<n;i++)
	{
		id[i]=obj2.id[i];
		pin[i]=obj2.pin[i];

		for (j = 0; j < e; j++)
		{
			exam_grades[i][j]=obj2.exam_grades[i][j];
		}

		strcpy(firstNames[i], obj2.firstNames[i]);
		strcpy(lastNames[i], obj2.lastNames[i]);
	}

	o_f<<"+++++++++ ELEMENTS IN "<<obj2.objName<<" ARE ASSIGNED TO "<<objName<<endl;
	o_f<<"+++++++++ END OVERLOADED OPERATOR ="<<endl;

}

OVERLOADED_GRADES
OVERLOADED_GRADES::operator + (OVERLOADED_GRADES obj2)
{
	// declare a temporary object of class OVERLOADED_GRADES:
	OVERLOADED_GRADES obj("TempOBJ", 0, 0);
	// your code goes below:
	//refrence object no changes, second object = obj2. and temporary object = obj.
	int i,j;
	o_f<<"+++++++++ START OVERLOADED OPERATOR +"<<endl;
	
	obj.n=n;  //refrence object into temporary object
	obj.e=e;

	for(i=0;i<n;i++)
	{
		obj.id[i]=id[i];
		obj.pin[i]=pin[i];

		for (j = 0; j < e; j++)
		{
			obj.exam_grades[i][j]=exam_grades[i][j];
		}

		strcpy(obj.firstNames[i], firstNames[i]);
		strcpy(obj.lastNames[i], lastNames[i]);
	} //end of original object into temporary
	o_f<<"+++++++++ "<<n<<" ELEMENTS IN "<<objName<<" ARE ADDED TO "<<obj.objName<<endl;

	obj.n=obj.n+obj2.n; // second object into temporary object
	obj.e=obj2.e;

	for(i=n; i<obj.n; i++)
	{
		obj.id[i]=obj2.id[i-n];
		obj.pin[i]=obj2.pin[i-n];

		for (j = 0; j < e; j++)
		{
			obj.exam_grades[i][j]=obj2.exam_grades[i-n][j];
		}

		strcpy(obj.firstNames[i], obj2.firstNames[i-n]);
		strcpy(obj.lastNames[i], obj2.lastNames[i-n]);
	}
	o_f<<"+++++++++ "<<obj2.n<<" ELEMENTS IN "<<obj2.objName<<" ARE ADDED TO "<<obj.objName<<endl;
	o_f<<"+++++++++ RETURNING "<<obj.objName<<" WITH "<<obj.n<<" ELEMENTS"<<endl;
	o_f<<"+++++++++ END OVERLOADED OPERATOR +"<<endl;

	return obj; // return the temporary object;
}
