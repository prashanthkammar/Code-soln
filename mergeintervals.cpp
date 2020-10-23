// let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8} }. The
// intervals {1,3} and {2,4} overlap with each other, so they should be merged
// and become {1, 4}. Similarly {5, 7} and {6, 8} should be merged and become
// {5, 8}

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct interval
{
    int start, end;
};

bool compare(interval a, interval b)
{
    return a.start < b.start;
}

void mergeintervals(interval *arr, int n)
{
    if (n <= 0)
        return;

    sort(arr, arr + n, compare);

    stack<interval> s;
    s.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        interval top = s.top();

        if (top.end < arr[i].start)
            s.push(arr[i]);

        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }

    cout << "Merged intervals " << endl;
    while (!s.empty())
    {
        interval a = s.top();
        cout << "[" << a.start << "," << a.end << "]" << endl;
        s.pop();
    }
}
int main()
{
    int n;
    cin >> n;
    interval *arr = new interval[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].end;

    mergeintervals(arr, n);
}