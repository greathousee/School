
// Course: CSC 226 Introduction to Programming with C++
// Name: Eddie Greathouse
// Assignment A13: <Put a brief sentence about your program here.>
/*
    Answer to questions: <a. The program uses two classes because one class ensures random numbers while
    the other class only focuses on the dice. b. Having 2 classes is better than having one class because debugging
    the program is easier if the problem can be linked to either the RandGen or the Dice class.>
    Purpose: <Put a more in-depth description of the program here.>
*/
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

//---------------------------------------------------------------------
// Program illustrating use of RandGen and Dice classes
//---------------------------------------------------------------------
class RandGen
{
  public:
    RandGen();                          // set seed for all instances
    int RandInt(int max = RAND_MAX);     // returns int in [0..max)
    int RandInt(int low, int max);      // returns int in [low..max]
    double RandReal();                  // returns double in [0..1)
    double RandReal(double low, double max); // range [low..max]

    static void SetSeed(int seed);      // static (per class) seed set
private:
    static int ourInitialized;          // for 'per-class' initialization
};


class Dice
{
  public:
  	Dice(); 				// default constructor assumes a 6-sided die.
    Dice(int sides);        // constructor for any size dice
    int Roll();             // return the random roll of the die
    int NumSides() const;   // how many sides this die has
    int NumRolls() const;   // # times this die rolled

  private:
    int myRollCount;        // # times die rolled
    int mySides;            // # sides on die
    int less_error;         //sets itself to be six-sided when user specifies a number less than 2
};
//---------------------------------------------------------------------
// main begins here
//---------------------------------------------------------------------

int main()
{   int Numsides, Numdice, NumRolls;
    cout << "Enter the number of sides on the die.\n" << endl;
    cin >> Numsides;
    cout << "How many dice would you like to use? 1 or 2?\n" << endl;
    cin >> Numdice;
    cout << "Please enter the number of rolls.\n" << endl;
    cin >> NumRolls;
    const int start=1;
    const int stop=10;

    int loopcount =1;

    Dice cube(Numsides);              // make a six-sided die

    cube.Roll();  //For debugging purposes, the same number will be generated by EVERY SINGLE first roll.
    //So, unless you want the same number for each first roll, we must throw away the first roll.
    //which we do by ignoring the first roll and not printing it out.


    cout << "This loop displays "<<stop-start+1 <<" rolls of a 6-sided dice:\n" << endl;
    for (loopcount=start; loopcount<=stop; loopcount++)
        {
             cout << "Roll " <<loopcount<< " is " << cube.Roll() << "."<< endl;
        }
    cout << "\nRolled the six-sided dice " << cube.NumRolls()-1 << " times.\n" << endl;

    return 0;
}

//---------------------------------------------------------------------
// RandGen class functions begin here
//---------------------------------------------------------------------

int RandGen::ourInitialized = 0;

void RandGen::SetSeed(int seed)
// postcondition: system srand() used to initialize seed
//                once per program (This is a static function)
{
    if (0 == ourInitialized)
    {
    ourInitialized = 1;   // only call srand once
	srand(seed);          // randomize
    }
}


RandGen::RandGen()
// postcondition: system srand() used to initialize seed
//                once per program
{
    if (0 == ourInitialized)
    {
    	ourInitialized = 1;          // only call srand once
        srand(unsigned(time(0)));    // randomize
    }
}

int RandGen::RandInt(int max)
// precondition: max > 0
// postcondition: returns int in [0..max)
{
    return int(RandReal() * max);
}

int RandGen::RandInt(int low, int max)
// precondition: low <= max
// postcondition: returns int in [low..max]
{
    return low + RandInt(max-low+1);
}

double RandGen::RandReal()
// postcondition: returns double in [0..1)
{
    return rand() / (double(RAND_MAX) + 1);
}

double RandGen::RandReal(double low, double high)
{
    double width = fabs(high-low);
    double thelow = low < high ? low : high;
    return RandReal()*width + thelow;
}

//---------------------------------------------------------------------
// Dice class functions begin here
//---------------------------------------------------------------------

Dice::Dice()//Default is to assume a six sided die.
// postcondition: all private fields initialized
{

    myRollCount = 0;
    mySides = 6;
}


Dice::Dice(int sides)
// postcondition: all private fields initialized
{
    myRollCount = 0;
    mySides = sides;
}

int Dice::Roll()
// postcondition: number of rolls updated
//                random 'die' roll returned
{
    RandGen gen;    // random number generator

    myRollCount= myRollCount + 1;         // update # of times die rolled
    return gen.RandInt(1,mySides);        // in range [1..mySides]
}

int Dice::NumSides() const
// postcondition: return # of sides of die
{
    return mySides;
}

int Dice::NumRolls() const
// postcondition: return # of times die has been rolled
{
    return myRollCount;
}

