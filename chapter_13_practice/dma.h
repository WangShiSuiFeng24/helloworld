#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class ABC
{
public:
    virtual ~ABC();
    virtual void View() { std::cout << "This is ABC View(), it is empty.\n"; }
};

class baseDMA : public ABC
{
private:
    char *label;
    int rating;
public:
    baseDMA(const char *l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();

    virtual void View();
    baseDMA &operator=(const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream &os, const baseDMA &rs);
};

class lacksDMA : public baseDMA
{
private:
    enum
    {
        COL_LEN = 40
    };
    char color[COL_LEN];

public:
    lacksDMA(const char *c = "blank", const char *l = "null",
             int r = 0);
    lacksDMA(const char *c, const baseDMA &rs);

    virtual void View();
    friend std::ostream &operator<<(std::ostream &os,
                                    const lacksDMA &ls);
};

class hasDMA : public baseDMA
{
private:
    char *style;

public:
    hasDMA(const char *s = "none", const char *l = "null",
           int r = 0);
    hasDMA(const char *s, const baseDMA &rs);
    hasDMA(const hasDMA &hs);
    ~hasDMA();

    virtual void View();
    hasDMA &operator=(const hasDMA &hs);
    friend std::ostream &operator<<(std::ostream &os,
                                     const hasDMA &hs);
};

#endif