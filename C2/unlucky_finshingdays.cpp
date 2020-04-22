#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] < 5)
        {
            cnt++;
        }
    }
    cout << cnt;
    int b[cnt];
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] < 5)
        {
            b[m] = i+1;
            m++;
        }
    }
    for(int i = 0; i < cnt; i++)
    {
        cout << " " << b[i];
    }


}