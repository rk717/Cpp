#include <bits/stdc++.h>
using namespace std;

int main()
{
    int events, days;
    cin >> events >> days;

    vector <int> first; int a;
    vector <int> last;  int b;
    vector <int> cost;  int c;

    for(int i = 0; i < events; i++)
    {
        cin >> a >> b >> c;
        first.push_back(a);
        last.push_back(b);
        cost.push_back(c);
    }
    
    int money = 0;

    for(int i = 0; i < events; i++)
    {
        money += (last[i]-first[i]+1)*cost[i];
    }

    cout << money << endl;

    int longtime = last[0] - first[0];
    int guardnum = 0; 
    for(int i = 0; i < events; i++)
    {
        if(last[i] - first[i] > longtime)
        {
            longtime = last[i] - first[i];
            guardnum = i;
        }

    }

    cout << guardnum + 1 << endl;

    vector <int> most;
    for(int i = 0; i < events; i++)
    {
        for(int m = first[i]; m < last[i] + 1; m++)
        {
            most.push_back(m);
        }
    }

    sort(most.begin(), most.end());
    
    int max = 0; 
    int cnt = 0;
    for(int i = 0; i < most.size(); i++)
    {
        if(most[i] == most[i+1])
        {
            cnt++;
            if(max < cnt)
            {
                max = cnt; 
            }
        }
        else
        {
            cnt = 0;
        }    
    }
    cout << max + 1 << endl;

    int sub = 0;
    int f = 0, g = 0;  
    for(int i = 0; i < most.size(); i++)
    {
        if(most[i] - most[i-1] > sub)
        {
            sub = most[i] - most[i-1];
            f = most[i-1] + 1;
            g = most[i] - 1;
        }
    }

    cout << f << " " << g; 

}
