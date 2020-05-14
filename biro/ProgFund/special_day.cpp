#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t1name; //task1 name
    int N; //number of special days
    vector <string> name; string singleName;//friends name
    vector <int> month; int a;//month number 
    vector <int> date; int b;//date number
    
    //input 
    getline(cin, t1name);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin.ignore(999, '\n');
        getline(cin, singleName);
        name.push_back(singleName);

        cin >> a >> b;
        month.push_back(a);
        date.push_back(b);
    }

    //a) count and list all the special days that belong to a given person
    int a_cnt = 0;
    for(int i = 0; i < N; i++)
    {
        if(name[i] == t1name)
        {
            a_cnt++;
        }
    }
    
    cout << a_cnt;  //count of the special days that name belongs to.
    for(int i = 0; i < N; i++)
    {
        if(name[i] == t1name)
        {
            cout << " " << month[i] << " " << date[i];
        }
    }

    cout << endl;
    //b)Count and list all of our friends(each person should appear in the list once)
    vector <string> b_name;
    for(int i = 0; i < name.size(); i++)
    {
        b_name.push_back(name[i]);
    }

    vector <string> b_setName;
    for(int i = 0; i < b_name.size(); i++)
    {
        if(find(b_setName.begin(), b_setName.end(), b_name[i])!= b_setName.end()) 
        {
            continue;
        }
        else
        {
            b_setName.push_back(b_name[i]);
        }
        
    }
    cout << b_setName.size() << " ";

    for(int i = 0; i < b_setName.size() - 1; i++)
    {
        cout << b_setName[i] << ",";
    }
    cout << b_setName[b_setName.size()-1];
    cout << endl;

    //c)Create a summary about all the special days of each month
    vector <int> c_month;
    for(int i = 0; i < 12; i++)
    {
        c_month.push_back(0);
    } 

    for(int i = 0; i < month.size(); i++)
    {
        c_month[month[i] - 1] += 1;
    } 

    cout << c_month[0];
    for(int i = 1; i < 12; i++)
    {
        cout << " " << c_month[i];
    }
    cout << endl;

    //d)which month are ther the most special days, and how many special days are there in this month
    vector <int> d_month;
    for(int i = 0; i < 12; i++)
    {
        d_month.push_back(0);
    }

    vector <int> d_new;
    int dnum = 1;
    for(int i = 0; i < N; i++)
    {
        if(month[i] == month[dnum])
        {
            if(date[i] != date[dnum])
            {
                d_new.push_back(month[i]);
            }
        }
        if(month[i] != month[dnum])
        {
            d_new.push_back(month[i]);
        } 
        dnum++;
        
    }

    for(int i = 0; i < d_new.size(); i++)
    {
        d_month[d_new[i] - 1] += 1;
    }
    //2 0 0 0 0 1 0 2 0 0 0 1

    int dbig = 0;
    int dvalue = 0;
    for(int i = 0; i < d_month.size(); i++)
    {
        if(d_month[i] > dbig)
        {
            dbig = d_month[i];
            dvalue = i;
        }
    }

    cout << dvalue + 1 << " " << dbig;
    
    // for(int i = 0; i < d_month.size(); i++)
    // {
    //     cout << d_month[i];
    // }

    // vector<int> monthnew;
    // vector<int> daynew;
    // for (int i = 0; i < N; i++)
    // {
    //     if (find(monthnew.begin(), monthnew.end(), month[i]) == monthnew.end() && find(daynew.begin, daynew.end(), day[i]) == daynew.end()) 
    //     {
    //         monthnew.push_back(month[i]);
    //         daynew.push_back(day[i]);
    //     }
    // }
}

