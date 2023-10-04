#include <iostream>
#include "queue.h"
#include <cstdlib>
#include <ctime>

const int MIN_PER_HR = 60;
const int MIN_SIM_HOURS = 150;

bool newcustomer(double x); 

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);
    cout << "The number of simulation hours >= 100. " << endl;

    int hours = MIN_SIM_HOURS;

    long cyclelimit = hours * MIN_PER_HR;

    double perhour = 0;

    Item temp;
    double average_wait = 0;

    while (average_wait < 1)
    {
        double min_per_cust;
        long turnaways = 0;
        long customers = 0;
        long served = 0;
        long sum_line = 0;
        int wait_time = 0;
        long line_wait = 0;
        perhour++;

        if (!line.isempty())
            line.dequeue(temp);

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            min_per_cust = MIN_PER_HR / perhour;
            if (newcustomer(min_per_cust))
            {
                if (line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    line.enqueue(temp);
                }
            }

            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;

            sum_line += line.queuecount();
        }   // for loop

        average_wait = (double)line_wait / served;

        if (average_wait < 1)
        {
            if (customers > 0)
            {
                cout << "customers accepted: " << customers << endl;
                cout << "  customers served: " << served << endl;
                cout << "         turnaways: " << turnaways << endl;
                cout << "average queue size: ";
                cout.precision(2);
                cout.setf(ios_base::fixed, ios_base::floatfield);
                cout << (double)sum_line / cyclelimit << endl;

                cout << " average wait time: "
                     << (double)line_wait / served << " minutes\n";
            }
            else
                cout << "No customers!\n";

            cout << "The average " << perhour << " of arrival per hour, and average wait time is "
                 << average_wait << endl;
        }
    }

    cout << "Done!\n";
    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}