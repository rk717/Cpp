#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct
{
    string animal;
} animals;

int main()
{


    int countB;
    int countV;
    //output
    int CountBoth = 0;
    bool error;
    do
    {
        cout << "How many animals are in the Budapest: " << endl;
        cin >> countB;
        cout << "How many animals are in the Vesprem: "  << endl;
        cin >> countV;

        error = cin.fail() || cin.peek() != '\n' || countB <= 0 || countV <= 0;
        if (error)
        {
            cout << "You have entered an invalid input" << endl;

        }
        cin.clear();
        cin.ignore(999, '\n');
    }while(error);

    animals Budapest[countB]; //declare the input array
    animals Vesprem[countV];
    int sizeb;  //the both[] array size.
    if (countB > countV)
    {
        sizeb = countV;
    }
    else
    {
        sizeb = countB;
    }
    animals both[sizeb]; //declare the output array



    cout << "Please input the animals name in Budapest: " << endl;
    int i = 0;
    for (i = 0; i < countB; i++)
    {
        getline(cin, Budapest[i].animal, '\n');
    }

    cout << "Please input the animals name in Vesprem: " << endl;
    int j = 0;
    for (j = 0; j < countV; j++)
    {
        getline(cin, Vesprem[j].animal, '\n');
    }

    cout << "The animals from the both Zoos are: " << endl;
    for (i = 0; i < countB; i++)
    {
        j = 0;
        while (j < countV && (Budapest[i].animal != Vesprem[j].animal))
        {
            j += 1;
        }
        if(j < countV)
        {
            both[CountBoth].animal = Budapest[i].animal;
            CountBoth += 1;

        }

    }


    for(i = 0; i< CountBoth; i++)
    {
        cout << both[i].animal <<endl;
    }



}
