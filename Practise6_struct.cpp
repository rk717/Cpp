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
    //For error check
    bool error;
    //input
    int N;
    //output
    int count;
    //input the size of the array
    do
    {
        cout << "How many people are in the database: (positive integer)?" << endl;
        cin >> N;
        error = cin.fail() || cin.peek() != '\n' || N <= 0;
        if (error)
        {
            cout << "You have type a string or a non positive number" << endl;
        }
        cin.clear();
        cin.ignore(999,'\n');
    }while (error);
    //array declaration
    Person people[N];
    //Input people array
    for (int i = 0; i < N; i++)
    {
        do
        {
            cout << "Please add the " << i+1 << " person's name!";
            getline(cin, people[i].name, '\n');
            error = islower(people[i].name.at(0)); //first character name should be Capital letter
            int j = 0;
            while (!error && j < people[i].name.length() && (isalpha(people[i].name.at(j)) || people[i].name.at(j) == ' ' )) //the j
            {
                j++;
            }
            error = j < people[i].name.length(); //if array stop before the end
            if (!error)
            {
                cout << "Where does this person live?" << endl;
                getline(cin, people[i].city, '\n');
                cout << "How old is this person (0 <= age <= 120)" << endl;
                cin >> people[i].age;
                error = cin.fail() || cin.peek() != '\n' || people[i].age < 0 || people[i].age > 120;
                if(error)
                {
                    cout << "You have typed an invalid age!" << endl;
                }
                cin.clear();
                cin.ignore(999,'\n');
            }
            else
            {
                cout << "You have typed an invalid name" << endl;
            }


        }while(error);
    }




    return 0;
}
