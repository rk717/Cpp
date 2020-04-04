#include <iostream>

using namespace std;

bool ExistsGreater (int x, int y)
{
    return (x < y);
}

int main()
{
    int n;
    cout << "Please give a size of an array, the size should between 2 and 20" << endl;
    cin >> n;

    cout << "Please input the numbers in the array." << endl;
    int arr[20];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x, y;
    for (int i = 0; i < (n-1); i++)
    {
        if (arr[i] < arr[i+1])
        {
            x = arr[i];
            y = arr[i+1];
            cout << "The Greater is  " << arr[i+1] << endl;
        }

    }
    cout << boolalpha;
    cout << "Does there have number which is greater than the previous one?" <<endl;
    cout << ExistsGreater(x,y);
}
