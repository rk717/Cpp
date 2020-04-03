#include <iostream>
using namespace std;
int main()
{

    cout << "Input the size of the array" << endl;
    int n;
    cin >> n;

    int a[n];
    int i = 0;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];

    }

    for (i = 0; i<n; i++)
    {
        cout << a[i];
    }

}
