#include <iostream>
using namespace std;
void menu(void);
int main()
{

    char ch;

    menu();

    while (cin.get(ch))
    {
        switch (ch)
        {
            case 'c':
                break;
            case 'p':
                break;
            case 't':
                cout << "A maple is a tree.\n";
                break;
            case 'g':
                break;
            default:
                cout << "Please enter a c, p, t, or g: ";
                if (ch != '\n')
                    while (cin.get() != '\n')
                        continue;
                continue;
        }
        while (cin.get() != '\n')
                continue;
        menu();
    }
    return 0;
}

void menu(void)
{
    cout << "Please enter one of the following choice: \n"
         << "c) carnivore          p) pianist\n"
         << "t) tree               g) game\n";
}