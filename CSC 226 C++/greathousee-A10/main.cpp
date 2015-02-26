// Course: CSC 226 Introduction to Programming with C++
 // Name: Your Name
 // Assignment A10: <Put a brief sentence about your program here.>
 /*
 Purpose: <Put a more in-depth description of the program here.>
 */
#include <iostream>
#include <fstream>
#include <cstdlib>

void meta_check (ifstream& in_stream, ofstream& out_stream);
void img_check (ifstream& in, ofstream& out);
void br_check (ifstream& in, ofstream& out);
void hr_check (ifstream& in, ofstream& out);

using namespace std;

int main()
{
    ifstream in_stream;
    ofstream out_stream;
    char input_file_name[16], ouput_file_name [16];

    cout << "Hello. This program is designed to debug certain problems in HTML's.\n " << endl;
    cout << "Please enter the input file name (must be less than 15 characters). \n" << endl;
    cin >> input_file_name;
    in_stream.open(input_file_name);
    if( in_stream.fail() )
        {
cout << "\nInput file opening failed.\n";
 exit(1);
 }\n
 cout << "Please enter the name of the output file (must be less than 15 characters).\n" << endl;
 cin >> output_file_name;
 out_stream.open(output_file_name)
    return 0;
}
char meta_check(ifstream& in, ofstream& out)
{
    char ch = 0;
    while ( !inputstream.eof() )
        {
        in_stream.get(ch);
        if ( ch = m)
        {
            cout << ch;
            in_stream.get(ch);
        }
    if ( ch = e)
    {
        cout << ch;
        out_stream.put ( '/' );
    }
    }
}

