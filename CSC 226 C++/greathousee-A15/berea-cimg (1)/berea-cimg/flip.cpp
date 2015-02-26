/*  flip.cpp

    Working pixelwise, this program reflects an image.
    Created as CImg tutorial on bmp pixelwise image manipulation
    for use in CSC 226 at Berea College by Dr. Jan Pearce.

    For use in Windows applications using the IDE Code::Blocks
    Under Project->Build Options->Linker Settings->Link Libraries: add gdi32
*/

#include "CImg.h"
#include <iostream>
  using namespace cimg_library;
  using namespace std;

 void displaydirections();

int main () {
   int newx, newy, maxy, z, c;

   cout << "We read in an image using the CImg constructor. "<<endl;
   CImg<unsigned int> img("berea.bmp");//white, black, Berea blue surrounded by red
   displaydirections();

   //Note that the display member function is very powerful!
   //It allows pixel information to show as well as zooming and resizing.
   //However, it has a color "normalization" feature turned on,
   //which will change the color of certain images or even set them to all black.
   //ask me if you want details on why and/or how to turn this off.
   //otherwise just be sure use red, green, or blue for your intial boards.

   img.display("Original");

   newx=img.width(); // width is typically denoted by x
   newy=img.height(); // height is typically denoted y

   maxy=newy-1; // This helps us avoid an off-by one error working with the pixels

   z=img.depth(); // For 2D images depth=1.

   c=img.spectrum(); // Use 3 for RGB images.

   cout<<"The image we read has the following structure."<<endl;
   cout<<"x: "<<newx<<" y: "<<newy<< " z: "<< z <<" c: "<<c <<"\n"<<endl;

   cout<<"We will flip this image upside down!"<<endl;
   cout<<"What follows are the pixel colors of the inverted image\n"<<endl;

   // Use the CImg constructor to define a new color image called newimg
   CImg<unsigned int>newimg(newx,newy,z,c);// x, y, z, c

   //These loops access the image at the level of the pixels
   for (int y = 0; y<newy; y++)
   {
      for (int x = 0; x<newx; x++)
      {
         newimg(x,y,0)=img(x,maxy-y,0); // 0 is the Red channel
         newimg(x,y,1)=img(x,maxy-y,1); // 1 is the Green channel
         newimg(x,y,2)=img(x,maxy-y,2); // 2 is the Blue Channel
         cout <<"["<<newimg(x,y,0)<<","<<newimg(x,y,1)<<","<<newimg(x,y,2)<< "] ";
         //Prints the intensities of the color channels
      }
      cout <<endl; // improves readability
   }

   displaydirections();

   (img,newimg).display("Original and New images"); //displays original and new

    newimg.save("bereanew.bmp"); //saves new image

    return 0;
}
 void displaydirections()
 /* displays directions allowing interaction with both console and image */
 {
   cout << "\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
   cout << "CLOSE YOUR IMAGE TO CONTINUE";
   cout << "\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
 }
