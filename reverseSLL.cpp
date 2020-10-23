//reverse a singly linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
} * p;

class linkedlist
{
public:
    linkedlist()
    {
        p = NULL;
    }

    void append(int num)
    {
        node *temp, *r;
        temp = new node;
        temp->data = num;
        temp->link = NULL;

        if (p == NULL)
            p = temp;
        else
        {
            r = p;
            while (r->link != NULL)
                r = r->link;

            r->link = temp;
        }
    }

    void reverse()
    {
        node *current = p;
        node *link = NULL, *prev = NULL;

        while (current != NULL)
        {
            link = current->link;
            current->link = prev;
            prev = current;
            current = link;
        }
        p = prev;
    }
    void display()
    {
        node *temp = p;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }

    ~linkedlist()
    {
        node *temp;
        while (temp != NULL)
        {
            temp = p->link;
            delete p;
            p = temp;
        }
    }
};

int main()
{
    linkedlist l;
    l.append(60);
    l.append(50);
    l.append(40);
    l.append(30);
    l.append(20);
    l.append(10);
    l.display();
    l.reverse();
    l.display();
}