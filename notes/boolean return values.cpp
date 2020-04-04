#include <iostream>

using namespace std;

//Boolean return values

//returns true if x and y are equal, false otherwise.

bool isEqual (int x, int y)
{
    return (x==y);
}

int main()
{
    cout << "Enter an integer: ";
    int x{0};
    cin >> x;

    cout << "Enter another integer: ";
    int y{0};
    cin >> y;

    cout << boolalpha;

    cout << x << " and " << y << "are real?";
    cout << isEqual(x,y);

    return 0;;
}
