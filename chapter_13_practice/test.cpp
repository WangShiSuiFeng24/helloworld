#include <iostream>
#include <limits>
using namespace std;
int main()
{
    char *playerName = "Ki";
    int minMove = 1;
    int maxMove = 15;
    int playerMove;
    bool validInput = false;
    do
    {
        cout << playerName << ", you may take " << minMove << " to " << maxMove << " marbles." << endl;
        cout << "You take: ";

        if (cin >> playerMove)
        {
            if (playerMove < minMove || playerMove > maxMove)
                cout << "0oops, the number you choose is not in the correct range." << endl;
            else
            {
                validInput = true;
                cout << "You will take " << playerMove << " marbles." << endl;
                //pileSize -= playerMove;
            }
            while (cin.get() != '\n')
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid! PLease try again. " << endl;
        }
    } while (!validInput); 
}