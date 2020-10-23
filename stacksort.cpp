//sort the given stack using only one temporary stack

#include <iostream>
#include <stack>
using namespace std;

void stack_sort(stack<int> &s)
{
    stack<int> temp;
    while (!s.empty())
    {
        int popped_ele = s.top();
        s.pop();

        while (!temp.empty() && popped_ele < temp.top()) //ascending order
        {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(popped_ele);
    }

    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
} //O(n^2)

int main()
{
    stack<int> s;
    s.push(100);
    s.push(20);
    s.push(10);
    s.push(30);
    s.push(90);
    stack_sort(s);

    stack<int> tmpStack = s;
    cout << "Sorted numbers are:\n";

    while (!tmpStack.empty())
    {
        cout << tmpStack.top() << " ";
        tmpStack.pop();
    }
}