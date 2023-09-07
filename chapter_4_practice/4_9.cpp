#include <iostream>
#include <cstring>
using namespace std;

struct Candybar
{
    char brand[20];
    float weight;
    unsigned int calories;
};

int main()
{
    Candybar *pc = new Candybar[3];

    strcpy(pc[0].brand, "Mocha, Munch");
    pc[0].weight = 2.3;
    pc[0].calories = 350;

    // ...
    delete[] pc;
}