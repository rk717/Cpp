#include <iostream>

using namespace std;

int main()
{
    //car's tank max 40
    //input 0 and 40 (0<cars[i]<41)
    bool error;
    int count;
    do
    {
        cout << "Please input number of cars from 0 and 10: ";
        cin >> count;
        error = cin.fail() || cin.peek() != '\n' || count<1 || count>10;
        if(error)
        {
            cout << "You type a string or a non positive number of the number out of range" << endl;
        }
        cin.clear();
        cin.ignore(999,'\n');
    }while(error);

    float a[count], b[count];

    for(int i = 0; i < count; i++)
    {
        do
        {
            cout << "Please add the " << i+1 << "car's information" << endl;
            cout << "How many fuel's does the " << i+1 << " car left, and how many fuel's does this car need for 100km?"<<endl;
            cin >> a[i] >> b[i];
            error = cin.fail() || cin.peek() != '\n' || a[i] > 40;
            if(error)
            {
                cout << "The car's tank can be ill with maximum 40l fuel. " << endl;
            }
            cin.clear();
            cin.ignore(999,'\n');
        }while(error);

    }
    int cnt = 0;
    for(int i = 0; i < count; i++)
    {
        if(a[i] - 0.8*b[i] >= 0 )
        {
            cnt++;
        }
    }

    int num[cnt], j=0;
    for(int i = 0; i < count; i++)
    {
        if(a[i] - 0.8*b[i] >= 0)
        {
            num[j] = i+1;
            j++;
        }
    }
    cout << "The amount of cars who can reach the next petrol station, and the cars index: ";
    cout << cnt;
    for(int i = 0; i < cnt; i++)
    {
        cout << " "<< num[i];
    }
    cout << endl;
    bool exist;
    cout << "Do there have the car with empty tank? " << endl;
    for(int i = 0; i < count; i++)
    {

        if(a[i] == 0)
        {
            exist = true;
        }

    }
    if(exist == true)
        {
            cout <<"Yes";
        }
        else
        {
            cout <<"No";
        }
}
