/*
    Compression of strings
    Example: 1. Input a, output a;
    2. Input aaa, Output a3
    3. Input aaaabcc , Output a4b1c2
    The output string length should be less than input else return original string as in first case
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

namespace patch
{
    template <typename T>
    string to_string(const T &n)
    {
        stringstream m;
        m << n;
        string s;
        m >> s;
        return s;
    }
} // namespace patch

string string_compression(string s)
{
    int sum = 1;
    string output = "";
    sort(s.begin(), s.end());
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
            sum++;
        else
        {
            output += s[i] + patch::to_string(sum);
            sum = 1;
        }
    }
    output += s[s.length() - 1] + patch::to_string(sum);
    return output > s ? s : output;
}

int main()
{
    string s;
    getline(cin, s);
    string a = string_compression(s);
    cout << a;
}