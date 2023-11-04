#include <iostream>
#include <fstream>
#include <string>
int main()
{
    using namespace std;
    char ch;

    ifstream fin1("17_2.txt");
    ifstream fin2("17_3.txt");
    ofstream fout("17_4.txt");

    string line;
    if (fin1.is_open() && fin2.is_open() && fout.is_open())
    {
        while (getline(fin1, line))
        {
            fout << line;
            if (getline(fin2, line))
                fout << " " << line << endl;
            else
                fout << endl;
        }
        while (getline(fin2, line))
            fout << line << endl;
        
        // 没有空格
        // while (!fin1.eof() || !fin2.eof())
        // {
        //     if (getline(fin1, line) && line.size() > 0)
        //         fout << line;
        //     if (getline(fin2, line) && line.size() > 0)
        //         fout << line;

        //     fout << endl;
        // }
    }
    else
    {
        cout << "Can't open the file!\n";
        exit(EXIT_FAILURE);
    }

    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}