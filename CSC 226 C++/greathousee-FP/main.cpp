// Course: CSC 226 Introduction to Programming with C++
// Name: Edward Greathouse
// Final Project: < A card game commonely known as "Spades" >
/*
    Purpose: <This program replicates a very commonly known card game called "Spades". In this particular version, the user will play against a computer
    and attempt to win as many tricks as possible. >
*/
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

enum suit_value {SPADES=0, DIAMONDS, HEARTS, CLUBS}; // The name of each suit in the deck
enum rank_value {TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE}; //the name of each "value" in the deck

class Card
{
public:
    Card(); //default constructor
    Card(int the_rank, int the_suit); //constructor with parameters
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
void remove_card(Card hand[], int& position, bool& player_turn, int& cards_left);

int main()
{
    Card deck[52]; //calls the default constructor

    int count=0; //counter
    int number_in_hand=26;
    int b=0, i=0; // more counters
        for (b = static_cast<int>(SPADES); b <= static_cast<int>(CLUBS); b++)
        {
            for (i = static_cast<int>(TWO); i<= static_cast<int>(ACE); i++)
            {
                deck[count].set_rank(static_cast<rank_value>(i));
                deck[count].set_suit(static_cast<suit_value>(b));
                count++;
            }
        }
shuffle(deck, 52); //shuffles the deck
int temp=0;
/*Now, we're going to design the loop for
    winning a trick.  The leading player must select
    and play a card from the hand. Then, the other
    player must select a card of the same suit to play.
    If there are no cards of the same suit, the other
    player may play any card in his or her hand.
    Then, the winner of the trick is determined,
    the two cards played are discarded, and the next
    trick is played. This continues until both players’
    hands are empty.*/
    bool bHumanLeads = true;
    char acChoice[2];
    int iRank;
    int iSuit;
    Card curPCard; //This represents the player's chosen card
    Card curCCard; //This represents the comp's chosen card
    int iLeadingSuit; //This represents the suit of the leading card
    while( number_in_hand > 0 )
    {
        if( bHumanLeads == true )
        {
            cout << " " << endl;
            cout << "Here's your hand again: " << endl;
            cout << endl;
            for ( i = 0; i < number_in_hand; i++ )
            {
                deck[i].print();
            }
            cout << " " << endl;
            cout << " " << endl;
            bool ProperCard = false;//True if card is in the hand
            do //while card chosen is in users hand
            {
                cout << "Which card would you like to play? (2, 3, 4, t, j, etc.) (h, d, c, s) ";

                //This is the function for choosing a proper card
                do //while users choice is valid
                {
                    cin >> acChoice[0] >> acChoice[1];
                    switch ( acChoice[0] )
                    {
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                            iRank = acChoice[0] - 48;   // the ascii value of the char is
                            break;                      // 48 greater than its numeric value
                        case 'T':
                        case 't':
                            iRank = 10;
                            break;
                        case 'J':
                        case 'j':
                            iRank = 11;
                            break;
                        case 'Q':
                        case 'q':
                            iRank = 12;
                            break;
                        case 'K':
                        case 'k':
                            iRank = 13;
                        break;
                        case 'A':
                        case 'a':
                            iRank = 14;
                            break;
                        default:
                            cout << "That's no good, my friend.  Please enter a valid rank (2,3,4,5,6,7,8,9,T,J,Q,K,A).";
                            iRank == NULL;
                            break;
                    };

                    // determine card suit
                switch ( acChoice[1] )
                {
                        case 'H':
                        case 'h':
                            iSuit = 2;
                            break;
                        case 'D':
                        case 'd':
                            iSuit = 1;
                            break;
                        case 'C':
                        case 'c':
                            iSuit = 3;
                            break;
                        case 'S':
                        case 's':
                            iSuit = 0;
                            break;
                        default:
                            cout << "That's not a suit, friend. Try again (H,D,C,S).";
                            iSuit == NULL;
                            break;
                };
                } while (iRank == NULL || iSuit == NULL);

                //Here, we'll check to see if the card is in the player's hand
                for( i = 0; i < number_in_hand; i++ )
                {
                    if ( deck[i].get_suit() == iSuit && deck[i].get_rank() == iRank )
                    {
                        ProperCard = true;
                        curPCard = deck[i];
                        remove_card(deck, i, bHumanLeads, number_in_hand);
                        i=27;
                    }
                    else
                    {
                        ProperCard = false;
                    }
                }
            } while ( ProperCard == false );
            //Here, we select a card from the comp's hand
                for(  i = 26; i <= 26+number_in_hand; i++ )
                {
                    if( deck[i].get_suit() == iSuit )
                    {
                        curCCard = deck[i];
                        bHumanLeads=false;
                        remove_card(deck, i, bHumanLeads, number_in_hand);
                        i=27+number_in_hand;
                    }
                    else
                    {
                        curCCard= deck[26];
                    }
                }
            cout << endl << " " << endl;
            cout << "Your opponent played ";
            curCCard.print();
            cout << endl;
            cout << "You played ";
            curPCard.print();
            cout << endl;
            if (curCCard.get_rank()>curPCard.get_rank())
            {
                cout << "Computer wins the trick" << endl;
                bHumanLeads=false;
                number_in_hand--;
            }
            else
            {
                cout << "Good Job, you win the trick" << endl;
                bHumanLeads=true;
                number_in_hand--;
            }
        }
        else //computer plays first card
        {
         cout << "The computer played:" << endl;
         deck[26].print();
         cout << endl;
         bool ProperCard = false;
         do //while card chosen is in users hand
            {
                cout << "Here is your hand again:" << endl;
                for (int i=0; i <number_in_hand; i++)
                {
                    deck[i].print();
                }
                cout << endl;
                cout << "Which card would you like to play? (2, 3, 4, t, j, etc.) (h, d, c, s) ";

                //This is the function for choosing a proper card
                do //while users choice is valid
                {
                    cin >> acChoice[0] >> acChoice[1];
                    switch ( acChoice[0] )
                    {
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                            iRank = acChoice[0] - 48;   // the ascii value of the char is
                            break;                      // 48 greater than its numeric value
                        case 'T':
                        case 't':
                            iRank = 10;
                            break;
                        case 'J':
                        case 'j':
                            iRank = 11;
                            break;
                        case 'Q':
                        case 'q':
                            iRank = 12;
                            break;
                        case 'K':
                        case 'k':
                            iRank = 13;
                        break;
                        case 'A':
                        case 'a':
                            iRank = 14;
                            break;
                        default:
                            cout << "That's no good, my friend.  Please enter a valid rank (2,3,4,5,6,7,8,9,T,J,Q,K,A).";
                            iRank == NULL;
                            break;
                    };

                    // determine card suit
                switch ( acChoice[1] )
                {
                        case 'H':
                        case 'h':
                            iSuit = 2;
                            break;
                        case 'D':
                        case 'd':
                            iSuit = 1;
                            break;
                        case 'C':
                        case 'c':
                            iSuit = 3;
                            break;
                        case 'S':
                        case 's':
                            iSuit = 0;
                            break;
                        default:
                            cout << "That's not a suit, friend. Try again (H,D,C,S).";
                            iSuit == NULL;
                            break;
                };
                } while (iRank == NULL || iSuit == NULL);

                //Here, we'll check to see if the card is in the player's hand
                for( i = 0; i < number_in_hand; i++ )
                {
                    if ( deck[i].get_suit() == iSuit && deck[i].get_rank() == iRank )
                    {
                        ProperCard = true;
                        curPCard = deck[i];
                        remove_card(deck, i, bHumanLeads, number_in_hand);
                        i=27;
                    }
                    else
                    {
                    ProperCard = false;
                    }
                }
            } while ( ProperCard == false );
            cout << endl << " " << endl;
            cout << "Your opponent played ";
            curCCard.print();
            cout << endl;
            cout << "You played ";
            curPCard.print();
            cout << endl;
            if (curCCard.get_rank()>curPCard.get_rank())
            {
                cout << "Computer wins the trick" << endl;
                bHumanLeads=false;
                number_in_hand--;
            }
            else
            {
                cout << "Good Job, you win the trick" << endl;
                number_in_hand--;
            }
        }
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
void remove_card(Card hand[], int& position, bool& player_turn, int& cards_left )
{
    Card temp;
    if (player_turn==true)
    {
        temp=hand[-1+cards_left];
        hand[position]=temp;
    }
    else
    {
        temp=hand[26+cards_left];
        hand[position]=temp;
        cout<< "computer changing cards" << endl;
    }
}
