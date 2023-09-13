#include <iostream>
using namespace std;
struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show(box);
void set_box(box *);

int main()
{
    box Orange = {"China", 12, 12, 12, 0};
    set_box(&Orange);
    show(Orange);
    return 0;
}

void show(box b)
{
    cout << "This box made by " << b.maker << ".\nAnd height = " << b.height;
    cout << ", width = " << b.width << ", length = " << b.length << ", volume = ";
    cout << b.volume << ".";
}

void set_box(box *pb)
{
    pb->volume = pb->height * pb->width * pb->length;
}