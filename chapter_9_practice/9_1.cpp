#include <iostream>
#include "golf.h"
int main()
{
    using namespace std;
    golf ann;
    setgolf(ann, "AnnBirdfree", 24);

    golf andy;
    setgolf(andy);

    showgolf(ann);
    showgolf(andy);

    return 0;
}