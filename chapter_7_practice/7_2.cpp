#include <iostream>

using namespace std;
const int SIZE = 10;
int set_mark(int[], int);
void display_mark(int[], int);
double average_mark(int[], int);
int main()
{
    int mark[SIZE];

    int marked_num = set_mark(mark, SIZE);
    display_mark(mark, marked_num);

    double average = average_mark(mark, marked_num);
    cout << "The average of mark is " << average << endl;

    return 0;
}

int set_mark(int arr[], int size)
{
    cout << "Enter the golf marks(q to quit): ";
    int i;
    for (i = 0; i < size; ++i)
    {
        cin >> arr[i];
        if (cin.fail())
            break;
        if (i < size-1)
            cout << "Next mark: ";
    }
    cout << endl;
    return i;
}

void display_mark(int arr[], int size)
{
    cout << "The marks is bellow: " << endl;
    for (int i = 0; i < size; ++i)
        cout << arr[i] << "\t";
    cout << endl;
}

double average_mark(int arr[], int size)
{
    double sum;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return sum / size;
}