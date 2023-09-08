// formore.cpp -- more looping with for
#include <iostream>
const int ArSize = 22;  // example of external declaration
int main()
{
    long long factorials[ArSize];
    factorials[0] = 1LL;
    int i;
    for (i = 1; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];

    for (i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;

    return 0;
}