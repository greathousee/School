// File Name: greathousee-A3
#include <iostream>
using namespace std;
int main() {
double num1 = -2;

cout << "Temp (Celsius)" << "\t" << "  Temp (Farhenheit)"; //gives title
 while( num1 < 31 ){ //creates the loop
    cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(1);
    cout << num1 << "      \t      " << num1*(9/5) + 32 << endl;
    num1 = num1 + 1;

 }
//converting dollars to pounds
 double dollar, pound = 0;

 cout << "Please enter the value of US dollar per pound (i.e 1.56)" ; //asks user the cost of a pound in dollars
 cout << " ";

 cin >> dollar;

 cout << "Pounds" << "   " << "Dollars"; //gives titles to chart
 while( pound < 201 ) //creates a loop
    {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << pound << "\t" << pound*dollar << endl;
    pound = pound + 5;
    }

    return 0;
 }
