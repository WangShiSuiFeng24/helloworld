#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    cout << "hello world!";

    cout << 160 << endl;
    cout << -0xffff << endl;
    cout << 011 << endl;

    cout << 'W' << endl;

    long ll = 560031841;
    cout.write((char *)&ll, 4);

    return 0;
}