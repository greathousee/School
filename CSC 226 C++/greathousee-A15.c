// Course: CSC 226 Introduction to Programming with C++
// Name: Your Name(s)
// Assignment A15: <Put a brief sentence about your program here.>
/*
    Purpose: <Put a more in-depth description of the program here.>
*/

#include "CImg.h"
#include <iostream>
  using namespace cimg_library;
  using namespace std;
class Tictactoe {
  public:

     Tictactoe();
     // constructor which sets all member variables appropriately

     int get_numberOn();
     // public accessor member function which returns numberplayed

     void make_move(int r, int c);
    // used when a user chooses to play at row r and column c

     void display();
    // used to call CImg to display the board after a legal move has been made
     void winner();
     //Used to check for a winner


  private:
     // private member variables
     char gameboard[3][3];	// r means unplayed, g means player green, b means player blue
     int numberplayed;		// the number of plays which have occurred (9 max)
     char winner;		// r means no winner yet, g means player green, b means player blue
     char player;		// g means active player is green, b means player is blue

     // private member functions

     bool legalmove(int r, int c);
     // when called with row r and column c
     // if  0 <= r <= 2 and 0<= c <=2 and the position if not already occupied by r or g,
     // this private function returns true and otherwise false

   // inlcude add any other needed private member variables and functions

};	// Note the need for a semicolon
void displaydirections();

int main ()
{
    Tictactoe game;
   const int boardsize=3;

   int x, y, r, g, b;

   // Use the CImg constructor to define a color image called myboard
   // Note that z=1 means our board is 2D and c=3 gives us 3 color channels RGB
   CImg<unsigned int>myboard(boardsize,boardsize,1,3);// x, y, z, c

   //These loops manipuate the image at the level of the pixels
   for (y = 0; y<boardsize; y++)
   {
      for (x = 0; x<boardsize; x++)
      {
         myboard(x,y,0)=255; // c=0 is the Red channel
         myboard(x,y,1)=0; // c=1 is the Green channel
         myboard(x,y,2)=0; //c=2 is the Blue Channel

      }
   }

   displaydirections();

   myboard.display("Board");
   while (game.get_numberOn() <= 8)
   {
   cout << "\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n"<<endl;

   cout << "Enter the column and row (separated by a space), remembering" <<endl;
   cout << "that each value must be between 0 and " << boardsize-1 << " inclusive: ";
   cin >> x >> y;
   game.make_move(x, y);
   if (game.get_numberOn() % 2 ==0)
   {
       r =0;
       g =255;
       b =0;
   }
    else
    {
        r =0;
        g =0;
        b =255;
    }

   myboard(x,y,0)=r; // set the Red channel to desired value
   myboard(x,y,1)=g; // c=1 is the Green channel
   myboard(x,y,2)=b; //c=2 is the Blue Channel

   displaydirections();
   myboard.display("Board");
   }
   game.winner();

}

 void displaydirections()
 /* displays directions allowing interaction with both console and image */
 {
   cout << "\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
   cout << "CLOSE YOUR BOARD TO CONTINUE";
   cout << "\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
 }
Tictactoe::Tictactoe()
{
    int n, r, g, i, j;
    numberplayed = 0;
    winner = r;
    player = g;
    for (i=0; i>3; i++)
    {
        for (j=0; j>3; j++)
        {
            gameboard[i][j] = 0;
        }
    }
}
int Tictactoe::get_numberOn()
{
    return numberplayed;
}
void Tictactoe::make_move(int r, int c)
{
    int g,b;
if (player = g)
{
    gameboard[r][c] = g;
    player = b;
    numberplayed++;
}
    else
    {
        gameboard[r][c] = b;
        player = g;
        numberplayed++;
    }
}
bool Tictactoe::legalmove(int r, int c)
{
    if (r >= 0 && r <= 2 && c >=0 && c <=2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Tictactoe::winner()
{
int i(0), j(0);
    for (i=0; i<= 2; i++)
    {
        for(j=0; j<= 2; j++)
        {
            if (gameboard[i][j]=b)
            {
            cout << "Player 1 wins!" << endl;
            }
            if (gameboard[i][j]=g)
            {
            cout << "Player 2 wins!" << endl;
            }
        }
    }
}
