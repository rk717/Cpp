#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct
{
    string name;
    int age;
    string city;
} Person;

int main()
{
    //input variables
    int N;
    //output
    int count;
    //for error handling
    bool error;
    do
    {
        cout << "How much element is in your database? (positive integer)" << endl;
        cin >> N;

        error = cin.fail() || cin.peek() != '\n' || N <= 0;
        if (error)
        {
            cout << "You have entered an invalid input" << endl;

        }
        cin.clear();
        cin.ignore(999, '\n');
    }while(error);

    Person people[N]; //declare the input array
    Person from_Budapest[N]; //declare the output array
    for (int i = 0; i < N; i++)
    {
        getline(cin, people[i].name, ';');
        getline(cin, people[i].city, ';'); //; we are not finish yet
        string tmp;
        getline(cin, tmp, '\n');  //in the getline, it is string  // \n means end of the line   20
        people[i].age = atoi(tmp.c_str());   // here we convert the string to the integer...

    }

    for (int i = 0; i < N; i++)
    {
        if (people[i].city == "Budapest")
        {
            cout << people[i].city << people[i].age << people[i].name << endl;
        }
    }

    return 0;



}
