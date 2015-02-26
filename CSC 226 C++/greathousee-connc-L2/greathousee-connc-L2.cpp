// Course: CSC 226 Introduction to Programming with C++
// Name: Edward Greathouse & Chloe Conn
// Lab 2: Creating Histograms
/*
 Purpose: This program is designed to to make hisographs for 4 or 5 possible-answer questions.
 It welcomes the user, determines the whether it should design a 4 column histo graph or a 5 column histo graph.
 Then it takes the number of answers that were "a," then "b," then "c," then " d," (then "e," where applicable)
 and creates a histogram.
*/
#include <iostream>
using namespace std;

bool valid (int num_choice);
void histo(int a, int b, int c, int d,int max);
void histo(int a, int b, int c , int d, int e, int max);
int max_check(int a, int b, int c, int d);
int max_check(int a, int b, int c, int d, int e);

//Declares the functions.

int main()

{
    int num_choices(0), a(0), b(0),c(0),d(0),e(0);
    int max_val(0);
    //variable declaration
    cout<<"Welcome to the Choice historgram!"<<endl;
    cout<<"Please enter the number of choices:";
    cin>>num_choices;

    while((valid(num_choices))== false) //if the num_choices is not 4 or 5, loops.
    {
    cout<<"You entered an invalid number of questions!!\n"<<"Please enter 4 or 5:";
    cin >> num_choices;
	}

    if (num_choices ==4) //creates a histogram for 4 width histogram.
    {
        cout<<"How many people picked a?:";
        cin>>a;cout<<endl;
        cout<<"How many people picked b?:";
        cin>>b;cout<<endl;
        cout<<"How many people picked c?:";
        cin>>c;cout<<endl;
        cout<<"How many people picked d?:";
        cin>>d;cout<<endl;
        max_val=max_check(a,b,c,d);
        histo(a,b,c,d,max_val);
    }

    else //creates a 5 width histogram.
    {
        cout<<"How many people picked a?:";
        cin>>a;cout<<endl;
        cout<<"How many people picked b?:";
        cin>>b;cout<<endl;
        cout<<"How many people picked c?:";
        cin>>c;cout<<endl;
        cout<<"How many people picked d?:";
        cin>>d;cout<<endl;
        cout<<"How many people picked e?:";
        cin>>e;cout<<endl;
        max_val=max_check(a,b,c,d,e);
        histo(a,b,c,d,e,max_val);
    }


return (0);



}

bool valid(int num_choice)
{
 	if (num_choice >5)
        return false;
    else if(num_choice<4)
        return false;

    else
        return true;
}
int max_check(int a, int b, int c, int d) //determines what the maximum of the height of the graph will be.
{
    int def_max(0);

    if((a>b)&&(a>c)&&(a>d))
        def_max=a;
    else if ((b>a)&&(b>c)&&(b>d))
        def_max=b;
    else if ((c>a)&&(c>b)&&(c>d))
        def_max=c;
    else if ((d>a)&&(d>c)&&(d>b))
        def_max=d;

    else
        def_max=d;

    return (def_max);
}

int max_check(int a, int b, int c, int d, int e)
{
        int def_max(a);

if( b >def_max ) def_max = b;
if( c >def_max ) def_max = c;
if( d>def_max ) def_max = d;
if( e >def_max ) def_max = e;

    return (def_max);
}

void histo(int a, int b, int c , int d, int max) //max value is the height of the graph, building the histogram top to bottom
{
    do{
    if (a>=max)
    {
        cout<<"X";
    }
    if (b>=max)
    {
        cout<<"\tX";
    }
     else
    cout << "\t";
    if (c>=max)
    {
        cout<<"\tX";
    }
     else
    cout << "\t";
    if (d>=max)
    {
        cout<<"\tX";
    }
     else
    cout << "\t";
    max--;
    cout<<endl;
    }while(max>0);
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"A"<<"\tB"<<"\tC"<<"\tD"<<endl;


}

void histo(int a, int b, int c , int d, int e, int max) //overloading histo
{
    do{
    if (a>=max)
    {
        cout<<"X";
    }
    if (b>=max)
    {
        cout<<"\tX";
    }
     else
    cout << "\t";
    if (c>=max)
    {
        cout<<"\tX";
    }
     else
    cout << "\t";
    if (d>=max)
    {
        cout<<"\tX";
    }
     else
    cout << "\t";
    if (e>=max)
    {
        cout<<"\tX";
    }
     else
    cout << "\t";
    max--;
    cout<<endl;
    }while(max>0);
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"A"<<"\tB"<<"\tC"<<"\tD"<<"\tE"<<endl;

}
