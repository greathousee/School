// Course: CSC 226 Introduction to Programming with C++
// Name: Your Name(Eddie Greathouse and Chloe Conn)
// Assignment #2: Using C++ Variables and Types
// This program allows a user to imput his/her height in feet and inches.
// The program then tells the user their height in centimeters, and their BMI depending whether they are fat or skinny.
// Eddie served as the driver, typing all the code, and contributing towards the developlentment of code on paper.
// Chloe served the role of Navigator, writing the code on paper and developing/edititing the code on computer.
#include <iostream>
using namespace std;
int main()
{
    double height_feet, height_inches, height_centimeters, BMI_kg_skinny, BMI_lb_skinny, BMI_kg_fatty, BMI_lb_fatty, height_meters;

cout <<"Type your height in feet (press enter) and inches (press enter)\n"; //The user enters his/her height.
cin >> height_feet;
cin >> height_inches;

height_centimeters = ((height_feet)*12 + height_inches)*2.54; //This line below defines the variables.
height_meters = (height_centimeters)*0.01;
BMI_kg_skinny = (height_meters)*(height_meters)*18.5;
BMI_lb_skinny = (BMI_kg_skinny)*2.20462;
BMI_kg_fatty = (height_meters)*(height_meters)*25.0;
BMI_lb_fatty = (BMI_kg_fatty)*2.20462;

cout << "You are " << height_centimeters << " centimeters tall.\n"; //program tells user their height in cm, and how much they probablly weigh.
cout << "If you are fat (meaning your BMI is 250) then you are " << BMI_lb_fatty << " pounds.\n";
cout << "If you are skinny (meaning your BMI is 185) then you are " << BMI_lb_skinny << " pounds.\n";

return 0;
}
