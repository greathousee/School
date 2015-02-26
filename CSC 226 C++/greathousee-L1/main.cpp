#include <iostream>

using namespace std;

int main()
{
    int sticks;
    cout << "Welcome to the game of Nim. You will compete\n";
    cout << "against the computer to be the last person to take\n";
    cout << "all the sticks.Please enter the number of sticks\n";
    cout << "you wish to start (must be greather than 9)." << endl;
    cin >> sticks;
    while (sticks < 9)
    {
        cout << sticks << " is not less than 9, please try again." << endl;
        cout << "Please enter the number of sticks\n";
        cout << "you wish to start (must be greater than 9)." << endl;
        cin >> sticks;

    }
    double sticks_taken;
    cout << "Please enter the number of sticks you wish to\n";
    cout << "take (must be less than 5, but greater than 0)." << endl;
    cin >> sticks_taken;
    while (sticks_taken > 5)
    {
        cout << sticks_taken << " is not between 1 and 5." << endl;
        cout << "Please enter the number of sticks you wish to take." << endl;
        cin >> sticks_taken;
    }
    while (sticks > 4)
    {
     sticks = sticks - sticks_taken - 4;
     cout << "The computer takes 4 sticks. " << sticks << " sticks are remaining. Your turn." << endl;
     cin >> sticks_taken;
    }
    sticks = sticks - sticks_taken;
    if (sticks == 4)
    {
        cout << "computer takes 4 sticks. You lose!" << endl;
    }


    if (sticks == 3)
{

        cout << "computer takes 3 sticks. You lose!" << endl;
}
    if (sticks == 2)
{


        cout << "computer takes 2 sticks. You lose!" << endl;
}
    if (sticks == 1)
{


        cout << "computer takes 1 stick. You lose!" << endl;
}
if (sticks == 0)
{
    cout << "You win!" << endl;
}



    return 0;
}
