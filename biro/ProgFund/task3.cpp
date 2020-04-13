At a competition, all participants get 1st place if they reach 90% of the total points; 2nd place if they reach 80% of the total points (but less than 90%); and 3rd place if they reach 70% of the total points (but less than 80%). The results of the participants are listed in alphabetical order. Write a program that creates the lists of awarded participants (grouped by category), and not awarded participants. 

Input：
The frst line of the standard input contains the count of participants (1≤N≤100) and the total points (1≤P≤100). The next N lines each contain a name and the achieved points (1≤Pi≤100) which are separated by a semicolon. 

Output:
Each line of the standard output should contain the count of participants of the given award, and the participants who were awarded. The items should be separated by a semicolon. The frst item in each line should be the count. The order of lines: I, II, III, not awarded 

Example:
input:
6 100
Angyal Pofa;90
Bozontos Beata;73
Cukor Falat;85
Dohongo Diana;78
Eros Pista;83
Fickos Ferenc;64

output:
1;Angyal Pofa;
2;Cukor Falat;Eros Pista;
2;Bozontos Beata;Dohongo Diana;
1;Fickos Ferenc;


#include <iostream>
#include <string>
#include <istream>
using namespace std;

int main()
{
    int n, total_points;
    cin >> n >> total_points;

    string name[n];
    int points[n];
    string a;

    for(int i = 0; i < n; i++)
    {
        getline(cin,a);
        getline(cin, name[i], ';');
        cin >> points[i];
    }

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int cnt4 = 0;
    for(int i = 0; i < n; i++)
    {
        if(points[i] > total_points*0.89)
        {
            cnt1 += 1;
        }
        else if(points[i] > total_points*0.79 && points[i] < total_points*0.90)
        {
            cnt2 += 1;
        }
        else if(points[i] > total_points*0.69 && points[i] < total_points*0.80)
        {
            cnt3 += 1;
        }
        else
        {
            cnt4 += 1;
        }
    }
    cout << cnt1 << ";";
    for(int i = 0; i < n; i++)
    {

        if(points[i] > total_points*0.89)
        {
            cout << name[i] << ";";
        }
    }
    cout <<  '\n'  <<cnt2 << ";";
    for (int i = 0; i < n; i++)
    {
        if(points[i] > total_points*0.79 && points[i] < total_points*0.90)
        {
            cout << name[i] << ";";
        }
    }
    cout << '\n' << cnt3 << ";";
    for (int i = 0; i < n; i++)
    {
        if (points[i] > total_points*0.69 && points[i] < total_points*0.80)
        {
            cout << name[i] << ";";
        }
    }
    cout << '\n' << cnt4 << ";";
    for (int i = 0 ; i < n; i++)
    {
        if (points[i] < total_points*0.70)
        {
            cout << name[i] << ";";
        }
    }


}
