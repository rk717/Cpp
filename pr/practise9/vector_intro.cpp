#include <iostream>
#include <vector>//Needed for Vector type
#include <algorithm>//Needed for sort

using namespace std;

typedef struct
        {
            string name;
            int point;
        }contestant;

void input_vector(vector <float> &array);//parameter handling by reference
void output_vector(vector <float> array);//parameter handling by value

int main()
{
    //Declaration
    vector <int> int_array;
    vector <float> float_array;
    vector <contestant> contestants;//Type defined by us
    //Initialization
    vector <int> numbers(5);//Five initialized element
    for (int i=0; i<numbers.size(); i++)//.size() size/count of array
    {
        cout << numbers[i] << " ";
    }
    cout << endl;// Output is five 0
    vector <int> numbers2;//No initialization
    numbers2.reserve(5);//Five reserved element, but not initialized
    for (int i=0; i<numbers2.size(); i++)
    {
        cout << numbers2[i] << " ";
    }
    cout << endl;//"Nothing" is the output, because size is 0
    //Difference between Capacity and size
    cout << numbers2.size() << endl;//0
    cout << numbers2.capacity() << endl;//5
    numbers2.push_back(1);//Add one element to the array
    cout << numbers2.size() << endl;//1
    cout << numbers2.capacity() << endl;//5
    numbers2.resize(3);//WE decrease its size to 3
    cout << numbers2.size() << endl;//3
    cout << numbers2.capacity() << endl;//5
    for (int i=0; i<numbers2.size(); i++)
    {
        cout << numbers2[i] << " ";
    }
    cout << endl;//1 0 0 (resize initializes the uninitialized elements)
    numbers2.resize(6,22);//we fill the uninitialized elements with 22
    for (int i=0; i<numbers2.size(); i++)
    {
        cout << numbers2[i] << " ";
    }
    cout << endl;//1 0 0 (resize initializes the uninitialized elements)
    //Outindexing
    cout << numbers2[numbers2.size()] << endl;//C++ allows it... :(
    //cout << numbers2.at(numbers2.size()) << endl;//C++ does not allow it... :)
    /*terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 6) >= this->size() (which is 6) */
    //Input vector
    int count = 6;
    int element;
    for (int i=0; i<count; i++)
    {
        cin >> element;
        int_array.push_back(element);
    }
    for (int i=0; i<int_array.size(); i++)
    {
        cout << int_array[i] << " ";
    }
    cout << endl;
    //Referencing, giving value
    cout << int_array[2] << endl;
    int_array[2] = 100;
    cout << int_array[2] << endl;
    //First element
    cout << int_array.front() << endl;
    cout << int_array[0] << endl;
    cout << int_array.at(0) << endl;
    //Last element
    cout << int_array.back() << endl;
    cout << int_array[int_array.size()-1] << endl;
    cout << int_array.at(int_array.size()-1) << endl;
    //Deleting the elements
    //Delete last element
    int_array.pop_back();
    cout << int_array.back() << endl;
    //Using as parameter
    input_vector(float_array);
    output_vector(float_array);
    //Sorting array, from the first element to the last element
    sort(float_array.begin(),float_array.end());//Will not work for normal array
    output_vector(float_array);
    return 0;
}

void input_vector(vector <float> &array)//parameter handling by reference
{
    int count;
    float element;
    cout << "How many elements are in the array? " << endl;
    cin >> count;
    for (int i=0;i<count;i++)
    {
        cout << "Please type the " << i+1 << ". element: " << endl;
        cin >> element;
        array.push_back(element);
    }
}

void output_vector(vector <float> array)//parameter handling by value
{
    for (int i=0;i<array.size();i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

