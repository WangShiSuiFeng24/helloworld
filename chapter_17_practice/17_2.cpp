#include <iostream>
#include <fstream>
int main(int argc, char * argv[])
{
    using std::cerr;
    using std::cin;
    int ch;

    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " filename[s]" << std::endl;
        exit(EXIT_FAILURE);
    }

    using std::ofstream;
    ofstream fout(argv[1]);

    if (fout.is_open())
    {
        while ((ch = cin.get()) != EOF)
        {
            fout << (char)ch;
        }
    }
    else
    {
        cerr << "error to create the file!";
        exit(EXIT_FAILURE);
    }

    fout.close();

    return 0;
}