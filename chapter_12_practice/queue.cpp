#include "queue.h"
#include <cstdlib>
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue()
{
    Node *temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

bool Queue::enqueue(const Item & item) 
{
    if (isfull())
        return false;
    Node *temp = new Node;
    temp->item = item;
    temp->next = nullptr;

    if (items == 0)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
    items++;
    return true;
}

bool Queue::dequeue(Item & item)
{
    if (isempty())
        return false;
    item = front->item;
    Node *temp;
    temp = front;
    front = front->next;
    delete temp;
    items--;
    if (items == 0)
        rear = front;
    return true;
}

// customer method
void Customer::set(long when)
{
    arrive = when;
    processtime = std::rand() % 3 + 1;
}