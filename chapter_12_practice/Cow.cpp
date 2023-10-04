// Cow.cpp -- compile with 12_1.cpp
#include "cow.h"
#include <cstring>
#include <iostream>

Cow::Cow()
{
    name[0] = '\0';
    hobby = nullptr;
    weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strncpy(name, nm, 20);
    if (strlen(nm) >= 20)
        name[19] = '\0';
    else
        name[strlen(nm)] = '\0';
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    if (hobby != nullptr)
        delete[] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    if (this == &c)
        return *this;
    strcpy(name, c.name);
    delete[] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;

    return *this;
}

void Cow::ShowCow() const
{
    if (hobby == nullptr)
    {
        std::cout << "This Cow's info is Empty!" << std::endl;
        return;
    }
    else
    {
        using std::cout;
        using std::endl;
        cout << "This is Information of COW." << endl;
        cout << "Name: " << name << endl;
        cout << "Hobby: " << hobby << endl;
        cout << "Weight: " << weight << endl;
    }
}