Game consoles exists since the 1970s, and many companies fght for having a bigger share on the market of game consoles even today. Currently, we are in the 8th generation of game consoles. We made a short note of the game console companies that we think important. The note contains the name of the companies and the count of consoles released in each generation. We know that a certain console was released in the 7th generation. Write a program that defnes which companies could make this console. Hoow many such companies are there, and which are those companies? 

Input:
The standard input consists of 3 parts. The frst line contains the count of companies (1≤N≤100), then the next N lines contain the names of the companies. The frst line of the second part contains the count of notes (1≤M≤50); then come the notes themselves in M lines. A note consists of 3 numbers (separated by spaces): the ID of the console company (1≤ID≤N) based on the frst part of the input, the generation (1≤G≤8), and then the count of consoles (1≤C≤100). The same company and generation pair is listed only once. The third part of the input is just one line: two company indexes (1≤C1,C2≤N). 

Output:
The frst line of the standard output should contain the count and names of those companies who released consoled in the 7th generation. If there are no consoles from this generation, then write “NONE” (if this does not seem to work, try the Houngarian word “NINCS”). 


Input:
5
Nintendo
Sega
Sony
Microsoft
Nvidia 
6
1 1 5
1 3 4
2 3 4
4 5 4
1 4 5
4 7 1
1 3

Output:
1 Microsoft


#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string arr[n];


    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    int a1[m], a2[m], a3[m];

    for(int i = 0; i < m; i++)
    {
        cin >> a1[i] >> a2[i] >> a3[i];
    }

    int x, y;
    cin >> x >> y;

    int cnt = 0;


    for(int i = 0; i < m; i++)
    {

        if(a2[i] == 7)
        {
            cnt += 1;
        }
    }
    if(cnt == 0)
    {
        cout << "NONE";
    }
    else
    {
        cout << cnt;

        for (int i = 0; i < m; i++)
        {
            if(a2[i] == 7)
            {
                cout <<" " << arr[a1[i]-1];
            }
        }
    }











}
