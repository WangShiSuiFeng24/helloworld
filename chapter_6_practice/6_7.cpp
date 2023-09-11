#include <iostream>
#include <cctype>
#include <string>
int main()
{
    using namespace std;

    string word;
    int o_count = 0;
    int v_count = 0;
    int c_count = 0;
    cout << "Enter words (q to quit): \n";
    while (cin >> word && word != "q")
    {
        if (!isalpha(word[0]))
            ++o_count;
        else
            switch(word[0])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    ++v_count;
                    break;
                default:
                    ++c_count;
                    break;
            }
    }

    cout << v_count << " words beginning with vowels\n";
    cout << c_count << " words beginning with consonants\n";
    cout << o_count << " others" << endl;

    return 0;
}