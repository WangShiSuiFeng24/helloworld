#include "queuetp.h"
// 不能将模板成员函数放在独立的实现文件中


template <class T>  
QueueTP<T>::QueueTP(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <class T>
QueueTP<T>::~QueueTP()
{
    Node *temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class T>
bool QueueTP<T>::isempty() const
{
    return items == 0;
}

template <class T>
bool QueueTP<T>::isfull() const
{
    return items == qsize;
}

template <class T>
int QueueTP<T>::queuecount() const
{
    return items;
}

template <class T>
bool QueueTP<T>::enqueue(const T &item)
{
    if (isfull())
        return false;
    Node *add;
    add = new Node;
    add->item = item;
    add->next = nullptr;

    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    items++;
    return true;
}

template <class T>
bool QueueTP<T>::dequeue(T &item)
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
        rear = nullptr;
    return true;
}

void Worker::Set()
{
    cout << "Enter worker's name: ";
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;

    while (cin.get() != '\n')
        continue;
}

void Worker::Show() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}