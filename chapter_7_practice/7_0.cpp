void f(int ar[], int n, int value)
{
    while (n-- > 0)
        ar[n] = value;
}

void f2(int * head, int * tail, int value)
{
    while (head < tail)
    {
        *head = value;
        ++head;
    }
}

double f3(double ar[], int n)
{
    double max = ar[0];
    for (int i = 1; i < n; ++i)
        if (ar[i] > max)
            max = ar[i];
    return max;
}

int replace(char * str, char c1, char c2)
{
    int count;
    while (*str)
    {
        if (*str == c1)
        {
            *str = c2;
            ++count;
        }
        str++;
    }
    return count;
}

int judge(int (*p)(const char *));

struct application{
    char name[30];
    int credit_ratings[3];
};
#include <iostream>
void show(application app)
{
    std::cout << app.name << ": "
              << app.credit_ratings << std::endl;
}

void show (const application * pa)
{
    std::cout << pa->name << ": "
              << pa->credit_ratings << std::endl;
}

struct applicant
{
};
void f1(applicant *a);
const char *f2(const applicant *a1, const applicant *a2);

typedef void (*p1)(applicant *a);
typedef const char *(*p2)(const applicant *a1, const applicant *a2);

void (*(*ap[5]))(applicant *a);

p1 ap[5];
p2 (*pa)[10];
