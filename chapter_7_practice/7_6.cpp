#include <iostream>
using namespace std;

int Fill_array(double[], int);
void Show_array(const double[], int);
void Reverse_array(double[], int);
const int SIZE = 20;
int main()
{
    double Array[SIZE];

    int size = Fill_array(Array, SIZE);
    Show_array(Array, size);
    Reverse_array(Array, size);
    Show_array(Array, size);
    Reverse_array(Array + 1, size - 2);
    Show_array(Array, size);

    return 0;
}

int Fill_array(double arr[], int size)
{
    int i;
    double temp;
    cout << "Enter the number seperate by blank(q to stop): ";
    for (i = 0; i < size; ++i)
    {
        cin >> temp;
        if (cin.fail())
            break;
        arr[i] = temp;
    }
    return i;
}

void Show_array(const double arr[], int size)
{
    cout << "The array's data: " << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void Reverse_array(double arr[], int size)
{
    int i = 0;
    int j = size - 1;
    double temp;
    while (i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        ++i;
        --j;
    }
}