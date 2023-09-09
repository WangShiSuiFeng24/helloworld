#include <iostream>
const char *months[12] =
    {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main()
{
    using namespace std;
    int input[12];
    int sum = 0;
    for (int i = 0; i < 12; ++i)
    {
        cout << "Enter the number of sale mount in " << months[i] << ": ";
        cin >> input[i];
        sum += input[i];
    }
    cout << "Total sale " << sum << " this year." << endl;
    return 0;
}