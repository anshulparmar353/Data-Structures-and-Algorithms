#include <iostream>
using namespace std;
int main()
{
    int x = 5;
    int y = 4;
    int *p1 = &x;
    int *p2 = &y;

    cout << *p1 << " " << *p2 << endl;
    cout << *p1++ << " " << *++p2 << endl;

    return 0;
}