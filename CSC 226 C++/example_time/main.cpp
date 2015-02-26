#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <iomanip>


using namespace std;

int main()
{
    clock_t t, s, passed, left;
    time(&t);
    system("pause");
    time(&s);
    passed = difftime(s, t);
    while (passed <= 30)
    {
        time(&s);
        passed = difftime(s, t);
        left = 30-passed;
        cout <<"\t" <<"\t" <<"\t"<<"\t"<< left << " seconds remaining" << endl;
        cout << "| " << 'a' << " | " << 'b' << " | " << 'c' << " | " << endl;
        cout << "| " << 'd' << " | " << 'e' << " | " << 'f' << " | " << "\t" << "Words: 0"<< endl;
        cout << "| " << 'g' << " | " << 'h' << " | " << 'i' << " | " << endl;
        cout << "Press Enter" << endl;
        cin.get (char* s, streamsize n);
    }
    return 0;
}
