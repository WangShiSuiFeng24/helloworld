#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> Lotto(int, int);

int main()
{
    vector<int> winners;

    winners = Lotto(51, 6);
    vector<int>::iterator pd;

    cout << "winners: \n";
    for (pd = winners.begin(); pd != winners.end(); ++pd)
        cout << *pd << " ";
    return 0;
}

vector<int> Lotto(int dot, int sdot)
{
    vector<int> result, temp;

    srand(time(0));

    for (int i = 0; i < sdot; ++i)
    {
        for (int j = 0; j < dot; ++j)
            temp.push_back(rand() % dot + 1);

        random_shuffle(temp.begin(), temp.end());

        result.push_back(*temp.begin());
    }
    return result;
}