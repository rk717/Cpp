//we have some positive numbers (we do not know how many)
//the user will signal the end of the input by 0. 
//in other words: user will input until cue(0)
//How long is the biggest monotonic increasing part of the numbers

//1 2 3 4 5 -> 5
//1 2 1 2 1 -> 2
//1 2 3 4 2 3 4 -> 4
//1 1 1 1 -> 0
//4 3 2 1 -> 0
//1 2 3 1 2 3 4 ->

#include <iostream>
#include <vector>

using namespace std;

//Integer input function's head
int input_integer(string input_text, int minval, int maxval, string error_message);

//Integer vector
vector<int> input_int_vector();

//Count of Maximum monotonic part
int max_mon_count(vector<int> array);

int main()
{
    vector<int> numbers = input_int_vector();

    int maxmon = max_mon_count(numbers);

    if (maxmon == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << maxmon + 1 << endl;
    }
    return 0;
}

//Integer input function
int input_integer(string input_text, int minval, int maxval, string error_message)
{
    //Variables for error handling
    bool error;
    //Local variables for the function
    int num;
    do
    {
        cout << input_text << endl;
        cin >> num;
        error=cin.fail() || cin.peek()!='\n' || (num < minval || num > maxval);
        if (error)//Error, if the type is not correct or input does not meet the precondition
        {
            cout << error_message << endl;
        }
        cin.clear();
        cin.ignore(999,'\n');
    }while(error);
    return num;
}

vector<int> input_int_vector()
{
    vector<int> nums;
    int number;
    //your code comes here...
    while(cin >> number && number != 0)
    {
        nums.push_back(number);
    }
    return nums;
}

int max_mon_count(vector<int> array)
{
    int count = 0;
    //your code comes here...
    for(int i = 0; i < array.size(); i++)
    {
        int j = i;
        while(j < array.size() - 1 && array[j] < array[j+1])
        {
            j++;
        }
        if( j - i > count)
        {
            count = j - i;
        }
        i = j;
    }


    return count;
}
