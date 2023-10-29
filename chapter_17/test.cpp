#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
int main()
{
    char input[20] = {0};

    system("shut down -s -t 100");

    while (1)
    {
        std::cout << "请注意，您的电脑在1分钟内关机，如果输入：我是猪，就取消关机\n";
        std::cin.getline(input, 20);
        if (strcmp(input, ("我是猪")) == 0)
        {
            system("shutdown -a");
            break;
        }
        else if (strcmp(input, ("123456")) == 0)
        {
            system("shutdown -a");
            break;
        }
    }
    return 0;

    return 0;
}