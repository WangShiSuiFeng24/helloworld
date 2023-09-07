#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<float, 3> record_list;

    float average;

    cout << "Please input three record of 40 miles.\n";
    cout << "First record:";
    cin >> record_list[0];
    cout << "Second record:";
    cin >> record_list[1];
    cout << "Third record:";
    cin >> record_list[2];

    cout << "Ok, you input:\n1." << record_list[0] << "\n2." << record_list[1] << "\n3."
         << record_list[2] << endl;

    average = (record_list[0] + record_list[1] + record_list[2]) / 3;
    cout << "Congratulate, your average performance is " << average << ".";

    return 0;
}