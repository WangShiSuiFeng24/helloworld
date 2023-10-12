#ifndef PERASON_H_
#define PERASON_H_

#include <iostream>
#include <string>

using namespace std;
class Person
{
private:
    string fname;
    string lname;

public:
    Person() : fname("no name"), lname("no name"){}
    Person(const string &f, const string &l);
    virtual ~Person(){}

    virtual void Show() const;
};

class Gunslinger : virtual public Person
{
private:
    int nick;

public:
    Gunslinger() : Person(), nick(0){}
    Gunslinger(const string &f, const string &l, int n);
    ~Gunslinger() {}

    double Draw();
    void Show() const;
};

struct Card
{
    enum SUITE
    {
        SPADE,
        HEART,
        DIAMOND,
        CLUB
    };
    SUITE suite;
    int number;
};

class PokerPlayer : virtual public Person
{
public:
    ~PokerPlayer(){}
    Card Draw() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    double GDraw() const;
    int CDraw() const;
    void Show() const;
};

#endif