#include <iostream>
#include <cmath>

using namespace std;
struct point {
double x, y;
};
void printPoint(point p);
point get_point ();
double point_distance( point p1, point p2);

int main()
{

    point p1, p2;
    cout << "Hello! This program is designed to take in two seperate points,\n" << endl;
    cout << " and calculate the distance between them.\n" << endl;
    cout << "Please enter the first point.\n" << endl;
    p1 = get_point();
    cout << "Please enter the second point.\n" << endl;
    p2 = get_point();
    printPoint(p1);
    printPoint(p2);

    return 0;
}
void printPoint (point p)
{
    cout << "(" << p.x << "," << p.y << ")";
}
point get_point ()
{
    point p;
    cout << "Please enter an x coordinate.\n" << endl;
    cin >> p.x;
    cout << "Please enter a y coordinate.\n" << endl;
    cin >> p.y;
    return p;
}
double point_distance (point p1, point p2)
{
    double distance;

}
