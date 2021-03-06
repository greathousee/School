// Course: CSC 226 Introduction to Programming with C++
// Name: Eddie Greathouse
// Assignment A15: <This is a TicTacToe game that uses awesome graphics.>
/*
    Purpose: <This program implements classes with both private variables, and public functions. >
                It also stores the moves in a 3x3 matrix. If a move is called that is incorrect,
                the program ends. However, the program will tell you if the game ends in a draw,
                but i could not get it to declare if player 1 or player 2 wins. I attempted it,
                then commented out the portion which causes the program to fail.
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

     void mydisplay(int r, int c);
    // used to call CImg to display the board after a legal move has been made
     bool check_winner();
     //Used to check for a winner


  private:
     // private member variables
// r means unplayed, g means player green, b means player blue
     int numberplayed;		// the number of plays which have occurred (9 max)
     char winner;		// r means no winner yet, g means player green, b means player blue
     char player;		// g means active player is green, b means player is blue
     char gameboard[3][3];

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
    int x, y;

    while (game.get_numberOn() <= 8)
   {
   cout << "\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n"<<endl;

   cout << "Enter the column and row (separated by a space), remembering" <<endl;
   cout << "that each value must be between 0 and 2 inclusive: ";
   cin >> x >> y;
   game.make_move(x, y);

    game.mydisplay(x, y);
   }
   cout << endl;
   cout << "The game ended in a draw!\n" << endl;

   return 0;
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
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            gameboard[i][j] = 'r';
            cout << gameboard[i][j];
        }
        cout << endl;
    }
    cout << "***********\n" << endl;

    numberplayed = 0;
}
int Tictactoe::get_numberOn()
{
    return numberplayed;
}
void Tictactoe::make_move(int r, int c)
{
        if (legalmove(r,c) == true)
        {
            //if (check_winner() == true && player =='b')
            //{
            //    cout << "Player 2 wins!" << endl;
            //}
            //if (check_winner() == true && player == 'g')
            //{
            //    cout << "Player 1 wins!" << endl;
            //}
        }
            else
            {
            cout << "Not cool!\n" << endl;
            exit(1);
            }
}
bool Tictactoe::legalmove(int r, int c)
{
    if (r > -1 && r < 3 && c > -1 && c < 3 && gameboard[r][c] != 'g' && gameboard[r][c] != 'b')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tictactoe::check_winner()
{
    if ((gameboard[0][0]=='b') && (gameboard[1][1]=='b') && (gameboard[2][2]=='b'))
    {
        winner='b';
        return true;
    }
    if ((gameboard[2][0]=='b') && (gameboard[0][2]=='b') && (gameboard[1][1]=='b'))
        {
            winner='b';
            return true;
        }
    if ((gameboard[0][0]=='b') && (gameboard[0][1]=='b') && (gameboard[0][2]=='b'))
    {
        winner='b';
        return true;
    }
    if ((gameboard[1][0]='b') && (gameboard[1][1]='b') && (gameboard[1][2]='b'))
    {
        winner='b';
        return true;
    }
    if ((gameboard[2][0]='b') && (gameboard[2][1]='b') && (gameboard[2][2]='b'))
    {
        winner='b';
        return true;
    }
    if ((gameboard[0][0]='b') && (gameboard[1][0]='b') && (gameboard[2][0]='b'))
    {
        winner='b';
        return true;
    }
    if ((gameboard[0][1]='b') && (gameboard[1][1]='b') && (gameboard[2][1]='b'))
    {
        winner='b';
        return true;
    }
    if ((gameboard[0][2]='b') && (gameboard[1][2]='b') && (gameboard[2][2]='b'))
    {
        winner='b';
        return true;
    }
     if ((gameboard[0][0]='g') && (gameboard[0][1]='g') && (gameboard[0][2]='g'))
    {
        winner='g';
        return true;
    }
    if ((gameboard[1][0]='g') && (gameboard[1][1]='g') && (gameboard[1][2]='g'))
    {
        winner='g';
        return true;
    }
    if ((gameboard[2][0]='g') && (gameboard[2][1]='g') && (gameboard[2][2]='g'))
    {
        winner='g';
        return true;
    }
    if ((gameboard[0][0]='g') && (gameboard[1][0]='g') && (gameboard[2][0]='g'))
    {
        winner='g';
        return true;
    }
    if ((gameboard[0][1]='g') && (gameboard[1][1]='g') && (gameboard[2][1]='g'))
    {
        winner='g';
        return true;
    }
    if ((gameboard[0][2]='g') && (gameboard[1][2]='g') && (gameboard[2][2]='g'))
    {
        winner='g';
        return true;
    }
        if ((gameboard[0][0]='g') && (gameboard[1][1]='g') && (gameboard[2][2]='g'))
        {
            winner='g';
            return true;
        }
        if ((gameboard[2][0]='g') && (gameboard[1][1]='g') && (gameboard[0][2]='g'))
        {
            winner='g';
            return true;
        }
 return false;
}

void Tictactoe::mydisplay(int r, int c)
{
    if (player == 'b')
        {
            gameboard[r][c] = 'b';
            player = 'g';
            numberplayed++;
        }
                else
            {
                gameboard[r][c] = 'g';
                player = 'b';
                numberplayed++;
            }
    for (int j=0; j<3; j++)
    {
        for (int i=0; i<3; i++)
        {
            cout << gameboard[i][j];
        }
        cout << endl;
    }
    cout << "***********\n" << endl;


   // Use the CImg constructor to define a color image called myboard
   // Note that z=1 means our board is 2D and c=3 gives us 3 color channels RGB
   CImg<unsigned int>myboard(3,3,1,3);// x, y, z, c

   //These loops manipuate the image at the level of the pixels
   for (int p = 0; p<3; p++)
   {
      for (int q = 0; q<3; q++)
      {
        if (gameboard[q][p]=='r'){
         myboard(q,p,0)=255; // c=0 is the Red channel
         myboard(q,p,1)=0; // c=1 is the Green channel
         myboard(q,p,2)=0; //c=2 is the Blue Channel
        }else if (gameboard[q][p]=='g'){
         myboard(q,p,0)=0; // c=0 is the Red channel
         myboard(q,p,1)=255; // c=1 is the Green channel
         myboard(q,p,2)=0; //c=2 is the Blue Channel
         }else{
         myboard(q,p,0)=0; // c=0 is the Red channel
         myboard(q,p,1)=0; // c=1 is the Green channel
         myboard(q,p,2)=255; //c=2 is the Blue Channel
      }
   }


   }
   myboard.display("Board");
}

