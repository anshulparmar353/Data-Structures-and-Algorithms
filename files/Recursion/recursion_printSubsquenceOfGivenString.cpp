#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f(string &str, int idx, string result, vector<string> &list)
{
    // base case
    if (idx == str.length())
    {
        list.push_back(result);
        return;
    }
    // assumption
    f(str, idx + 1, result + str[idx], list);
    f(str, idx + 1, result, list);
}

int main()
{
    vector<string> res;
    string str = "abcd";

    f(str, 0, "", res);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl; // Newline after output for clarity
    return 0;
}
