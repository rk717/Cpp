#include <iostream>
#include <vector>
using namespace std;


void input_vector(vector<int> &array )
{
    int n;
    int a;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        array.push_back(a);
    }
}


int main()
{
    vector<int> fish;
    input_vector(fish);

    int cnt = 0;
    for(int i = 0; i < fish.size(); i++)
    {
        if(fish[i] < 5)
        {
            cnt++; 
        }
    }
    cout << cnt; 
    
    vector<int> sad;
    
    for(int i = 0; i < fish.size(); i++)
    {
        if(fish[i] < 5)
        {
            sad.push_back(i+1);
            
        }
    }

    for(int i = 0; i < sad.size(); i++)
    {
        cout << " " << sad[i]; 
    }

    
}