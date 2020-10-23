//implementing queue data structure using stack

#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> primary_s, secondary_s;

public:
    void enqueue(int num)
    {
        while (!primary_s.empty())
        {
            secondary_s.push(primary_s.top());
            primary_s.pop();
        }
        primary_s.push(num);
        while (!secondary_s.empty())
        {
            primary_s.push(secondary_s.top());
            secondary_s.pop();
        }
    }

    int dequeue()
    {
        if (primary_s.empty())
            return -1;

        int num = primary_s.top();
        primary_s.pop();
        return num;
    }
};

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}