#include <iostream>
#include <ctime>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

const int LENGTH = 1000000;

int main()
{
    vector<int> vi0;

    srand(time(0));

    for (int i = 0; i < LENGTH; ++i)
        vi0.push_back(rand() % 1000);

    vector<int> vi(vi0);
    list<int> li(vi0.begin(), vi0.end());

    clock_t time = clock();
    sort(vi.begin(), vi.end());
    time = clock() - time;

    cout << "Time used sort by vector.sort(): ";
    cout << (double)(time) / CLOCKS_PER_SEC << " second" << endl;

    time = clock();
    li.sort();
    time = clock() - time;

    cout << "Time used sort by list.sort(): ";
    cout << (double)(time) / CLOCKS_PER_SEC << " second" << endl;

    //
    li.assign(vi0.begin(), vi0.end());
    time = clock();
    vi.assign(li.begin(), li.end());
    sort(vi.begin(), vi.end());
    li.assign(vi.begin(), vi.end());
    time = clock() - time;

    cout << "Time used by generic sort: ";
    cout << (double)(time) / CLOCKS_PER_SEC << " second" << endl;

    return 0;
}