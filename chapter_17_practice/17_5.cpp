#include <iostream>
#include <set>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin_mat("mat.dat");
    ifstream fin_pat("pat.dat");

    string guest;
    set<string> mat_set, pat_set, guest_set;

    if (!fin_mat.is_open() || !fin_pat.is_open())
    {
        cerr << "Error open files." << endl;
        exit(EXIT_FAILURE);
    }
    
    while (getline(fin_mat, guest) && guest.size() > 0)
        mat_set.insert(guest);
    cout << "\nMat's friends are: \n";
    for (auto pd = mat_set.begin(); pd != mat_set.end(); pd++)
        cout << *pd << " ";

    while (getline(fin_pat, guest) && guest.size() > 0)
        pat_set.insert(guest);
    cout << "\nPat's friends are: \n";
    for (auto pd = pat_set.begin(); pd != pat_set.end(); pd++)
        cout << *pd << " ";

    fin_mat.close();
    fin_pat.close();

    guest_set.insert(mat_set.begin(), mat_set.end());
    guest_set.insert(pat_set.begin(), pat_set.end());

    ofstream fout("matpat.dat");
    if (!fout.is_open())
    {
        cerr << "Error open files." << endl;
        exit(EXIT_FAILURE);
    }

    for (auto pd = guest_set.begin(); pd != guest_set.end(); pd++)
        fout << *pd << endl;

    fout.close();

    ifstream fin("matpat.dat");
    if (!fin.is_open())
    {
        cerr << "Error open files." << endl;
        exit(EXIT_FAILURE);
    }

    cout << "\n All Guest list: ";
    while (getline(fin, guest))
        cout << guest << endl;

    cout << endl;
    fin.close();

    return 0;
}