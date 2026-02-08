#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f(string &str, int idx, string result, vector<string> &list, vector<string> &v)
{
    // base case
    if (idx == str.size())
    {
        list.push_back(result);
        return;
    }
    int digit = str[idx] - '0';
    if (digit <= 1)
    {
        f(str, idx + 1, result, list, v);
        return;
    }
    for (int i = 0; i < v[digit].size(); i++)
    {
        f(str, idx + 1, result + v[digit][i], list, v);
    }
    return;
}
int main()
{
    vector<string> v(10);
    v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str = "23";
    vector<string> list;
    f(str, 0, "", list, v);
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }

    return 0;
}