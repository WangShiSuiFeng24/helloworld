#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"
#include <fstream>

int main()
{
    using namespace std;
    using namespace VECTOR;

    srand(time(0));

    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    ofstream fout;
    fout.open("random_walk.txt");

    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        
        fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;

        while (result.magval() < target)
        {
            fout << steps << ": " << result << endl;

            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }

        // std output
        cout << "After " << steps << " steps, the subject "
                                     "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n"
             << result << endl;
        cout << "Average outward distance per step = "
             << result.magval() / steps << endl;

        // file output
        result.rect_mode();

        fout << steps << ": " << result << endl;

        fout << "After " << steps << " steps, the subject "
                                     "has the following location:\n";
        fout << result << endl;
        result.polar_mode();
        fout << "or\n";
        fout << result << endl;
        fout << "Average outward distance per step = "
             << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}