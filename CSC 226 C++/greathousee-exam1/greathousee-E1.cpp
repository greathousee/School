// I was not able to complete this project. The formatting needs editing, and there is a logic error when running the program. I did not have enough time to debug the program.
#include <iostream>

using namespace std;

double convert_USD_to_ARS (double exchange_rate, double exchange_fee, double amount_exchanged);

int main()
{
    double exchange_rate, exchange_fee, amount_exchanged;
    cout << "Hello, I will convert your stinky US dollars to awesome South American dollars.\n" << endl;
    cout << "However, I need your help \n" << endl;
    cout << "Please enter the exchange rate.\n" << endl;
    cin >> exchange_rate;
    if (exchange_rate <= 0);
    {
        cout << "Please enter a POSITIVE exchange rate.\n" << endl;
        cin >> exchange_rate;
    }
    cout << "Thank you. Please enter the exchange fee.\n" << endl;
    cin >> exchange_fee;
    if (exchange_fee <= 0);
    {
        cout << "Please enter a POSITIVE exchange fee. \n" << endl;
        cin >> exchange_fee;
    }
amount_exchanged = 50;
while ((amount_exchanged >= 50) && (amount_exchanged <= 500));
{
    cout << "$" << convert_USD_to_ARS(exchange_rate, exchange_fee, amount_exchanged) << "equals" << amount_exchanged << endl;
amount_exchanged = amount_exchanged + 50;
}


    return 0;
}
double convert_USD_to_ARS(double exchange_rate, double exchange_fee, double amount_exchanged)
{
    double awesome_money;
    awesome_money = (amount_exchanged-exchange_fee)*exchange_rate;
    return awesome_money;
}
