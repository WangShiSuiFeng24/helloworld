// hangman.cpp -- some string methods
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <fstream>
#include <vector>
#include <exception>
using std::string;
const int NUM = 26;

const string wordlist0[NUM] =
    {
        "apiary", "beetle", "cereal",
        "danger", "ensign", "florid",
        "garage", "health", "insult",
        "jackal", "keeper", "loaner",
        "manage", "nonce", "onset",
        "plaid", "quilt", "remote",
        "stolid", "train", "useful",
        "valid", "whence", "xenon",
        "yearn", "zippy"};
    
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::tolower;

    std::srand(std::time(0));

    string file = "words.txt";

    using std::ofstream;
    ofstream fout;
    // try {
        fout.open(file);
    // }
    // catch (std::exception e)
    // {
    //     cout << "Can't open file " << file << " ." << endl;
    // }
    for (int i = 0; i < NUM; ++i)
    {
        fout << wordlist0[i];
        if (i % 6 == 5)
            fout << endl;
        else
            fout << ' ';
    }
    if (NUM % 6 != 0)
        fout << endl;

    fout.close();

    using std::ifstream;
    using std::vector;
    ifstream fin;
    // try {
        fin.open(file);
        if (!fin)
        {   
            cout << "Can't open file " << file << " ." << endl;
            exit(EXIT_FAILURE);
        }
    // }
    // catch (std::exception e)
    // {   
    //     cout << "Can't open file " << file << " ." << endl;
    //     exit(EXIT_FAILURE);
    // }
    vector<string> wordlist;
    string temp;
    while (fin >> temp)
        wordlist.push_back(temp);
    fin.close();

    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);

    while (play == 'y')
    {
        string target = wordlist[std::rand() % NUM];

        int length = target.length();

        string attempt(length, '-');
        string badchars;

        int guesses = 6;

        cout << "Guess my secret word. It has " << length
             << " letters, and you guess\n"
             << "one letter at a time. You get " << guesses
             << " wrong guesses.\n";

        cout << "Your word: " << attempt << endl;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;

            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);

            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;

                loc = target.find(letter, loc + 1);

                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt << endl;

            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }

        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";
            cout << "Will you play another? <y/n> ";
            cin >> play;
            play = tolower(play);
    }
    cout << "Bye\n";
    return 0;
}