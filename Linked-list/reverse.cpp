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

node* rev(node* curr){
    node* prev = NULL;
    node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    node* root = new node(10);
    root->next = new node(20);
    root->next->next = new node(30);
    root->next->next->next = new node(40);
    root->next->next->next->next = new node(50);

    node* temp = root;

    // Print original list
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL\n";

    // Reverse list
    root = rev(root);

    // Print reversed list
    temp = root;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}
