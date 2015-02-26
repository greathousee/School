// Course: CSC 226 Introduction to Programming with C++
// Name: Eddie Greathouse
// Assignment A17: <This program takes as a stream a text file called greathousee-story.txt, it then adds words similar to the madlib game.>
/*
 Purpose: <In order to accomplish this goal, the program stores the text file into a stream. It then
 finds the location of brackets, and the number immediatly following the brackets. Depending on the number following the bracket
 (implements a switch statement) it inputs a stream determined by the user.>
*/
#include <iostream>
#include <string> //Include the standard C++ String library
#include <cctype>
#include <fstream>
#include <vector>
using namespace std;

int main( )
{
    vector<string> storyVector;
    string str0, str1, str2, str3, str4, str5, str6, strstory;
    ifstream letterstream;
    letterstream.open("greathousee-story.txt");
    if (letterstream.fail())
    {
        cout << "Input file opening failed." << endl;
    }
    while (!letterstream.eof())
    {
        string character;
        int count;
        character = letterstream.get();
        storyVector.push_back(character);
        count++;
    }
    cout << "Enter the name of a person." << endl;
    cin >> str0;
    cout << "Enter the name of a place." << endl;
    cin >> str1;
    cout << "Enter an adjective." << endl;
    cin >> str2;
    cout << "Enter a noun." << endl;
    cin >> str3;
    cout << "Enter a verb in the present participle tense." << endl;
    cin >> str4;
    cout << "Enter an adverb." << endl;
    cin >> str5;
    cout << "Enter the name of another person." << endl;
    cin >> str6;
    char END='E';
    getline(letterstream, strstory, END);
    int bracket_position = strstory.find("[");
    int end_position=strstory.find('E');
    if (bracket_position>end_position)
    {
     int number = strstory[bracket_position+1]-48;
     switch (number)
     {
     case 0:
        int end_bracket_position=strstory.find("]");
        int counting=bracket_position-end_bracket_position;
        strstory.erase(bracket_position, counting);
        strstory.insert(bracket_position, str0);
        break;
    case 1:
        int end_bracket_position=strstory.find("]");
        int counting=bracket_position-end_bracket_position;
        strstory.erase(bracket_position, counting);
        strstory.insert(bracket_position, str1);
        break;
    case 2:
        int end_bracket_position=strstory.find("]");
        int counting=bracket_position-end_bracket_position;
        strstory.erase(bracket_position, counting);
        strstory.insert(bracket_position, str2);
        break;
    case 3:
        int end_bracket_position=strstory.find("]");
        int counting=bracket_position-end_bracket_position;
        strstory.erase(bracket_position, counting);
        strstory.insert(bracket_position, str3);
        break;
    case 4:
        int end_bracket_position=strstory.find("]");
        int counting=bracket_position-end_bracket_position;
        strstory.erase(bracket_position, counting);
        strstory.insert(bracket_position, str4);
        break;
    case 5:
        int end_bracket_position=strstory.find("]");
        int counting=bracket_position-end_bracket_position;
        strstory.erase(bracket_position, counting);
        strstory.insert(bracket_position, str5);
        break;
    case 6:
        int end_bracket_position=strstory.find("]");
        int counting=bracket_position-end_bracket_position;
        strstory.erase(bracket_position, counting);
        strstory.insert(bracket_position, str6);
        break;
     }
     int bracket_position = strstory.find("[");
    }
    cout << strstory;


    for (int i=0; i<storyVector.size()-1; i++)
    {
        cout << storyVector[i];
    }
 return 0;
}
