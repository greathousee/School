// Course: CSC 226 Introduction to Programming with C++
// Name: Eddie Greathouse Jack Weisensee
// Assignment A5: tOGGLE
/*
 Purpose: <Put a more in-depth description of the program here, and an
 explanation as to why you submitted separate source files if you decided
 to continue to work on the assignment separately.>
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







            return 0;
}
