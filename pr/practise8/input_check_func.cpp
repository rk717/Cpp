#include <iostream>

using namespace std;

int input_integer(string input_text, int minval, int maxval, string error_message);
void input_int_array(int size, int array[]);

int main()
{
    //input variables
    int count;
    //input with error check
    count = input_integer("Please enter an integer number! (1<=number<=20)",1,20, "You entered a string or an invalid number. Please try again with an integer number! (1<=number<=20)");
    //Array declaration
    int numbers[count];
    //Array input
    input_int_array(count, numbers);

    return 0;
}

int input_integer(string input_text, int minval, int maxval, string error_message)
{
    //local variables
    bool error;
    int number;
    do
    {
        cout << input_text << endl;
        cin >> number;
        //error, if it is not an integer or less than 1 or greater than 20
        error = cin.fail() || cin.peek()!='\n' || number < minval || number > maxval;
        if (error)
        {
            cout << error_message << endl;
        }
        cin.clear();
        cin.ignore(999,'\n');
    }
    while (error);
    return number;
}

void input_int_array(int size, int array[])
{
    for (int i=0; i<size; i++)
    {
        cout << i+1 << " . array element: " << endl;
        array[i] = input_integer("Please input an integer number(0<=number<20) ", 0, 20, "You have typed an invalid input, you should give an integer number between 0 and 20!");
    }
}

