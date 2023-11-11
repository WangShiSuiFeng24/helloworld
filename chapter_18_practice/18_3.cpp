#include <iostream>

long double sum_value() { return 0; }

template <typename T, typename... Args>
long double sum_value(T value, Args... args)
{
    long double sum = (long double)value + (long double)sum_value(args...);
    return sum;
}

int main()
{
    using namespace std;
    cout << sum_value(52, 34, 98, 101) << endl;
    cout << sum_value('x', 'y', 95, 74, 'Z') << endl;
    cout << sum_value(0.2, 1e2, 54, 'M', '\t') << endl;

    return 0;
}