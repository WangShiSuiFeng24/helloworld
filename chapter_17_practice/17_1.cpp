#include <iostream>

int main()
{
    char ch;

    int count = 0;

    while ((ch = std::cin.peek()) != '$')
    {
        std::cin.get(ch);
        count++;
    }

    std::cout << count << " chars.\n";
    return 0;
}