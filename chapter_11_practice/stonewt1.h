#ifndef STONEWT1_H_
#define STONEWT1_H_
#include <iostream>

class Stonewt
{
private:
    enum
    {
        Lbs_per_stn = 14
    };
    int stone;
    double pds_left;
    double pounds;

public:
    Stonewt();
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    ~Stonewt();

    bool operator<(const Stonewt &s) const;
    bool operator<=(const Stonewt &s) const;
    bool operator>(const Stonewt &s) const;
    bool operator>=(const Stonewt &s) const;
    bool operator==(const Stonewt &s) const;
    bool operator!=(const Stonewt &s) const;

    void show_lbs() const;
    void show_stn() const;
};

#endif