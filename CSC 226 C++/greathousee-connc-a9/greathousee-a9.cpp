// Course: CSC 226 Introduction to Programming with C++
// Name: Eddie Greathouse
// Assignment A9: <This program is designed to intake a file with numbers and output the max, min, and average on the screen and in a file.>

#include <iostream> // for cout
#include <fstream>  // for I/O member functions
#include <cstdlib>  // for the exit function
#include <iomanip>  // for the setw function
#include <float.h>  // This allows the fuction to calculate infinity
using namespace std;
void calculate(ifstream& numbers, ofstream& results);

int main() {
   ifstream fin;
   ofstream fout;
   char numbers[16], results[16];
   double max(), min();

cout << "This program is designed to find the maximum, minimum, and average of any set of numbers. \n" << endl;
cout << "Please enter the filename that has the numbers inside. \n" << endl;
cin >> numbers;
cout << "Now please enter the file name to be saved. \n" << endl;
cin >> results;
   fin.open(numbers);
   if( fin.fail() ) {	// oops the file did not exist for reading?
	cout << "Input file opening failed." << endl;
	exit(1);
   }

   fout.open("results.txt");
   if( fout.fail() ) {	// oops the output file open failed!
	cout << "Output file opening failed.\n";
	exit(1);
   }
   calculate(fin, fout);

   fin.close( );
   fout.close( );
   cout << "End of program." << endl;
   return 0;
}
// Uses iostreams, streams to the screen, and iomanip:
void calculate(ifstream& numbers, ofstream& results)
{
    double next=0, maxn (-DBL_MAX), minimu(DBL_MAX), average;
   // set the format for the neater output file.
   results.setf(ios::fixed);
   results.setf(ios::showpoint);
   results.setf(ios::showpos);
   results.precision(5);
   // set the format for the output to the screen too.
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.setf(ios::showpos);
   cout.precision(5);
   int counter(0);
   cout << "The numbers in the input file are: \n" << endl;
   while(! numbers.eof() )
        { // while there is still stuff to read
        counter++;
        numbers >> next;
        cout << next << endl;
        maxn = max(maxn, next);
        minimu = min(minimu, next);
        average += next;
        }
        average = average/counter;
        cout << "The Maxum of the numbers is" << maxn << endl;
        cout << "The Minimum of the numbers is" << minimu << endl;
        cout << "The average of the numbers is" << average << endl;

        results << "The Maxum of the numbers is" << maxn << endl;
        results << "The Minimum of the numbers is" << minimu << endl;
        results << "The average of the numbers is" << average << endl;



   }

