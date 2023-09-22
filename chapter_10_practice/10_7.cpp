#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 19;
class Plorg
{
private:
    char name[SIZE];
    int CI;
public:
    Plorg(const char st[] = "Plorga", int ci = 50);
    ~Plorg();

    void reset_ci(int n);
    void print_info() const;
};

Plorg::Plorg(const char st[], int ci)
{
    strcpy(name, st);
    CI = ci;
}

Plorg::~Plorg()
{

}

void Plorg::reset_ci(int n)
{
    CI = n;
}

void Plorg::print_info() const
{
    cout << "plorg name: " << name << ", CI = " << CI << endl;
}

int main()
{
    Plorg pl;
    pl.print_info();

    pl.reset_ci(98);
    pl.print_info();

    Plorg pm("Stenom", 87);
    pm.print_info();

    return 0;
}
