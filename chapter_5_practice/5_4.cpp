#include <iostream>
const float DEPOSIT_BASE = 100;
int main()
{
    using namespace std;
    float sum_of_Daphne, sum_of_Cleo;
    sum_of_Daphne = sum_of_Cleo = DEPOSIT_BASE;

    int count_year = 0;
    while (sum_of_Daphne >= sum_of_Cleo)
    {
        sum_of_Daphne += DEPOSIT_BASE * 0.10;
        sum_of_Cleo += sum_of_Cleo * 0.05;
        count_year++;
    }

    cout << "In " << count_year << " year: Daphne = " << sum_of_Daphne << endl;
    cout << "\tCleo = " << sum_of_Cleo << endl;
    return 0;
}