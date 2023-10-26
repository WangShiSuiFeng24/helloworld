#include <iostream>
#include <algorithm>
#include <string>

template <class T>
int reduce(T ar[], int n);

int main()
{
    long arl[5] = {45000, 3400, 45000, 100000, 2500};

    int resize = reduce(arl, 5);

    std::cout << "array1: \n";
    for (int i = 0; i < resize; ++i)
        std::cout << arl[i] << ' ';

    std::string ar2[6] = {"it", "aboard", "it", "zone", "quit", "aa"};
    resize = reduce(ar2, 6);

    std::cout << "\narray2: \n";
    int i;
    for (i = 0; i < resize; ++i)
        std::cout << ar2[i] << ' ';

        return 0;
}

template <typename T>
int reduce(T ar[], int n)
{
    std::sort(ar, ar + n);
    return std::unique(ar, ar + n) - ar;
}