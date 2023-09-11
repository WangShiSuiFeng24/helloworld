#include <iostream>
#include <array>

int main()
{
    using namespace std;
    array<double, 10> donation;

    double input;
    double sum = 0.0;
    int count = 0;
    double average = 0.0;

    cout << "Enter 10 double values: ";
    while (count < 10 && cin >> donation[count])
    {
        sum += donation[count];
        ++count;
    }

    if (count == 0)
        cout << "No proper input!\n";
    else
    {
        average = sum / count;
        int value_than_average_count = 0;
        for (int i = 0; i < count; ++i)
        {
            if (donation[i] > average)
                ++value_than_average_count;
        }

        cout << "The average of the " << count << " double values is " << average << ".\n";
        cout << "The value in array bigger than average count is " << value_than_average_count;
    }
    return 0;
}