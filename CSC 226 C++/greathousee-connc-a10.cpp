 // Course: CSC 226 Introduction to Programming with C++
 // Name: Your Name
 // Assignment A10: <Put a brief sentence about your program here.>
 /*
 Purpose: <Put a more in-depth description of the program here.>
 */

 #include <iostream>
#include <fstream>

using namespace std;

void fix_html(ofstream& outputstream, ifstream& inputstream);


int main() {
char in_file_name[16], out_file_name[16];
 ofstream out_stream;
 ifstream in_stream;


cout << "This program will fix html webpages by updating the errors in the code." << endl;
cout << "It will fix the HMTL code and put it in another file." << endl;
cout << "Please enter the name of the file that the HTML should be updated on.(" << endl;
cin >> in_file_name;
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
HTML_fix(out_file_name, in_file_name);


 in_stream.close();
}

void fix_html(ofstream& outputstream, ifstream& inputstream){
char gChar = ' ';
int count = 1;

instream.open(out_stream, ios::app);
while (!inputstream.eof() ){
in_stream.get(gChar);
 if (gChar='<')
    {
        in_stream.get(gChar);
    if (gChar='m'){
        instream.get (gChar);
    if (gChar='e'){
        instream.get (gChar);
    if (gChar!='>'){
        instream.get (gChar);
    else (gChar='>')
        instream.putback('/');
        instream.put('>');
        count++;
        }}}}
 if (gChar='<')
    {
        in_stream.get(gChar);
    if (gChar='i'){
        instream.get (gChar);
    if (gChar='m'){
        instream.get (gChar);
    if (gChar!='>'){
        instream.get (gChar);
    else (gChar='>')
        instream.putback('/');
        instream.put('>');
        count++;
        }}}}
 if (gChar='<')
    {
        in_stream.get(gChar);
    if (gChar='b'){
        instream.get (gChar);
    if (gChar='r'){
        instream.get (gChar);
    if (gChar!='>'){
        instream.get (gChar);
    else (gChar='>')
        instream.putback('/');
        instream.put('>');
        count++;
        }}}}
 if (gChar='<')
    {
        in_stream.get(gChar);
    if (gChar='b'){
        instream.get (gChar);
    if (gChar='r'){
        instream.get (gChar);
    if (gChar!='>'){
        instream.get (gChar);
    else (gChar='>')
        instream.putback('/');
        instream.put('>');
        count++;
        }}}}}
return count;
}


