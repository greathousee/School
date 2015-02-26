/*  debugme.cpp
    Author: Dr. Jan Pearce
    Important note:
    The Code::Blocks debugger will not work unless you use a project in the workspace!!!
    Purpose: A second program for learning to use the debugger*/

#include <iostream>
using namespace std;

char get_grade();
//Returns 'A' or 'B' based on input by user

int main ()
{
	char grade;
	grade=get_grade();

	if (grade=='A' || grade=='a')
	{
		cout << "\n It is great that you want an A! \n"<< endl;
	}
	else
	{
		cout << "\n Why do you only want a B? \n" <<endl;
	}

	return 0;
}

char get_grade()
//Returns 'A' or 'B' based on input by user
{
	int inputg;
	do
	{
	cout<<" Do you want to get an A or a B in this course?" << endl;
	cout<<" Please enter either A or B: ";
	cin >>inputg;

	} while (inputg!='A' && inputg!='B' && inputg!='a' && inputg!='b');

	return inputg;
}



