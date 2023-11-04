#include <iostream>
#include <fstream>
int main(int argc, char *argv[])
{
    using namespace std;
    char ch;

    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " srcfile desfile" << endl;
        exit(EXIT_FAILURE);
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    if (!fin.is_open())
    {
        cerr << "Can't open the file " << argv[1] << " !" << endl;
        exit(EXIT_FAILURE);
    }
    if (!fout.is_open())
    {
        cerr << "Can't open the file " << argv[2] << " !" << endl;
        exit(EXIT_FAILURE);
    }

    while (fin.get(ch))
        fout << ch;

    fin.close();
    fout.close();

    return 0;
}