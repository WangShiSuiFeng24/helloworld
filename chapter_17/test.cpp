#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
int main()
{
    char philo[20];
    int distance;
    char initial;

    std::cin >> philo >> distance;
    initial = std::cin.get();

    std::cout << philo << std::endl
              << distance << std::endl
              << "\"" << initial << "\"";

    return 0;
}