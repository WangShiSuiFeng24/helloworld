#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    int count = 0;
    char word[20];

    cout << "Enter words (to stop, type the word done):" << endl;
    cin >> word;
    while (strcmp(word, "done"))
    {
        ++count;
        cin >> word;
    }
    cout << "You entered a total of " << count << " words";
    return 0;
}