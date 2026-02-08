#include <iostream>
using namespace std;
int main()
{

    int r1, c1;
    cout << "Enter the row and column for matrix 1: " << endl;
    cin >> r1 >> c1;

    int r2, c2;
    cout << "Enter the row and column for matrix 2: " << endl;
    cin >> r2 >> c2;

    if (c1 == r2)
    {
        int A[r1][c1];

        cout << "Enter the elements for matrix 1: " << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                cin >> A[i][j];
            }
        }

        int B[r2][c2];

        cout << "Enter the elements for matrix 2: " << endl;
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cin >> B[i][j];
            }
        }

        int C[r1][c2];

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                int value = 0;
                for (int k = 0; k < r2; k++)
                {
                    value += A[i][k] * B[k][j];
                }
                C[i][j] = value;
            }
        }

        cout << "The resulted Matrix is: " << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        cout<<"The matrix multipication is not possible"<<endl;
    }

    return 0;
}