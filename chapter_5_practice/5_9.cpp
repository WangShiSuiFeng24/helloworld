#include <iostream>
#include <string>

using namespace std;
const int SIZE = 20;
const string FINISHED = "done";

int main()
{
    int count = 0;
    string word;

    cout << "Enter words (to stop, type the word done):" << endl;
    cin >> word;
    while (word != FINISHED)
    {
        ++count;
        cin >> word;
    }
    cout << "You entered a total of " << count << " words";
    return 0;
}