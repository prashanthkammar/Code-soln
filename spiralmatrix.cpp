// Print a 2D array spirally

#include <iostream>
using namespace std;

void spiral(int **a, int n, int m)
{
    int top = 0;
    int left = 0;
    int down = n - 1;
    int right = m - 1;
    int dir = 0;

    while (top <= down && left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
                cout << a[top][i] << " ";
            top++;
        }

        else if (dir == 1)
        {
            for (int i = top; i <= down; i++)
                cout << a[i][right] << " ";
            right--;
        }

        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
                cout << a[down][i] << " ";
            down--;
        }
        else if (dir == 3)
        {
            for (int i = down; i >= top; i--)
                cout << a[i][left] << " ";
            left++;
        }
        dir = (dir + 1) % 4;
    }
}

int main()
{
    int n, m; // n = rows, m = columns
    cin >> n >> m;

    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    spiral(a, n, m);

    for (int i = 0; i < n; i++)
        delete[] a[i];

    delete[] a;
}