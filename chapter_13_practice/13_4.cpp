#include <iostream>
#include "vintageport.h"

int main()
{
    using namespace std;

    VintagePort vp1("alibaba", 10, "yuan bro", 1991);
    VintagePort vp2("tencent", 20, "xing bro", 1993);

    vp1.Show();
    vp2.Show();

    return 0;
}