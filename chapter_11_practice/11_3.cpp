#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect2.h"

int main()
{
    using namespace std;
    using namespace VECTOR;

    //srand(time(0));

    Vector step;
    double direction;
    double dstep;

    Vector result(0.0, 0.0);

    double target;

    unsigned long steps = 0;
    unsigned long steps_max = 0;
    unsigned long steps_min = 0;
    unsigned long steps_tot = 0;
    double steps_avg;

    unsigned N;

    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

        cout << "Enter the tests count: ";
        if (!(cin >> N))
            break;

        for (int i = 0; i < N; ++i)
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }

            if (steps > steps_max)
                steps_max = steps;
            if (steps_min == 0)
                steps_min = steps_max;
            if (steps < steps_min)
                steps_min = steps;
            steps_tot += steps;

            steps = 0;
            result.reset(0.0, 0.0);
        }
        steps_avg = steps_tot / N;

        cout << "The " << N << " times tests max steps is " << steps_max << endl;
        cout << "                 min steps is " << steps_min << endl;
        cout << "                 average stpes is " << steps_avg << endl;

        cout << "Enter target distance (q to quit): ";

        steps_max = 0;
        steps_min = 0;
        steps_tot = 0;
    }
    cout << "Bye.\n";
    return 0;
}