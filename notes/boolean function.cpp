bool b1 = true;      // declaring a boolean variable with true value   

bool x = 0;  // false 
bool y = 100;  // true 
bool z = 15.75;  // true


#include <iostream>

using namespace std;

bool is4digits (string pin)
{
    bool status = true;
    if(pin.length() != 4)
    {
        status = false;
    }
    return status;
}

int main()
{
    string PIN;
    cout << "enter a 4 digit PIN number: ";
    cin >>PIN;

    if(is4digits(PIN)==1)
    {
        cout << "PIN accempted.";
    }
    else
    {
        cout << "PIN Denied.";
    }

    return 0;
}
