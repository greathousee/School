/*  helloberea.cpp

    Created as CImg tutorial on bmp image generation
    for use in CSC 226 at Berea College by Dr. Jan Pearce
    Creates helloberea.bmp

    For use in Windows applications using the IDE Code::Blocks
    Under Project->Build Options->Linker Settings->Link Libraries: add gdi32
*/

#include "CImg.h" // Include the CImg library.
#include <iostream>
using namespace cimg_library; //using this namespace will save typing class names
using namespace std;

void displaydirections();

int main() {

//Cimg uses arrays for storing colors in RGB (Red, Green, Blue) format
   unsigned char blue[] = {0, 0, 255}; // Defines blue color array
   unsigned char white[] = {255, 255, 255}; // Defines white color array

// The following uses the CImg library to create a new object called img.
// It is basically a very souped-up array using a templated class needing the <>s.

   // Use a constructor to define a 200x200 color image with 3 = RGB colors available.
   CImg<unsigned char> img(200, 200, 1, 3); // x, y, z, c

//Next we will see member functions used.

   // fill parameters are the colors in RGB channels.
   img.fill(255);

   //upper-left x, upper-left y, lower-right x, lower-right y, color, opacity (between 0 & 1)
   img.draw_rectangle(25, 25, 175, 175, blue,0.3);
   img.draw_rectangle(50, 50, 150, 150, blue,0.8);

   // Draw blue "Hello Berea!" beginning at the given coordinates.
   img.draw_text(70, 95, "Hello Berea!", white);

   displaydirections();

   //Note that the display member function is very powerful!
   //It allows pixel information to show as well as zooming and resizing.
   //However, it has a color "normalization" feature turned on,
   //which will change the color of certain images or even set them to all black.
   //ask me if you want details on why and/or how to turn this off.
   //otherwise just be sure use red, green, or blue for your intial images.

   // Display the image in a display window. Parameter is window title.
   // See above warning about this function.
   img.display("Berea uses CImg");

   //Note that this function saves in a bmp format by default regardless of extension given.
   img.save("helloberea.bmp");

return 0;
}

 void displaydirections()
 /* displays directions allowing interaction with both console and image */
 {
   cout << "\n\n                                  -_-_-_-_-_-_-_-_-_-_-_-_-_-_";
   cout << "\n\n                                  CLOSE YOUR IMAGE TO CONTINUE";
   cout << "\n\n                                  -_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
 }
