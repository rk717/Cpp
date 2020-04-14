#include <iostream>

using namespace std;

typedef struct
            {
                string name;
                string city;
                int age;
            } Person;

int main()
{
    //error handling
    bool error;
    //Input
    int N;
    //output
    int count;
    //input with error handling
    do
    {
        cout << "How many people's data do you have?" << endl;
        cin >> N;
        error = cin.fail() || cin.peek()!='\n' || N<=0;
        if (error)
        {
            cout << "You have typed a non positive number or a string!" << endl;
        }
        cin.clear();
        cin.ignore(999,'\n');
    }while(error);
    //Array declaration
    Person people[N];
    Person from_Budapest[N];
    //Array input
    for (int i = 0;i<N;i++)
    {
        do
        {
            cout << "What is the name of the " << i+1 << ". person?" << endl;
            getline(cin,people[i].name,'\n');
            error = !isupper(people[i].name.at(0));
            int j=0;
            while(!error && j<people[i].name.length() && (isalpha(people[i].name.at(j)) || people[i].name.at(j) == ' '))
            {
                j++;
            }
            error = j<people[i].name.length();
            if (error)
            {
                cout << "You have typed an invalid name" << endl;
            }
            else
            {
                cout << "What is the city of the " << i+1 << ". person?" << endl;
                getline(cin,people[i].city,'\n');
                do
                {
                    cout << "What is the age of the " << i+1 << ". person?" << endl;
                    cin >> people[i].age;
                    error = cin.fail() || cin.peek()!='\n' || people[i].age<0 || people[i].age > 120;
                    if (error)
                    {
                        cout << "Invalid age!" << endl;
                    }
                    cin.clear();
                    cin.ignore(999,'\n');
                }while(error);
            }
        }while(error);
    }
    //Solution
    count = 0;
    for (int i=0;i<N;i++)
    {
        if (people[i].city == "Budapest")
        {
            from_Budapest[count] = people[i];
            count++;
        }
    }
    //Output
    if (count == 0)
    {
        cout << "There was nobody from Budapest" << endl;
    }
    else
    {
        for (int i=0;i<count;i++)
        {
            cout << from_Budapest[i].name << " " << from_Budapest[i].city << " " << from_Budapest[i].age << endl;
        }
    }
    return 0;
}
