// queuetp.h
#ifndef QUEUETP_H_
#define QUEUETP_H_

#include <iostream>
#include <string>
using namespace std;

class Worker
{
private:
    std::string fullname;
    long id;
// protected:
//     void Data() const;
//     void Get();
public:
    Worker() : fullname("no none"), id(0L) {}
    Worker(const std::string & s, long n) : fullname(s), id(n) {}
    ~Worker() {}

    void Set();
    void Show() const;
};

template <class T> 
class QueueTP
{
private:
    enum
    {
        Q_SIZE = 10
    };
    struct Node
    {
        T item;
        Node *next;
    };

    Node *front;
    Node *rear;
    int items;
    const int qsize;

    QueueTP(const QueueTP & q) : qsize(0) {}
    QueueTP &operator=(const QueueTP &q) { return *this; }

public:
    QueueTP(int qs = Q_SIZE);
    // QueueTP(int qs = Q_SIZE) : qsize(qs)
    // {
    //     front = rear = null;
    //     items = 0;
    // }

    ~QueueTP();
    // {
    //     Node *temp;
    //     while (front != nullptr)
    //     {
    //         temp = front;
    //         front = front->next;
    //         delete temp;
    //     }
    // }
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T &item);
    bool dequeue(T &item);
};

// #include "queuetp.h"

// void Worker::Set()
// {
//     cout << "Enter worker's name: ";
//     getline(cin, fullname);
//     cout << "Enter worker's ID: ";
//     cin >> id;

//     while (cin.get() != '\n')
//         continue;
// }

// void Worker::Show() const
// {
//     cout << "Name: " << fullname << endl;
//     cout << "Employee ID: " << id << endl;
// }

// template <class T>  
// QueueTP<T>::QueueTP(int qs) : qsize(qs)
// {
//     front = rear = nullptr;
//     items = 0;
// }

// template <class T>
// QueueTP<T>::~QueueTP()
// {
//     Node *temp;
//     while (front != nullptr)
//     {
//         temp = front;
//         front = front->next;
//         delete temp;
//     }
// }

// template <class T>
// bool QueueTP<T>::isempty() const
// {
//     return items == 0;
// }

// template <class T>
// bool QueueTP<T>::isfull() const
// {
//     return items == qsize;
// }

// template <class T>
// int QueueTP<T>::queuecount() const
// {
//     return items;
// }

// template <class T>
// bool QueueTP<T>::enqueue(const T &item)
// {
//     if (isfull())
//         return false;
//     Node *add;
//     add = new Node;
//     add->item = item;
//     add->next = nullptr;

//     if (front = nullptr)
//         front = add;
//     else
//         rear->next = add;
//     rear = add;
//     items++;
//     return true;
// }

// template <class T>
// bool QueueTP<T>::dequeue(T &item)
// {
//     if (isempty())
//         return false;
//     item = front->item;
//     Node *temp;
//     temp = front;
//     front = front->next;
//     delete temp;
//     items--;
//     if (items == 0)
//         rear = nullptr;
//     return true;
// }
#endif