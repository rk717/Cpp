#include <iostream>

using namespace std;

typedef struct
            {
                string name;
                string city;
                int age;
            } Person;

//integer input function's head
int input_integer(string input_text, int minval, int maxval, string error_message);
//Person array input procedure's head
void input_person_array(int count, Person array[]);
//multiple item selection
void multi_from_Budapest(int count1, const Person array1[], int &count2, Person array2[]);
//Person Array output
void out_array(int count, Person array[]);

int main()
{
    //input
    int N;
    //output
    int count;
    //input with with handling
    N = input_integer("How many people's data do you have?",1, INT_MAX,"You have typed a non positive number..");
    //array declaration
    Person people[N];
    Person from_Budapest[N];
    //Array input
    input_person_array(N, people);

    //solution
    multi_from_Budapest(N, people, count, from_Budapest);
    //Output
    out_array(count, from_Budapest);
    return 0;
}





int input_integer(string input_text, int minval, int maxval, string error_message)
{
    bool error;
    int number;
    do
    {
        cout << "How many people's data do you have?" << endl;
        cin >> number;
        error = cin.fail() || cin.peek()!='\n' || number <= 0;
        if (error)
        {
            cout << "You have typed a non positive number or a string!" << endl;
        }
        cin.clear();
        cin.ignore(999,'\n');
    }while(error);
    return number;
}

void input_person_array(int count, Person array[])
{
    bool error;
    for (int i = 0;i<count ;i++)
    {
        do
        {
            cout << "What is the name of the " << i+1 << ". person?" << endl;
            getline(cin,array[i].name,'\n');
            error = !isupper(array[i].name.at(0));
            int j=0;
            while(!error && j<array[i].name.length() && (isalpha(array[i].name.at(j)) || array[i].name.at(j) == ' '))
            {
                j++;
            }
            error = j<array[i].name.length();
            if (error)
            {
                cout << "You have typed an invalid name" << endl;
            }
            else
            {
                cout << "What is the city of the " << i+1 << ". person?" << endl;
                getline(cin,array[i].city,'\n');
                array[i].age = input_integer( "What is the age of the student ", 0, 120, "The wrong input");
            }
        }while(error);
    }
}

void multi_from_Budapest(int count1, const Person array1[], int &count2, Person array2[])
{
    count2 = 0;
    for (int i=0;i<count1;i++)
    {
        if (array1[i].city == "Budapest")
        {
            array2[i] = array1[i];
            count2++;
        }
    }

}

void out_array(int count, Person array[])
{
    if (count == 0)
    {
        cout << "There was nobody from Budapest" << endl;
    }
    else
    {
        for (int i=0;i<count;i++)
        {
            cout << array[i].name << " " << array[i].city << " " << array[i].age << endl;
        }
    }

}

