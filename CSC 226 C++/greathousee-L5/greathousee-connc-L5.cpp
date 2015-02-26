// Course: CSC 226 Introduction to Programming with C++
// Name: Chloe Conn and Edward Greathouse
// Lab L5: Enumeration Types and the Switch Statement
/*
    Purpose: <This assignment creates a deck of cards, shuffles them, and distributes them to four players.
    To accomplish this task, each card is given a rank and suit and is stored as a single object. As a result,
    there are 52 objects of the class Card. In addition, this program demonstrates the usage of enumeration type.>
*/
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

enum suit_value {CLUBS=0, DIAMONDS, HEARTS, SPADES}; // The name of each suit in the deck
enum rank_value {TWO=0, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE}; //the name of each "value" in the deck

class Card
{
public:
    Card(); //default constructor
    Card(int the_rank, int the_suit); //constructor with parameters
    void user_choice(); //this function is not used, but would be useful is user wanted to make an individual card
    rank_value get_rank(); //accessor function, returns the rank
    suit_value get_suit(); // acessor function, returns the suit
    void set_rank(rank_value newrank); //Mutator function, sets the rank of the card
    void set_suit(suit_value newsuit); //Mutator function, sets the value of the card
    void print(); //prints the array to the screen


private:
    suit_value Suit; //variable of the enumeration type
    rank_value Rank; //" "
};

void shuffle(Card a[], int q);

int main()
{
    Card deck[52]; //calls the default constructor

    int count=0; //counter
    int number_in_hand; //will take as input from user

    int b=0, i=0; // more counters

        for (b = static_cast<int>(CLUBS); b <= static_cast<int>(SPADES); b++)
        {
            for (i = static_cast<int>(TWO); i<= static_cast<int>(ACE); i++)
            {
                deck[count].set_rank(static_cast<rank_value>(i));
                deck[count].set_suit(static_cast<suit_value>(b));
                deck[count].print();
                count++;
            }

        }
        //creates and displays all the objects
        shuffle(deck, 52); //shuffles the deck
        cout << "Shuffling!*****YEAH!" << endl;
        cout << "********************" << endl;
        cout << endl;
        for (int r=0; r <51; r++)
        {
        deck[r].print(); //prints the deck after it's been shuffled
        }
cout << "Now, enter the number of cards to be distributed to each player" << endl;
cout << "while ensuring the number is less than 13." << endl;
cin >> number_in_hand; // stores the number of cards that will be distributed to each player
int temp=0;
cout << "Player 1 has " << endl;
cout << endl;
for (temp; temp<=number_in_hand; temp++)
{
    deck[temp].print(); //printsr the cards in player 1's hand
}
cout << "Player 2 has " << endl;
cout << endl;
for (temp; temp<=number_in_hand*2; temp++)
{
    deck[temp].print(); //prints the cards in player 2's hand
}
cout << "Player 3 has " << endl;
cout << endl;
for (temp; temp <= number_in_hand*3; temp++)
{
    deck[temp].print(); //prints the cards in player 3's hand
}
cout << "Player 4 has " << endl;
cout << endl;
for (temp; temp <= number_in_hand*4; temp++)
{
    deck[temp].print(); //prints the cards in players 4's hand
}
    return 0;
}


Card::Card()
{
  Suit = CLUBS;
  Rank = TWO;
}
Card::Card(int the_suit, int the_rank)
{
    Rank = static_cast<rank_value>(the_rank);
    Suit = static_cast<suit_value>(the_suit);
}
void Card::user_choice()
{

}
rank_value Card::get_rank()
{
    return Rank;
}
suit_value Card::get_suit()
{
    return Suit;
}
void Card::set_rank(rank_value newrank)
{
    Rank = newrank;
}
void Card::set_suit(suit_value newsuit)
{
    Suit = newsuit;
}
void Card::print()
{
            switch (Rank)
            {
            case TWO:
            cout<<"Two";
            break;
            case THREE:
            cout<<"Three";
            break;
            case FOUR:
            cout<<"Four";
            break;
            case FIVE:
            cout<<"Five";
            break;
            case SIX:
            cout<<"Six";
            break;
            case SEVEN:
            cout<<"Seven";
            break;
            case EIGHT:
            cout<<"Eight";
            break;
            case NINE:
            cout<<"Nine";
            break;
            case TEN:
            cout<<"Ten";
            break;
            case JACK:
            cout<<"Jack";
            break;
            case QUEEN:
            cout<<"Queen";
            break;
            case KING:
            cout<<"King";
            break;
            case ACE:
            cout<<"Ace";
            break;
            }

        cout << " of ";

             switch( Suit )
            {
            case CLUBS:
            cout << "Clubs"<<endl;
            break;
            case DIAMONDS:
            cout << "Diamonds"<<endl;
            break;
            case HEARTS:
            cout << "Hearts"<<endl;
            break;
            case SPADES:
            cout <<"Spades"<<endl;
            break;
        }
        }

void shuffle(Card a[], int q)
{
    Card temp;
    int j;
    for (int i=0; i < q; i++)
    {
        j = rand() % 51 + 0;
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
}
