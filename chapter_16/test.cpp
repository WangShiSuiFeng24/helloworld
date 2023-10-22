#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[], char *envp[])
{
    for (int i = 0; i < argc; ++i)
    {
        printf("%s\n", argv[i]);
    }

    for (int i = 0; i < argc; ++i)
    {
        printf("%s\n", envp[i]);
    }

    cout << __cplusplus << endl;

    return 0;
}