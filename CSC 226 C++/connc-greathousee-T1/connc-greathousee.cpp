/*   Course: CSC 226 Introduction to Programming with C++
     Name: Eddie Greathouse and Chloe Conn
     Assignment A1: Finding an Average
     Description: This program teaches us how to use the division operation. This program assumes there are 3 peas per pod. */

#include <iostream>
using namespace std; // introduces namespace std for cout and cin

int main() {
    double number_of_peas, total_pods;

    cout << "Press return after entering a number.\n";
    cout << "Enter the number of peas:\n";
    cin >> number_of_peas;

    total_pods = number_of_peas / 3;

    cout << "If you have ";
    cout << number_of_peas;
    cout << " pea pods\n";

    cout << " peas in each pod, then\n";
    cout << "you have ";
    cout << number_of_peas;
    cout << " peas in all the pods.\n";

    return 0;
}
