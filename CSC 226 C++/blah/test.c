// File Name: formatdemo.cpp
// This program will take the number of candy bars in a package and the cost of each bar
// and output the cost of the package, showing formatting differences for doubles

#include <isotream>
using namespace std;


int main() {
    int number_of_bars;
    double one_cost, package_cost;

    cout << "Enter the number of candy bars in a package: ";
    cin >> number_of_bars;
    cout << "Enter the cost of one candy bar: ";
    cin >> one_cost;

    package_cost = number_of_bars * one_cost;

    cout << "\n" << "UNFORMATTED: The total cost of the package is : $" << package_cost << endl;

    // Set the format of the output to 2-decimal place precision:
    cout.setf(ios::fixed); //this sets the format to fixed
    cout.setf(ios::showpoint); //this forces the decimal to show
    cout.precision(2); //this forces exactly 2 digits after the decimal

//These lines changed the format of subsequent output

    cout << "FORMATTED: The total cost of the package is : $" << package_cost << "\n" <<endl;

    system("PAUSE");
    return 0;
}
