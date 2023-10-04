#include "stack.h"

Stack::Stack(int n)
{
    pitems = new Item[n];
    size = n;
    top = 0;
}

Stack::Stack(const Stack & st)
{
    size = st.size;
    pitems = new Item[size];
    for (int i = 0; i < size; ++i)
        pitems[i] = st.pitems[i];
    top = st.top;
}

Stack::~Stack()
{
    if (pitems != nullptr)
        delete[] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item)
{
    if (isfull())
        return false;
    pitems[top] = item;
    top++;
    return true;
}

bool Stack::pop(Item & item)
{
    if (isempty())
        return false;
    top--;
    item = pitems[top];
    return true;
}

Stack & Stack::operator=(const Stack & st)
{
    if (this == &st)
        return *this;
    delete[] pitems;
    pitems = new Item[st.size];
    for (int i = 0; i < st.top; ++i)
        pitems[i] = st.pitems[i];
    size = st.size;
    top = st.top;
    return *this;
}