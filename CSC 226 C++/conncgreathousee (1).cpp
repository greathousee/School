
// Course: CSC 226 Introduction to Programming with C++
// Name: Chloe Conn Eddie Greathouse
// Assignment A7: <This game takes a starting amount of money from the user and makes a bet using some or all of that money
//and the user guess which cup the rare candy is under. If the user guesses the correct cup then they win the bet money.>
/*
    Purpose: <This game takes a starting amount of money from the user and makes a bet using some or all of that money
//and the user guess which cup the rare candy is under. If the user guesses the correct cup then they win the bet money.>
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

void shuffle(bool& cup1, bool& cup2, bool& cup3);

void gamble(int& totalmoney, int betmoney, int guess);
// gamble that takes as parameters the total amount of money you have, the amount of your bet, and your guess.

using namespace std;

int main(){

    int  betmoney, totalmoney, guess, count;
// This sections welcomes the user and asks the user for the amount to begin with.
    cout << "Welcome to the shell game!\n." << endl;
     cout << "In the shell game there are three red solo cups, \n" << endl;
     cout << "and under one of them will be a rare candy.\n" << endl;
     cout << "Please enter the amount of money you wish to start.\n" << endl;
    cin >> totalmoney;
    //This section repeats, asking the user how they want to bet and which cup they think the rare candy is under.
for (count == 10; count > 0; count--)
{
    cout << "Please enter the amount of money you would like to bet." << endl;
    cin >> betmoney;

    cout << "Which cup will the rare candy be under? Enter 1, 2, or 3." << endl;
    cin >> guess;

    gamble (totalmoney, betmoney, guess);
    //This function contains the game
}

//The loop above repeats until either the total amount of money is zero or the user played the game 10 times.


return 0;
}

void gamble(int& currentmoney, int usersbet , int userscup)
{
 while ((currentmoney < 0) || (usersbet > currentmoney)) //If the user bets more than he or she has, then the program will ask the user to enter a different amount.
    {
        cout << "You cannot bet " << usersbet << "." << endl;
        cout << "Please enter a different amount." << endl;
        cin >> usersbet;
    }
bool cup1, cup2, cup3;
// This function changes and gives the cups a value
shuffle (cup1, cup2, cup3);
if (cup1>cup2 && cup1>cup3 && 1==userscup) //The following if's statements determines whether the winner wins or loses based on the shuffle function.
    {

    currentmoney=usersbet + currentmoney;
    cout <<"Congratulations\n." << endl;
    cout <<"You bet " << usersbet << "and you won./n" << endl;
    cout <<" You now have " << currentmoney << ".\n" << endl;
}



if (cup2>cup1 && cup2>cup3 && 2==userscup)
    {

    currentmoney=usersbet + currentmoney;
    cout <<"Congratulations\n." << endl;
    cout <<"You bet " << usersbet << "and you won.\n" << endl;
    cout <<" You now have " << currentmoney << ".\n" << endl;
}


if (cup3>cup1 && cup3>cup2 && 3==userscup){

    currentmoney=usersbet + currentmoney;
    cout <<"Congratulations!\n" << endl;
    cout <<"You bet " << usersbet << " and you won.\n" << endl;
    cout <<" You now have " << currentmoney << ".\n" << endl;
}

else {
        currentmoney=currentmoney-usersbet;
    cout <<"Sorry!\n" << endl;
    cout <<"You bet " << usersbet << " and you lost.\n" << endl;
    cout <<" You now have " << currentmoney << ".\n" << endl;

}
}



//This function checks to see if you have enough money to make the bet. If not, then it gives a message stating this fact and does nothing else.
//It also checks to make sure that the bet is greater than 0 and, again, it displays a message stating this problem and does nothing else.
//If there is enough money, it calls the shuffle(...) function and then sees if guess is correct.
//If the user guessed correctly, the bet amount is added to the total money. Otherwise, the user loses that bet.




void shuffle(bool& cup1, bool& cup2, bool& cup3)
{
    cup1 = static_cast<double>(rand())/((RAND_MAX) + 1);
    cup2 = static_cast<double>(rand())/((RAND_MAX) + 1);
    cup3 = static_cast<double>(rand())/((RAND_MAX) + 1);

    return;
}
