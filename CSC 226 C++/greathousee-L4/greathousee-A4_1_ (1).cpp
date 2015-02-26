// Course: CSC 226 Introduction to Programming with C++
// Name: Eddie Greathuse
// Lab L4: Using an array to work with UPC Codes
/*
    Purpose: <Put a more in-depth description of the program here, and an
    explanation as to why you submitted separate source files if you decided
    to continue to work on the assignment separately.>
*/
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
class BarCodes
{
public:
    BarCodes();
    void input_numbers(ifstream& input);
    void output_numbers(ofstream& output);

private:
    int check_digit[11];
    bool check_valid(); //returns true if check digit is correct


};

int main()
{
    BarCodes UPC_codes;
    ifstream in_stream;
    ofstream out_stream;
    char input[12], output[12];
    int i, j(0);
    cout << "Enter the filename of the input file and the output file, seperated by a space." << endl;
    cin >> input;
    cin >> output;
    in_stream.open(input);
    if (in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    else
    {
    out_stream.open(output);
    if (out_stream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    in_stream >> i;
    while (i>j)
    {
        cout << "hello";
    UPC_codes.input_numbers(in_stream);
    UPC_codes.output_numbers(out_stream);
    j++;
    }
    in_stream.close();
    out_stream.close();
    return 0;
    }
}
BarCodes::BarCodes()
{
}
void BarCodes::input_numbers(ifstream& input)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
    input >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10 >> n11 >> n12;
    check_digit[0] = n1;
    check_digit[1] = n2;
    check_digit[2] = n3;
    check_digit[3] = n4;
    check_digit[4] = n5;
    check_digit[5] = n6;
    check_digit[6] = n7;
    check_digit[7] = n8;
    check_digit[8] = n9;
    check_digit[9] = n10;
    check_digit[10] = n11;
    check_digit[11] = n12;
    cout << "test";

}
void BarCodes::output_numbers(ofstream& output)
{
    if (check_valid()==true)
    {
        cout << "works";
        output << check_digit[1];
    }
    else
    {
        output << "ERROR";
        cout << "test";
    }

}
bool BarCodes::check_valid()
{
    cout << "tes69";
    int tempa, tempb, tempc, tempd, checkdigit;
    tempa = (check_digit[0] + check_digit[2] + check_digit[4] + check_digit[6] + check_digit[8] + check_digit[10])*3;
    tempb = check_digit[1] + check_digit[3] + check_digit[5] + check_digit[7] + check_digit[9];
    tempc = tempa + tempb;
    if (tempc % 10 != 0)
    {
        tempd = tempc % 10;
        checkdigit = 10 - tempd;
    }
    if (checkdigit == check_digit[11])
    {
        return true;
    }
    else
    {
        return false;
    }

}
