// Course: CSC 226 Introduction to Programming with C++
    // Name: Chad Peruggia
    // Assignment 11: <This program will take a broken HTML document and fix open tags.>
    /*
       Purpose: <This prorgam will allow a user to input a file name, and output file name.  Teh computer will then
                        copy the document, 1 character at a time, while doing so, it will find any unclosed meta tags, break tags
                        img tags and header tags.  It will put the corrected HTML in the file that you designate.>*/
#include<iostream>
#include <fstream>

using namespace std;

void read_n_fix(ifstream& inputstream, ofstream& outputstream); // function to read the input file and print the output file
bool check_char(ifstream& inputstream, ofstream& outputstream, int& hfix,int& mfix,int& ifix,int& bfix);
int main()
{
    ifstream input;
    ofstream output;
    char inputname[16], outputname[16]; // files' names can have at most 15 chars.
    cout << "Please enter the input file's name: ";
    cin >> inputname;
    cout << "Please enter the output file's name: ";
    cin >> outputname;
    // Condensed input and output file opening and checking.
    input.open(inputname);
    output.open(outputname);
    if (input.fail() || output.fail()){
        cout << "Input or output file opening fails.";
    }
    else read_n_fix(input, output); // Call the function.

    input.close(); // close file
    output.close(); // close file
    return 0;
}

bool check_char(ifstream& inputstream, ofstream& outputstream, int& hfix,int& mfix,int& ifix,int& bfix)
{
    char character,character2;
    inputstream.get(character);
    inputstream.get(character2);

   // counter to count each type of error that occurs !!!  Late implementation sorry :(
   if ((character=='i')&&(character2=='m'))
            ifix=ifix+1;
        else if ((character=='m')&&(character2=='e'))
            mfix++;
        else if ((character=='b')&&(character2=='r'))
            bfix++;
        else if ((character == 'h')&&(character2=='r'))
            hfix++;
    //if statement to check next two characters.
    if(((character=='i')&&(character2=='m')) || // next two is img tag
        ((character=='b')&&(character2=='r')) || // next two is br tag
       ((character=='m')&&(character2=='e')) || // next two is meta tag
       ((character=='h')&&(character2=='r')))// next two is HR tag
    {
        outputstream.put(character);
        outputstream.put(character2);
        return true;
    }
      else
      {
        outputstream.put(character);
        outputstream.put(character2);
        return false;
      }
}

void read_n_fix(ifstream& inputstream, ofstream& outputstream)
{
    int hfix(0), mfix(0), ifix(0), bfix(0);
    char character;
    inputstream.get(character);
    outputstream.put(character);
  while( !inputstream.eof())
  {
    inputstream.get(character);
        if (character=='<') //if the character is a < then its the start of a tag
            {
                outputstream.put(character); //print the leading <
                if ( check_char(inputstream,outputstream, hfix,mfix,ifix,bfix)==true) //call to boolean function to check inputs after teh <. If true, it needs to find the end of the tag to fix it
                        {
                            inputstream.get(character);//get character to compare to >
                            while(character !='>') // scanned to end of the tag
                                {
                                    outputstream.put(character);
                                    inputstream.get(character); //will print all characters up to the closing tag >
                                 }
                                 //the stream found a >
                                outputstream<<" /";//puts in a space
                                outputstream.put(character);//prints the > that was scanned in
                           }//end the if statment
            }//end the large if statement
        else  //the first character wasn't a <, it will just print the character on the file.
           {
               if ( !inputstream.eof()) // if its not the end of the file it will print, if it is, it will do nothing
                outputstream.put(character);
            }
    }
    cout<<"There were many fixes!"<<endl<<hfix<<"Header Tags"<<endl<<bfix<<"BR tags"<<endl<<ifix<<"IMG tags"<<endl<<mfix<<"Meta tags"<<endl;
  }
