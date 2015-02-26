/*  debugging-example.cpp
    Author: Dr. Jan Pearce
    Important note:
    The Code::Blocks debugger will not work unless you use a project in the workspace!!!
    Purpose: To learn to use the debugger*/

#include <iostream>
using namespace std;

void dumbfunction(int&  i);

int main()
{
	char answer;
	cout << "This program does something.\n Use the debugger to understand.\n" << endl;

    for (int i=1; i<1000; i=i*2){

    cout << "i = ";
    cout << i++ << endl;

    dumbfunction(i);
    }

    return 0;
}

void dumbfunction(int&  k){
 k++;
}
