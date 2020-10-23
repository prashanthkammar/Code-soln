//Find middle element of a linked list

#include <iostream>

struct node
{
    int data;
    node *link;
} * p;

class Linkedlist
{
public:
    Linkedlist();
    void append(int num);
    void display();
    int middleelement();
    ~Linkedlist()
    {
        node *temp;
        while (p != NULL)
        {
            temp = p;
            p = p->link;
            delete temp;
        }
    }
};

Linkedlist::Linkedlist()
{
    p = NULL;
}

void Linkedlist::append(int num)
{
    node *r, *temp;
    r = new node;
    r->data = num;
    r->link = NULL;

    if (p == NULL)
        p = r;
    else
    {
        temp = p;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = r;
    }
}

int Linkedlist::middleelement()
{
    node *r, *q;
    r = q = p;
    while (q != NULL)
    {
        q = q->link;
        if (q != NULL)
            q = q->link;
        if (q != NULL)
            r = r->link;
    }
    int num = r->data;
    return num;
}

void Linkedlist::display()
{
    node *temp = p;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->link;
    }
    std::cout << std::endl;
}

int main()
{
    Linkedlist l;
    l.append(50);
    l.append(30);
    l.append(40);
    l.append(10);
    l.append(20);
    l.append(5);
    l.append(1);
    l.display();
    std::cout << "Middle element is " << l.middleelement();
}