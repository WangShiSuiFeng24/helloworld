#include "stonewt1.h"

Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0;
}

Stonewt::Stonewt(double lbs)
{
    pounds = lbs;
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::~Stonewt()
{}

bool Stonewt::operator<(const Stonewt & s) const
{
    return pounds < s.pounds;
}

bool Stonewt::operator<=(const Stonewt & s) const
{
    return pounds <= s.pounds;
}

bool Stonewt::operator>(const Stonewt & s) const
{
    return pounds > s.pounds;
}

bool Stonewt::operator>=(const Stonewt & s) const
{
    return pounds >= s.pounds;
}

bool Stonewt::operator==(const Stonewt & s) const
{
    return pounds == s.pounds;
}

bool Stonewt::operator!=(const Stonewt & s) const
{
    return pounds != s.pounds;
}

void Stonewt::show_lbs() const
{
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_stn() const
{
    std::cout << pounds << " pounds\n";
}