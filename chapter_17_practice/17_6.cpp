#include <iostream>
#include <fstream>
#include "emp.h"

using namespace std;

const int MAX = 4;
enum ClassType
{
    Employee,
    Manager,
    Fink,
    HighFink
};

int main()
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();

    manager ma("Amorphis", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();

    highfink hf(ma, "Curly Kew");
    hf.ShowAll();

    // 下一阶段
    cout << "Press a key for next phase:\n";
    cin.get();

    ofstream fout("EMP.TXT");
    if (!fout.is_open())
        exit(EXIT_FAILURE);

    cout << "Using an abstr_emp *pointer to write file.\n";
    abstr_emp *tri[MAX] = {&em, &ma, &fi, &hf};

    for (int i = 0; i < MAX; i++)
    {
        if (typeid(*tri[i]) == typeid(employee))
        {
            fout << Employee << endl;
            // tri[i]->writeall(fout);
        }
        else if (typeid(*tri[i]) == typeid(manager))
        {
            fout << Manager << endl;
            // tri[i]->writeall(fout);
        }
        else if (typeid(*tri[i]) == typeid(fink))
        {
            fout << Fink << endl;
            // tri[i]->writeall(fout);
        }
        else if (typeid(*tri[i]) == typeid(highfink))
        {
            fout << HighFink << endl;
            // tri[i]->writeall(fout);
        }
        else 
        {
            fout << -1 << endl;
            // tri[i]->writeall(fout);
        }
        tri[i]->writeall(fout);
    }

    fout.close();

    abstr_emp *pc[MAX];
    int classtype;
    int i = 0;
    ifstream fin("EMP.TXT");

    if (!fin.is_open())
        exit(EXIT_FAILURE);

    while (fin >> classtype)
    {
        fin.get();
        switch (classtype)
        {
            case Employee:
                pc[i] = new employee;
                // pc[i]->getall(fin);
                // i++;
                break;
            
            case Manager:
                pc[i] = new manager;
                // pc[i]->getall(fin);
                // i++;
                break;

            case Fink:
                pc[i] = new fink;
                // pc[i]->getall(fin);
                // i++;
                break;
            
            case HighFink:
                pc[i] = new highfink;
                // pc[i]->getall(fin);
                // i++;
                break;
        } // switch
        pc[i]->getall(fin);
        i++;
    } // while

    for (i = 0; i < MAX; ++i)
        pc[i]->ShowAll();

    fin.close();
    return 0;
}