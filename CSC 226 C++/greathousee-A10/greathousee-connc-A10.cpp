 // Course: CSC 226 Introduction to Programming with C++
 // Name: Your Name
 // Assignment A10: <Put a brief sentence about your program here.>
 /*
 Purpose: <Put a more in-depth description of the program here.>
 */

 #include <iostream>
#include <fstream>

using namespace std;

int fix_html(ofstream& outputstream, ifstream& inputstream);


int main() {
    char in_file_name[16], out_file_name[16];
    ofstream out_stream;
    ifstream in_stream;
    int num_errors(0);

    cout << "This program will fix html webpages by updating the errors in the code." << endl;
    cout << "It will fix the HMTL code and put it in another file." << endl;
    cout << "Please enter the name of the file that the HTML should be updated on.(" << endl;
    cin>> in_file_name;
    cout << "Please enter the name of the file to put the updated code into." << endl;
    cin >> out_file_name;

    in_stream.open (in_file_name);
    if (in_stream.fail())
    {
        cout << "\nInput file opening failed.\n";
    }
    out_stream.open (out_file_name);
    if (out_stream.fail())
    {
        cout << "\nInput file opening failed.\n";
    }

    cout<< "The number of errors in your file were"  << endl;
    num_errors=fix_html(out_stream, in_stream);
    cout << num_errors<<endl;

    in_stream.close();
    cout << "counting all spaces, the trailing line-feed, and the EOF.\n" << endl;
}
int do_work (ofstream& outputstream, ifstream& inputstream)
    char temp
    while ( !inf.eof()){
        inputstream.get (temp);
        if ( temp == '<'){
            outputstream.put(temp);
            fix_html (ofstream& outputstream, ifstream& inputstream, &num_errors)
        }
        else{
            outputstream.put(temp);
        }
    }
int fix_html(ofstream& outputstream, ifstream& inputstream, num_errors&){
    char char1, char2;
    int num_errors = 0;
    while (!inputstream.eof() ){
        inputstream.get(char1);
        inputstream.get(char2);
        if ((char1=='m' && char2 == 'e') ||(char1 == 'i' && char2 == 'm' ) ||
            (char1 == 'h' && char2 == 'r') || (char1 == 'b' && char2 == 'r'){
            outputstream.put (char1)
            outputsream.put (char2)
            char x;
            while (x != '>'){
                inputstream.get (x)
                outputstream.put (x)
                }
            outputstream.put ('/')
            outputsteam.put ('>')
            }


        }
}




