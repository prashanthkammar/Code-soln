//remove nth element from end of thelist

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} * p;

class Linkedlist
{
public:
    Linkedlist()
    {
        p = NULL;
    }

    void append(int num)
    {
        node *r, *temp;
        r = new node;
        r->data = num;
        r->next = NULL;

        if (p == NULL)
            p = r;
        else
        {
            temp = p;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = r;
        }
    }

    void removefromend(int n)
    {
        node *fast, *slow;
        fast = slow = p;
        for (int i = 0; i < n; i++)
        {
            if (fast->next == NULL)
            {
                if (i == n - 1)
                {
                    node *temp = p;
                    p = p->next;
                    delete temp;
                    return;
                }
            }
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        node *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
    }
    void disp()
    {
        node *temp = p;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Linkedlist()
    {
        node *temp;
        while (p != NULL)
        {
            temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main()
{
    Linkedlist l;
    l.append(10);
    l.append(20);
    l.append(30);
    l.append(40);
    l.append(50);
    l.append(60);
    l.append(70);
    l.disp();
    l.removefromend(7);
    l.disp();
}