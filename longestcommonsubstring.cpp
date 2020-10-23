//Print the length of the longest common substring

#include <iostream>
#include <cstring>
using namespace std;

int commonsubsequence(char *x, char *y, int m, int n)
{
    int ans[m + 1][n + 1];
    int res = 0, row, col;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                ans[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
            {
                ans[i][j] = ans[i - 1][j - 1] + 1;
                if (res < ans[i][j])
                {
                    res = ans[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                ans[i][j] = 0;
        }
    }

    int len = res;
    if (len == 0)
    {
        cout << "No Common Substring";
        return 0;
    }

    char *s = new char[len + 1];
    while (ans[row][col] != 0)
    {
        s[--len] = x[row - 1]; // or Y[col-1]

        row--;
        col--;
    }
    cout << s << endl;

    return res;
}

int main()
{
    char x[] = "prashanthkammar";
    char y[] = "prashanth";

    int m = strlen(x);
    int n = strlen(y);

    cout << commonsubsequence(x, y, m, n);
}