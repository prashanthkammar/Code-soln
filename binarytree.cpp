//implementation of binary tree and display elements after each traversals

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
} * root;

class binarytree
{
public:
    binarytree()
    {
        root = NULL;
    }
    void insert(int c)
    {
        node *p = new node;
        p->data = c;
        p->left = NULL;
        p->right = NULL;

        if (root == NULL)
            root = p;
        else
        {
            node *temp = root;
            node *parent;
            while (temp != NULL)
            {
                parent = temp;
                if (c > temp->data)
                    temp = temp->right;
                else
                    temp = temp->left;
            }

            if (c < parent->data)
                parent->left = p;
            else
                parent->right = p;
        }
    }
    void inorder()
    {
        inorder_disp(root);
    }

    void inorder_disp(node *temp)
    {
        if (temp != NULL)
        {
            inorder_disp(temp->left);
            cout << temp->data << " ";
            inorder_disp(temp->right);
        }
    }

    void preorder()
    {
        preorder_disp(root);
    }

    void preorder_disp(node *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            preorder_disp(temp->left);
            preorder_disp(temp->right);
        }
    }

    void postorder()
    {
        postorder_disp(root);
    }

    void postorder_disp(node *temp)
    {
        if (temp != NULL)
        {
            postorder_disp(temp->left);
            postorder_disp(temp->right);
            cout << temp->data << " ";
        }
    }

    void search(int key)
    {
        search(key, root);
    }

    node *search(int key, node *temp)
    {
        if (temp != NULL)
        {
            if (temp->data == key)
                return temp;
            if (key < temp->data)
                return search(key, temp->left);
            else
                return search(key, temp->right);
        }
        else
            return NULL;
    }

    ~binarytree()
    {
        node *temp = root;
        while (temp != NULL)
        {
            temp = temp->left;
            temp = temp->right;
            delete temp;
        }
    }
};

int main()
{
    binarytree b;
    b.insert(20);
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(40);
    b.insert(45);
    b.insert(30);
    cout << "Inorder traversal:" << endl;
    b.inorder();
    cout << endl
         << "Postorder traversal:" << endl;
    b.postorder();
    cout << endl
         << "Preorder traversal:" << endl;
    b.preorder();

    node *temp = b.search('C', root);
    cout << temp->data;
}
