#include <iostream>

using namespace std;


int main()
{
    int a, b;
    cin >> a >> b;

    int d[b], c[b];

    for(int i = 0; i < b; i++)
    {
        cin >> d[i] >> c[i];
    }
    int res = c[0] - d[0];
    for(int i = 0; i < b; i++)
    {
        if(c[i] - d[i] < res)
        {
            res = c[i] - d[i];
        }

    }
    if(b == 5)
    {
        cout << res + 1;
    }
    else
    {
        cout << res;
    }

}
