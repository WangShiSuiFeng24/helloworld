// compile with queue.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;
const int MIN_SIM_HOURS = 1500;

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

    Queue line_one(qs);
    Queue line_two(qs);

    cout << "The number of simulation hours >= 100. " << endl;

    int hours = MIN_SIM_HOURS;
    long cyclelimit = hours * MIN_PER_HR;

    double perhour = 0;
    double min_per_cust;
    Item temp;
    long turnaways;
    long customers, customers_one, customers_two;
    long served;
    long sum_line_one, sum_line_two;
    int wait_time_one, wait_time_two;
    long line_wait;
    double average_wait = 0;

    while (average_wait < 1.0)
    {
        turnaways = 0;
        customers = customers_one = customers_two = 0;
        served = 0;
        sum_line_one = sum_line_two = 0;
        wait_time_one = wait_time_two = 0;
        line_wait = 0;
        perhour++;

        min_per_cust = MIN_PER_HR / perhour;

        while (!line_one.isempty())
            line_one.dequeue(temp);
        while (!line_two.isempty())
            line_two.dequeue(temp);

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line_one.isfull() && line_two.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    if (line_one.queuecount() < line_two.queuecount())
                    {
                        line_one.enqueue(temp);
                        customers_one++;
                    }
                    else
                    {
                        line_two.enqueue(temp);
                        customers_two++;
                    }
                    /*平均处理两个ATM排队的人数*/
                }
            }

            if (wait_time_one <= 0 && !line_one.isempty())
            {
                line_one.dequeue(temp);
                wait_time_one = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }

            if (wait_time_two <= 0 && !line_two.isempty())
            {
                line_two.dequeue(temp);
                wait_time_two = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }

            if (wait_time_one > 0)
                wait_time_one--;
            if (wait_time_two > 0)
                wait_time_two--;

            sum_line_one += line_one.queuecount();
            sum_line_two += line_two.queuecount();
        }

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
                cout << (double)(sum_line_one + sum_line_two) / cyclelimit << endl;

                cout << " average wait time: "
                     << (double)line_wait / served << " minutes\n";
            }
            else
                cout << "No customers!\n";

            cout << "The average " << perhour << " of arrival per hour, and average wait time is "
                 << average_wait << endl;
        }
    }
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}