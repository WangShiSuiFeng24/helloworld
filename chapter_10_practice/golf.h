// golf.h -- for 10_3.cpp
#ifndef GOLF_H_
#define GOLF_H

class golf
{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    golf();
    golf(const char *name, int hc);
    ~golf();

    void sethandicap(int hc);
    void showgolf() const;
};

#endif