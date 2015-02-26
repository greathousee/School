// Course: CSC 226 Introduction to Programming with C++
// Name: Eddie Greathuse
// Test T2: Using a class to create a box.
/*
    Purpose: The purpose of this assignment is to display our knowledge in the different mechanics of C++ classes.
    Constructors, manipulaters, overloaded functions, publics and private member functions are all used within this program.
*/
#include <iostream>

using namespace std;
class Square
{
public:
    Square(); // default constructor
    //Preconditions: the only precondition here is the the program is runned.
    //Postcondition: A new class will be constructed and ready for use
    Square(int whole); // second constructor
    //precondition: a chosen size for the box is given
    //postcondition: creates a box and displays with the size given as a parameter
    int getSize();
    //precondition: needs to know the size of the box.
    //postcondition: returns the size of the box.
    void setSize(int num);
    //precondition: checks to see if size is appropriate
    //if size is appropriate, it will say so.
    void display(); // displays Square to the screen
    /*draw a square of a desired integer size on the screen. For example, calling square(4) should draw
    ****
    ****
    ****
    ****
    */
private:
    int area;
    bool checksize(); //assures 0<area<75 so that squares will render correctly.
    //called by the non default constructor and setSize.
};

int main()
{
    int box;
    Square users_square;
    cout << "Please enter the size of the box." << endl;
    cin >> box;
    users_square.setSize(box);
    users_square.getSize();
    users_square.display();
    return 0;
}
Square::Square()
{

}
Square::Square(int whole)
{
    if (checksize()==true)
    {
        cout << "True";
        return;
    }
    else
    cout << "false";
        return;
}
int Square::getSize()
{
    return area;
}
void Square::setSize(int num)
{
    area = num;
    if (checksize()==true)
    {
        cout << "The size is acceptable" << endl;
        return;
    }
    else
    {
        cout << "The size is outside the limits of the square." << endl;
        return;
    }
}

void Square::display()
{
    int i(0), j(0);
    while (i<area)
    {
        while (j<area)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        j=0;
        i++;
    }
}
bool Square::checksize()
{
    if (area > 0 && area < 75)
    {
        return true;
    }
    else
        return false;
}
