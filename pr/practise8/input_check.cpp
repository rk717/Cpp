#include <iostream>

using namespace std;

int main()
{
    //input variables
    int count;
    //variables for error check
    bool error;
    //input with error check
    do
    {
        cout << "Please enter an integer number! (1<=number<=20)" << endl;
        cin >> count;
        //error, if it is not an integer or less than 1 or greater than 20
        error = cin.fail() || cin.peek()!='\n' || count < 1 || count > 20;
        if (error)
        {
            cout << "You entered a string or an invalid number. Please try again with an integer number! (1<=number<=20)" << endl;
        }
        cin.clear();
        cin.ignore(999,'\n');
    } while (error);
    //Array declaration
    int numbers[count];
    //Array input
    for (int i=0;i<count;i++)
    {
        do
        {
            cout << "Please enter the " << i+1 << " element! (integer number, 0<=number<=20)" << endl;
            cin >> numbers[i];
            //error, if it is not an integer or less than 0 or greater than 20
            error = cin.fail() || cin.peek()!='\n' || numbers[i] < 0 || numbers[i] > 20;
            if (error)
            {
                cout << "You entered a string or an invalid number. Please try again with an integer number! (0<=number<=20)" << endl;
            }
            cin.clear();
            cin.ignore(999,'\n');
        }while(error);
    }
    return 0;
}
