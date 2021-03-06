// Course: CSC 226 Introduction to Programming with C++
// Name: Edward Greathouse
// Assignment A16: <This program takes as input a stream of mixed integers in random order. The user
//                  is then opted to choose to sort the integers using selection sort or insertion sort.
//                  The resulting stream is exported to a txt document titled "sortednumbers.txt">
/*
 Purpose: <This program demonstrates proper use of classes, arrays, and streams. Within the class, a constructor,
 a public mutator function, public accessor functions, and several member functions and variables. The constructor, and some functions
 make proper use of input and output steams. In addition, several member functions manipulate and use complex algorithms to make
 several changes to an array.>

 Answers to questions:
 I. The number of comparisons are always greater than the number of swaps. This is because not comparisons will need to be swapped.
 II. When there is a larger quantity of integers, there are a lot more swaps than comparisons. I am not sure why this is.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_ARRAY = 250;

class ArraySorter
{
public:
    ArraySorter();
    //Postcondition: asks user for a file, opens it, and put the numbers in the array
    void fill_array();
    //copies the array filled by the constructor to workingArray
    void selection_sort();
    //sorts the array using the selection style from least to greatest and records the number of swaps and comparisons
    void insertion_sort();
    //Goes through each element in the array
    void insertion_sort_swap(int index);
    //sorts the array using the instertion style from least to greatest and records the number of swaps and compatrisons
    void create_stream(ostream& outs);
    //prints the sorted array to a file
    int num_swaps();
    //returns the number of swaps
    int num_comparisons();
    //returns the number of cpmparisons
    int index_of_smallest(int startIndex);
    //returns the smalled number in the array
    void swap_values(int& first, int& second);
    //swaps numbers in the array
private:

    int numberUsed; //stores the actual number of integers in the array
    int storedArray[MAX_ARRAY]; //stores a series of numbers read from a file
    int workingArray[MAX_ARRAY];
    int number_swaps = 0;
    int number_comparisons = 0;
};

int main()
{
    double sort_type;
    int p(0);
    cout << "Hello, this program takes a stream of integers and\n" << endl;
    cout << "outputs them in ascending order.\n" << endl;
    ArraySorter users_numbers;
    cout << "Please type of sorting to be done ('sel' for selection, or 'ins' for insertion).\n" << endl;
    cin >> sort_type;
    if (sort_type = 'sel')
    {
        users_numbers.fill_array();
        users_numbers.selection_sort();
    }
    if (sort_type = 'ins')
    {
        users_numbers.fill_array();
        users_numbers.insertion_sort();
    }
    cout << "The number of comparisons is " << users_numbers.num_comparisons() << endl;
    cout << "The number of swaps is " << users_numbers.num_swaps() << endl;
    return 0;
}
ArraySorter::ArraySorter()
{
    ifstream in_stream;
    char usersfile[250];
    int next, i = 0;
    cout << "Please enter the name of the file to be used" << endl;
    cin >> usersfile;
    in_stream.open(usersfile);
    if (in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
        while (! in_stream.eof())
        {
            in_stream >> next;
            storedArray[i] = next;
            i++;
        }
        numberUsed = i;
    in_stream.close();
}
void ArraySorter::fill_array()
{
    for (int j = 0; j < numberUsed; j++)
    {
        workingArray[j] = storedArray[j];
    }
}
int ArraySorter::index_of_smallest(int startIndex)
{

	int minIndex = startIndex;
    for (int index = startIndex + 1; index < numberUsed; index++)
        if ( workingArray[index] < workingArray[minIndex] )
        {
            minIndex = index;
            number_comparisons = number_comparisons + 1;
        }

    return minIndex;
}
void ArraySorter::selection_sort()
{
    ofstream out_stream;
    int indexOfNextSmallest;
    for (int index = 0; index < numberUsed - 1; index++)
    {//Place the correct value in arrayToSort[index]:
        indexOfNextSmallest = index_of_smallest(index);
        swap_values(workingArray[index], workingArray[indexOfNextSmallest]);
        number_swaps = number_swaps + 1;
    }
    out_stream.open("sortedfile.txt");
    if (out_stream.fail())
    {
        cout << "Output file opening failed\n";
        exit(1);
    }
    create_stream(out_stream);
    out_stream.close();
}
void ArraySorter::swap_values(int& first, int& second)
{
   int temp = first;
   first = second;
   second = temp;
}
void ArraySorter::create_stream(ostream& outs)
{
 for (int i = 0; i <= numberUsed; i++)
 {
     outs << workingArray[i] << endl;
 }
}
void ArraySorter::insertion_sort_swap(int index)
{
int newSpot=index, temp;
    while( newSpot > 0 && workingArray[newSpot-1] > workingArray[newSpot] )
    {
    temp = workingArray[newSpot-1]; // because the element is smaller than the one "under" it, swap!
    workingArray[newSpot-1] = workingArray[newSpot];
    workingArray[newSpot] = temp;
    newSpot --; // decrement newSpot to move the insertion downwards
    number_swaps = number_swaps + 1;
    number_comparisons = number_comparisons + 1;
    }
}
void ArraySorter::insertion_sort()
{
    ofstream out_stream;
    for (int i = 0; i <= numberUsed-1; i++)
        {
            insertion_sort_swap(i);
        }
        out_stream.open("sortedfile.txt");
    if (out_stream.fail())
    {
        cout << "Output file opening failed\n";
        exit(1);
    }
    create_stream(out_stream);
    out_stream.close();
}
int ArraySorter::num_comparisons()
{
    return number_comparisons;
}
int ArraySorter::num_swaps()
{
    return number_swaps;
}
