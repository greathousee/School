// Course: CSC 226 Introduction to Programming with C++
// Name: Eddie Greathouse
// Assignment A5: tOGGLE
/*
 Purpose: <This program take a letter, either upper case or lower case, then converts the letter to lower case or upper case.
 This assignment was completed seperately because my partner and I could not meet up to work on the project outside of class.>
*/
#include <iostream>

using namespace std;
int main()
 {char usersnumber; //this gives a name to the variable that the user will input

    cout << "Welcome. Please enter a letter.\n";
    cin >> usersnumber; //this is the letter that the user inputs
    if ( (usersnumber > 96) && (usersnumber < 121)){ // if the letter is lower case, it gives the letter in upper case
        usersnumber = usersnumber - 32;
        cout << usersnumber << endl;



}
        else
            if ( (usersnumber > 64) && (usersnumber < 91) ){ // if the letter is upper case, it gives the letter in lower case
            usersnumber = usersnumber + 32;
            cout << usersnumber << endl;
            }
            else
                cout << usersnumber << " is not a letter. \n";







            return 0;
}
