// two linked lists merge at one particular point. Print the node
// L1 : 1 -> 2 ->3 -> 4
// L2 : 10 -> 20 -> 3 (L1)

#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *link;
} * p, *q;

class linkedlist
{

public:
    linkedlist()
    {
        p = NULL;
    }

    void append(int num)
    {
        node *temp = new node;
        temp->data = num;
        temp->link = NULL;

        if (p == NULL)
            p = temp;
        else
        {
            node *r = p;
            while (r->link != NULL)
                r = r->link;

            r->link = temp;
        }
    }

    void intersect(node *temp)
    {
        node *r = p;
        for (int i = 0; i < 3; i++)
            r = r->link;

        while (temp->link != NULL)
            temp = temp->link;

        temp->link = r;
    }

    void disp(node *a)
    {
        node *temp = a;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }

    void get_intersection()
    {
        stack<node *> l1, l2;

        node *temp = p;
        while (temp != NULL)
        {
            l1.push(temp);
            temp = temp->link;
        }

        temp = q;
        while (temp != NULL)
        {
            l2.push(temp);
            temp = temp->link;
        }

        if ((l1.top() != l2.top()))
        {
            cout << "Lists are not merged " << endl;
            return;
        }
        node *r;
        while ((!l1.empty()) && (!l2.empty()))
        {
            if (l1.top() == l2.top())
            {
                r = l1.top();
                l1.pop();
                l2.pop();
            }
            else
            {
                cout << "Intersection " << r->data << endl;
                return;
            }
        }
    }
};

int main()
{
    linkedlist l;
    l.append(10);
    l.append(20);
    l.append(30);
    l.append(40);
    l.append(50);
    l.disp(p);
    q = new node;
    q->data = 5;
    q->link = NULL;
    node *temp = new node;
    temp->data = 7;
    temp->link = NULL;
    q->link = temp;
    l.intersect(q);
    l.disp(q);
    l.get_intersection();
}
