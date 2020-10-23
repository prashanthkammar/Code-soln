// implementing stack data structure using queue data structure
#include <iostream>
#include <queue>
using namespace std;

class stack
{
    queue<int> primary_q, secondary_q;

public:
    void push(int num)
    {
        secondary_q.push(num);
        while (!primary_q.empty())
        {
            secondary_q.push(primary_q.front());
            primary_q.pop();
        }

        queue<int> temp = primary_q;
        primary_q = secondary_q;
        secondary_q = temp;
    }
    int pop()
    {
        if (primary_q.empty())
            return -1;
        else
        {
            int num = primary_q.front();
            primary_q.pop();
            return num;
        }
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " " << s.pop() << " " << s.pop();
}