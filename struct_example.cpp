#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct StuInf
{
    string name;
    int age;
    string place;
}stu [3];

void printstu (StuInf stu);

int main()
{
    string mystr;
    int n;


    for (n = 0; n < 3; n++)
    {
        cout << "Enter the name: ";
        getline(cin, stu[n].name);

        cout << "Enter year: ";
        getline(cin, mystr);
        stringstream(mystr) >> stu[n].age;

        cout << "Enter the Place: ";
        getline(cin, stu[n].place);
    }

    cout << "You have entered these students: \n";
    for (n = 0; n < 3; n++)
        printstu(stu[n]);
    return 0;

}

void printstu(StuInf stu)
{
    cout << stu.name;
    cout << stu.age << endl;
    cout << stu.place << endl;
}
