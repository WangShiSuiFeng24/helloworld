#include "stonewt.h"
#include <iostream>
Stonewt::Stonewt(double lbs)
{
    pounds = lbs;
    stone = (int)lbs / Lbs_per_stn;
    pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
    style = POUNDS;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + pds_left;
    style = FLOATPOUNDS;
}

Stonewt::Stonewt()
{
    stone = 0;
    pds_left = pounds = 0.0;
    style = STONE;
}

Stonewt::~Stonewt()
{}

void Stonewt::Set_Style(Style m)
{
    style = m;
}

Stonewt Stonewt::operator+(const Stonewt & s) const
{
    Stonewt temp;
    temp.pounds = pounds + s.pounds;
    temp.stone = int(temp.pounds) / Lbs_per_stn;
    temp.pds_left = int(temp.pounds) % Lbs_per_stn + temp.pounds - int(temp.pounds);
    temp.style = this->style;

    return temp;
}

Stonewt Stonewt::operator-(const Stonewt & s) const
{
    Stonewt temp;
    temp.pounds = pounds - s.pounds;
    temp.stone = int(temp.pounds) / Lbs_per_stn;
    temp.pds_left = int(temp.pounds) % Lbs_per_stn + temp.pounds - int(temp.pounds);
    temp.style = this->style;

    return temp;
}

Stonewt Stonewt::operator*(double n) const
{
    Stonewt temp;
    temp.pounds = n * pounds;
    temp.stone = int(temp.pounds) / Lbs_per_stn;
    temp.pds_left = int(temp.pounds) % Lbs_per_stn + temp.pounds - int(temp.pounds);
    temp.style = this->style;

    return temp;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    if (s.style == Stonewt::STONE)
    {
        double st = s.stone + s.pds_left / Stonewt::Lbs_per_stn;
        os << st << " stone\n";
    }
    if (s.style == Stonewt::POUNDS)
        os << s.pounds << " pounds\n";
    if (s.style == Stonewt::FLOATPOUNDS)
        os << s.stone << " stone, " << s.pds_left << " pounds\n";
    return os;
}