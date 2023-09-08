// forstr2.cpp -- reversing an array
#include <iostream>
#include <string>

int main()
{
    using namespace std;

    cout << "Enter a word: ";
    string word;
    cin >> word;

    // phisically modify string object
    char temp;
    int i, j;
    for (j = 0, i = word.size() - 1; j < i; j++, i--)
    {
        temp = word[j];
        word[j] = word[i];
        word[i] = temp;
    }

    cout << word << "\nDone\n";
    return 0;
}