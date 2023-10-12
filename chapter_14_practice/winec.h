#ifndef WINEC_H_
#define WINEC_H_

#include <string>
#include <valarray>

template <class T1, class T2>
class Pair;
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;

public:
    T1 &first();
    T2 &second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair() {}
};


class Wine
{
private:
    std::string label;
    PairArray info;
    int year;

public:
    Wine(const char *l, int y, const int yr[], const int bot[]);
    Wine(const char *l, int y);

    void GetBottles();
    const std::string &Label() const;
    int sum() const;
    void Show();
};

#endif
