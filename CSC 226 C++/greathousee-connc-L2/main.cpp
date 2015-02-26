#include <iostream>
using namespace std;

bool valid (int num_choice);
void histo(int a, int b, int c, int d,int max);
void histo(int a, int b, int c , int d, int e, int max);
int max_check(int a, int b, int c, int d);
int max_check(int a, int b, int c, int d, int e);

int main()

{
    int num_choices(0), a(0), b(0),c(0),d(0),e(0);
    int max_val(0);
    cout<<"Welcome to the Choice historgram!"<<endl;
    cout<<"Please enter the number of choices:";
    cin>>num_choices;

    while((valid(num_choices))== false)
    {
    cout<<"You entered an invalid number of questions!!\n"<<"Please enter 4 or 5:";
    cin >> num_choices;
	}

    if (num_choices ==4)
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

    else
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
int max_check(int a, int b, int c, int d)
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

void histo(int a, int b, int c , int d, int max)
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

void histo(int a, int b, int c , int d, int e, int max)
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
