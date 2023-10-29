#include <iostream>
using namespace std;
class pione { public:
int zhijing;
int zhouchang=zhijing*2;
};
int main() {
pione C;
C.zhijing = 5;
cout << C.zhijing << endl;
cout << C.zhouchang << endl;
}