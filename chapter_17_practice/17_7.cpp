#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void ShowStr(const string & str);

class Store
{
private:
    string str;
    ofstream &fout;

public:
    Store(ofstream &out) : fout(out) {}

    bool operator()(const string &str);

    ~Store() {}
};

void GetStrs(ifstream &fin, vector<string> &v);

int main()
{
    vector<string> vostr;
    string temp;

    // acquire
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(const string & str)
{
    cout << str << endl;
}

bool Store::operator()(const string & s)
{
    size_t len = s.size();
    if (fout.is_open())
    {
        fout.write((char *)&len, sizeof(size_t));
        fout.write(s.data(), len);
        return true;
    }
    return false;
}

void GetStrs(ifstream & fin, vector<string> &v)
{
    size_t len;
    char ch;
    string temp;
    while (fin.read((char*)&len, sizeof(size_t)))
    {
        for (int i = 0; i < len; i++)
        {
            fin.read((char *)&ch, sizeof(char));
            temp.push_back(ch);
            cout << "character " << ch << " is inserted into temp.\n";
        }
        v.push_back(temp);
        cout << "string " << temp << " is inserted into vector.\n";
        temp.clear();
    }
}