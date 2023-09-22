// stack.h -- for 10_5.cpp
#ifndef STACK_H_
#define STACK_H_

struct customer
{
    char fullname[35];
    double payment;
};

typedef customer Item;

class Stack
{
private:
    enum
    {
        MAX = 10
    };
    Item items[MAX];
    int top;
public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Item &item);
    bool pop(Item &item);
};

#endif