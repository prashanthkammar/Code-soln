#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isAnagram(string a, string b)
{
    map<char, int> dict;

    if (a.length() != b.length())
        return false;

    for (auto i : a)
        dict[i] += 1;

    for (auto i : b)
        dict[i] -= 1;

    for (auto i : dict)
    {
        if (i.second != 0)
            return false;
    }
    return true;
}

int main()
{
    cout << isAnagram("hello", "lloeh");
}