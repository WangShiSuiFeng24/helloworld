// compile with sales.cpp
#include <iostream>
#include "sales.h"

using namespace SALES;
int main()
{
    double de[QUARTERS] =
        {12, 23, 45, 67};
    Sales s1(de, QUARTERS);
    Sales s2;
    s1.showSales();
    s2.showSales();

    return 0;
}