#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int v) {
        data = v;
        next = NULL;
    }
};

// Remove duplicates in O(n) time and O(1) space
node* removeDuplicates(node* head)
{
    if (head == NULL) return head;

    node* curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            // Duplicate found → remove next node
            node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;  // free memory
        }
        else
        {
            // Move to next distinct element
            curr = curr->next;
        }
    }

    return head;
}

// Print linked list
void printList(node* head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    // Example: Sorted list with duplicates
    node* head = new node(1);
    head->next = new node(1);
    head->next->next = new node(2);
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(3);
    head->next->next->next->next->next = new node(4);
    head->next->next->next->next->next->next = new node(4);

    cout << "Original List:\n";
    printList(head);

    head = removeDuplicates(head);

    cout << "After Removing Duplicates:\n";
    printList(head);

    return 0;
}