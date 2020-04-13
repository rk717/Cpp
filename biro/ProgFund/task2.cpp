Input:
The frst line of the standard input contains the count of food chain pairs (1≤N≤30). The next N lines contain the food chain pairs: two words separated by a space. The frst living being eats the second. There are no accents in the names of living beings. 

Output
The frst line of the standard output should contain the count of animals that eat other animals (they might eat plants, as well). The next lines should each contain the name of an animal that eats another animal. If there are no such animals, the output should be 0. 

input:
7
fox partridge
for blackbird
partridge earthworm
snail grass
blackbird snail
earthworm leaflitter
blackbird grain 

Output:
3
roka
fogoly
feketerigo




#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    string list1[n], list2[n];

    for(int i = 0; i < n; i++)
    {
        cin >> list1[i] >> list2[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(list2[j] == list1[i])
            {
                cnt += 1;  //cnt = 5
            }
        }
    }

    string animal[cnt];
    int a = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(list2[j] == list1[i])
            {
                animal[a] = list1[j];
                a++;
            }
        }
    }
       /*
        fox
        blackbird
        fox
        partridge
        fox
        */
    string res[cnt];
    int b = 0;
    for(int i = 0; i < cnt; i++)
    {
        bool exist = false;
        for(int j = 0; j < b; j++)
        {
            if(animal[i] == res[j])
            {
                exist = true;
            }
        }
        if(exist == false)
        {
            res[b] = animal[i];
            b += 1;

        }
    }

    string newl[n];
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        bool exist = false;
        for(int j = 0; j < c; j++)
        {
            if(list1[i] == newl[j])
            {
                exist = true;
            }
        }
        if(exist == false)
        {
            newl[c] = list1[i];
            c += 1;
        }
    }

    string ans[n];  //res[n] 和 newl[n].
    int f = 0;
    for(int i = 0; i < n; i++ )
    {
        for(int j = 0; j < n; j++)
        {
            if(newl[i] == res[j])
            {
                ans[f] = newl[i];
                f++;
            }
        }
    }





    cout << b << endl;
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}
