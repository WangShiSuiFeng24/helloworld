#include <iostream>
using namespace std;
template <typename T>
T max5(T[]);

int main()
{
    int arr[5] = {1, 2, 5, 4, 3};
    double arr_d[5] = {19.6, 13, 19.8, 100.8, 98.4};
    cout << "The Max Element of int array: " << max5(arr) << endl;
    cout << "The Max Element of double array: " << max5(arr_d) << endl;

    return 0;
}

template <typename T>
T max5(T arr[])
{
    T max = arr[0];
    for (int i = 1; i < 5; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}