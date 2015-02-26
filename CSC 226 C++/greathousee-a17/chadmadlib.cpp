#include <iostream>
#include <fstream>
#include <string >
#include <vector>
using namespace std;


int main(){
    ifstream input;
    ofstream output;
    string file;
    string fullStory [250];
    string usersStuff[200];
    string myStory[250];
    int counter (0);

    cout << "What is the story file name? ";
    cin >> file;
    input.open(file.c_str());

    while (getline(input, fullStory[counter]))
        counter ++;

    input.close();
    int x(0),y(0);
    int index;int z(0);

    // printing of the file line by line;
    for (int i = 0; i < counter; i ++){
       do{
            x = fullStory[i].find("[");
            y = fullStory[i].find("]",x+1);

            if ( y > -1){
                int lenSub = y - x;
                string sub = fullStory[i].substr(x,lenSub+1);
                // do work
                int x2, y2;
                int userInput;
                userInput= sub[1] - 48;
                if ( sub.length () > 3){
                    x2 = sub.find("\"");
                    y2 = sub.find("\"", x2+1);
                    int lenSub2 = y2 - x2 - 1;
                    string substr2 = sub.substr(x2+1,lenSub2);
                    cout << "Please enter a " << substr2 << endl;
                    cin >> usersStuff[userInput];
                }
                // building new strings to make final output
                fullStory[i].replace(x, lenSub+1, usersStuff[userInput].c_str());
            }
        }while ( y  != -1);
    }

    // print out the story
    for (int c= 0; c < counter ; c++){
        cout << fullStory[c]<<endl;
    }
}
