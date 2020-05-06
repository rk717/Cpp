#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; //size of array
    int M; //number of factory
    int K; //candy types
    cin >> N >> M >> K;
    vector <int> fac; int a; 
    vector <int> cand; int b;
    vector <int> price; int c;

    for(int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        fac.push_back(a);
        cand.push_back(b);
        price.push_back(c);
    }

    //a)what is the cheapest candy that you can buy in this shop?
    int lp = *min_element(price.begin(), price.end());
    for(int i = 0; i < N; i++)
    {
        if(price[i] == lp)
        {
            cout << fac[i] << " " << cand[i] << endl;
            break; //print out the first solution
        }
    }

    //b)From which facotry comes the highest number of different types of candy?
    vector <int> facb; 
    for(int i = 0; i < fac.size(); i++)
    {
        facb.push_back(fac[i]);
    }

    sort(facb.begin(), facb.end());
    int count = 1, tempCount;
    int popular = fac[0];
    int temp = 0; 
    for(int i = 0; i < facb.size() - 1; i++)
    {
        temp = fac[i];
        tempCount = 0; 
        for(int j = 0; j < fac.size(); j++)
        {
            if(temp == fac[j])
            {
                tempCount++;
            }
        }
        if (tempCount > count)
        {
            popular = temp; 
            count = tempCount;
        }
    }
    cout << popular << endl;

    //c)How much does the most expensive candy of each facotry cost?
    vector <int> facc;
    
    for(int i = 0; i < fac.size(); i++)
    {
        facc.push_back(fac[i]);
    }
    sort(facc.begin(), facc.end());
    facc.erase(unique(facc.begin(), facc.end()), facc.end());
    cout << facc.size();

    vector <int> ctemp;
    vector <int> c2temp;
    vector <int> csecond;
    
    int cd = 0;
    while (cd < facc.size())
    {
        for(int i = 0; i < fac.size(); i++)
        {
            if(facc[cd] == fac[i])
            {
                ctemp.push_back(price[i]);
            }
        }
        int big = *max_element(ctemp.begin(), ctemp.end() );
        csecond.push_back(big);
        ctemp.clear();
        cd++;
    }
    for(int i = 0; i < facc.size(); i++)
    {
        cout << " " << facc[i] << " " << csecond[i];
        
    }
    cout << endl;
    //d)How many different types of candles can be bought in this store.
    vector <int> cand2d;
    for(int i = 0; i < cand.size(); i++)
    {
        cand2d.push_back(cand[i]);
    }
    sort(cand2d.begin(), cand2d.end());
    cand2d.erase(unique(cand2d.begin(), cand2d.end()), cand2d.end());
    cout << cand2d.size() << endl;


    //e)Which candy types can be bought from only one facory?
    int ei = 0;
    int ecnt = 0;
    int etmp = 0;
    vector <int> elis;
    while(ei < cand2d.size())
    {
        for(int i = 0; i < cand.size(); i++)
        {
            if(cand2d[ei] == cand[i])
            {
                ecnt++;
                etmp = cand2d[ei];
            }
        }
        if(ecnt == 1)
        {
            elis.push_back(etmp);
        }
        ecnt = 0;
        etmp = 0;
        ei++;

    }
    cout << elis.size();
    for(int i = 0; i < elis.size(); i++)
    {
        cout << " " << elis[i]; 
    }
}
