#include <iostream>

using namespace std;
class Square
{
public:
    Square(); // default
    Square(int whole);
    int getSize();
    void setSize(int num);
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
