#include <iostream>
struct CandyBar
{
    char brand[20];
    float weight;
    unsigned int calorie;
};

int main()
{
    using namespace std;

    CandyBar snack =
        {
            "Mocha Munch",
            2.3,
            350
        };

    cout << "My favorite Candy is " << snack.brand << "." << endl;
    cout << "And its weight is " << snack.weight << ", calories is " << snack.calorie;
    cout << "." << endl;

    return 0;
}