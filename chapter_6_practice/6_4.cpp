#include <iostream>
using namespace std;

const int strsize = 20;
const int group_size = 5;
struct bop{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

void showmenu(void);
void display_by_name(bop *pg, int size);
void display_by_title(bop *pg, int size);
void display_by_bopname(bop *pg, int size);
void display_by_preference(bop *pg, int size);

int main()
{
    bop group[] = {
        {"Wimp Macho",
         "",
         "",
         0},
        {"Raki Rhodes",
         "Junior Programmer",
         "",
         1},
        {"Celia Laiter",
         "",
         "MIPS",
         2},
        {"Hoppy Hipman",
         "Analyst Trainee",
         "",
         1},
        {"Pat Hand",
         "",
         "LOOPY",
         2}};

    char ch;
    showmenu();

    while (cin.get(ch))
    {
        switch (ch)
        {
            case 'a':
                display_by_name(group, group_size);
                break;
            case 'b':
                display_by_title(group, group_size);
                break;
            case 'c':
                display_by_bopname(group, group_size);
                break;
            case 'd':
                display_by_preference(group, group_size);
                break;
            case 'q':
                cout << "Bye!\n";
                exit(EXIT_SUCCESS);
            default:
                cout << "Please enter a a, b, c, d, or q: ";
                if (ch != '\n')
                {
                    while (cin.get() != '\n')
                        continue; 
                }
                continue;
        }
        while (cin.get() != '\n')
            continue;
        showmenu();
    }

    return 0;
}

void showmenu(void)
{
    cout << "a. diplay by name      b. diplay by title\n"
         << "c. diplay by bopname   d. diplay by preference\n"
         << "q. quit\n";
}

void display_by_name(bop * bg, int size)
{
    for (int i = 0; i < size; i++)
        cout << bg[i].fullname << endl;
}

void display_by_title(bop * bg, int size)
{
    for (int i = 0; i < size; i++)
        cout << bg[i].title << endl;
}

void display_by_bopname(bop * bg, int size)
{
    for (int i = 0; i < size; i++)
        cout << bg[i].bopname << endl;
}

void display_by_preference(bop * bg, int size)
{
    for (int i = 0; i < size; i++)
    {
        switch (bg[i].preference)
        {
            case 0:
                cout << bg[i].fullname << endl;
                break;
            case 1:
                cout << bg[i].title << endl;
                break;
            case 2:
                cout << bg[i].bopname << endl;
                break;
        }
    }
}