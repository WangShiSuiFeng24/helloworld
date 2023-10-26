#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);

using namespace std;

int main()
{
    
    // char ar[] = "qwertyuiopasdfghjklzxcvbnm";
    long ar[] = {9, 9, 8, 8, 3, 3, 4, 4, 2, 2, 1, 1, 1, 7, 7, 6, 5, 5};
    // reduce(ar, sizeof(ar));
    cout << "sizeof(ar) = " << sizeof(ar) << endl;
    int elements = reduce(ar, 18);

    for (int i = 0; i < elements; ++i)
        cout << ar[i] << ' ';

    return 0;
}

int reduce(long ar[], int n)
{
    sort(ar, ar + n);
    return unique(ar, ar + n) - ar;
}