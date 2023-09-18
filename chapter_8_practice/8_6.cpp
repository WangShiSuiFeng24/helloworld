#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T maxn(T[], int n);

template <>
char *maxn(char *[], int n);

int main()
{
    int arr[5] = {1, 2, 5, 4, 3};
    double arr_d[5] = {19.6, 13, 19.8, 100.8, 98.4};
    string ss[] = {"Hello", "Hello World!"};

    cout << "The Max Element of int array: " << maxn(arr, 5) << endl;
    cout << "The Max Element of double array: " << maxn(arr_d, 5) << endl;
    cout << "The Max Element of string: " << maxn(ss, 2) << endl;

    return 0;
}

template <typename T>
T maxn(T st[], int n)
{
    T max = st[0];
    for (int i = 0; i < n; ++i)
        if (st[i] > max)
            max = st[i];
    return max;
}

template <>
char * maxn(char *sst[], int n)
{
    int pos;
    for (int i = 0; i < n; ++i)
        if (strlen(sst[pos]) < strlen(sst[i]))
            pos = i;
    return sst[pos];
}