// stack.cpp -- compile with 10_5.cpp
#include <iostream>
#include "stack.h"

Stack::Stack()
{
    top = 0;
}

Stack::~Stack()
{

}

bool Stack::isEmpty() const
{
    return top == 0;
}

bool Stack::isFull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        items[top] = item;
        top++;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        --top;
        item = items[top];
        return true;
    }
    else
        return false;
}