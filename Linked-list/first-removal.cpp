#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int v) {
        val = v;
        next = NULL;
    }
};

node* firstrem(node* root)
{
    if (root == NULL)
    {
        cout << "Linked list does not exist\n";
        return NULL;
    }

    node* oldHead = root;
    root = root->next;

    delete oldHead;

    return root;
}

int main()
{
    int size = 0;

    node* root = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* last = new node(50);

    root->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = last;

    node* temp = root;

    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
        size++;
    }

    cout << "NULL\nTotal size: " << size << endl;

    // Remove first node
    root = firstrem(root);

    int size2 = 0;
    temp = root;

    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
        size2++;
    }

    cout << "NULL\nTotal size: " << size2 << endl;
}
