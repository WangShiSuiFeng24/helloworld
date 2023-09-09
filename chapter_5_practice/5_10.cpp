#include <iostream>

int main()
{
    using namespace std;

    int i, j, k;
    int rows;
    cout << "Enter the number of rows:";
    cin >> rows;

    for (i = 0; i < rows; ++i)
    {
        for (j = rows - i - 1; j > 0; --j)
            cout << ".";
        for (k = 0; k < i + 1; k++)
            cout << "*";
        cout << endl;
    }

    return 0;
}