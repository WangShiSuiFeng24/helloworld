#include <iostream>
#include <string>
#include "queuetp.h"

int main()
{
    QueueTP<Worker> lolas(10);
    Worker w1;
    w1.Set();
    lolas.enqueue(w1);
    Worker w2;
    lolas.dequeue(w2);
    w2.Show();

    cout << "Bye.\n";
    return 0;
}