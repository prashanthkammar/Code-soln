//length of the longest common subsequence
#include <iostream>
#include <cstring>
using namespace std;

int longestsubsequence(char *x, char *y, int m, int n)
{
    int ans[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                ans[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                ans[i][j] = ans[i - 1][j - 1] + 1;
            else
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
        }
    }
    return ans[m][n];
}

int main()
{
    char x[] = "AGGTAB";
    char y[] = "GXTXAYB";

    int m = strlen(x);
    int n = strlen(y);

    cout << longestsubsequence(x, y, m, n);
}