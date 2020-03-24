#include <iostream>
using namespace std;
int main()
{

    cout << "Input the size of the array" << endl;
    int n;
    cin >> n;

    int a[n];
    int i = 0;

    cout << "Please input the income" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];

    }

    int cntP = 0;
    int cntN = 0;
    for (i = 0; i < n; i++)
    {
        if(a[i] > 0 )
        {
            cntP += a[i];
        }
        else
        {
            cntN += a[i];
        }
    }


    int saving = 0;
    saving = cntP + cntN ;

    cout << "The final saving is " << saving << endl;

}
