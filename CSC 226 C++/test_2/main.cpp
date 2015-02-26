#include <iostream>
#include <fstream>
#include <cstdlib>
#include  <iomanip>

using namespace std;

int main()
{
   cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout << "$" << setprecision(2) << 10.3 << endl;
cout << "$" << 20.5 << endl;


    return 0;
}
