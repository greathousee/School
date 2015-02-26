//Example program to generate pseudo-random probablities

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    srand((unsigned)time(0));
    double random_num;
    for(int index=0; index<25; index++)
    {
        random_num=static_cast<double>(rand())/(static_cast<double>(RAND_MAX) + 1); //will give a random number in [0, 1)
        cout << random_num << endl;
    }

    return 0;
}
