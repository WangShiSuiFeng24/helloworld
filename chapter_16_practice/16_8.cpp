#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<string> Mat_set, Pat_set, Guest_set;

    cout << "Enter Mat's friends(q to quit): ";
    string name;

    while (getline(cin, name) && name != "q")
    {
        Mat_set.insert(name);
        cout << name << " add to Mat's list. (q to quit): ";
    }

    cout << "\nMat's friends are: \n";
    for (auto pd = Mat_set.begin(); pd != Mat_set.end(); pd++)
        cout << *pd << ' ';

    cout << endl;
    cout << endl;
    cout << "Enter Pat's friends(q to quit): ";
    while (getline(cin, name) && name != "q")
    {
        Pat_set.insert(name);
        cout << name << "add to Pat's list. (q to quit): ";
    }

    cout << "\nPat's friends are: \n";
    for (auto pd = Pat_set.begin(); pd != Pat_set.end(); ++pd)
        cout << *pd << " ";

    Guest_set.insert(Mat_set.begin(), Mat_set.end());
    Guest_set.insert(Pat_set.begin(), Pat_set.end());

    cout << "\nAll friends are:\n";
    for (auto pd = Guest_set.begin(); pd != Guest_set.end(); ++pd)
        cout << *pd << " ";

    return 0;
}