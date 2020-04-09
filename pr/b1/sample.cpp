We measured the lowest (minimum) and the highest (maximum) temperatures for N days. Give the number and the index of the days when the difference between the lowest and the highest temperature was the smallest. Give all day’s index with these smallest difference! 


#include <iostream>

using namespace std;

typdef struct
{
    maxt, mint:int;
}Temp;

int main()
{
    //ask inputs
    int N;
    do{
        cout << "n: ";
        cin >> N;
        if (N<0)
        {
            cout << "error" << endl;
        }
    }while(N<0);
    
    Temp Days[N];
    for (int i = 0; i < N; i++)
    {
        do{
            cout << "give min and max temperature";
            cin >> Days[i].mint >> Days[i].maxt;
            if(Days[i].mint > Days[i].maxt)
            {
                cout << "the max need to be greater...";
            }
        }while(Days[i].mint > Days[i].maxt);
        
    }
    
    
    //start the algorithm 
    int maxdif = 0;
    maxdif = Days[0].maxt - Days[0].mint;
    int ncnt = 0;
    int outdays[N];
    outdays[0] = 0;
    for (int i = 1; i < N; i++)
        if((Days[0].maxt - Days[0].mint)==maxdif)
    {
        ncnt++;
        outdays[ncnt] = i;
        
    }
    if((Days[0].maxt - Days[0].mint) > maxdif)
    {
        ncnt=1;
        outdays[ncnt] = i;
        maxdif = Days[0].maxt - Days[0].mint;
    }
    
    //output result
    cout << "counter: " << ncnt << endl;
    for (int i = 1; i < ncnt; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    
}
