#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    // base case
    if (b > a)  return gcd(b, a);
    if (b == 0) return a;
    // assumption
    return gcd(b, a % b);
}
int main()
{
    int x = gcd(18,24);
    cout << x << endl;
    return 0;
}