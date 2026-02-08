#include <iostream>
#include <vector>
using namespace std;

int maximumOnesRow(vector<vector<int>> &V)
{
    int maxOnes = INT8_MIN;
    int maxOnesRow = -1;
    int columns = V[0].size();
    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[0].size(); j++)
        {

            if (V[i][j] == 1)
            {
                int numOfOnes = columns - j;
                if (numOfOnes > maxOnes)
                {
                    maxOnes=numOfOnes;
                    maxOnesRow = i;
                }
                break;
            }
        }
    }
    return maxOnesRow;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int res = maximumOnesRow(matrix);
    cout << res << endl;

    return 0;
}