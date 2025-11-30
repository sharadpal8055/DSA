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

// Merge two sorted linked lists
node* mergeSorted(node* head1, node* head2)
{
    // If one list is empty
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    // Dummy node to make handling easier
    node* dummy = new node(-1);
    node* tail = dummy;

    node* p1 = head1;
    node* p2 = head2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val <= p2->val)
        {
            tail->next = p1;
            p1 = p1->next;
        }
        else
        {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }

    // Attach remaining part
    if (p1 != NULL) tail->next = p1;
    if (p2 != NULL) tail->next = p2;

    node* mergedHead = dummy->next;
    delete dummy; // free dummy node

    return mergedHead;
}

// Print function
void printList(node* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {

    // First sorted linked list: 1 -> 3 -> 5 -> 7
    node* head1 = new node(1);
    head1->next = new node(3);
    head1->next->next = new node(5);
    head1->next->next->next = new node(7);

    // Second sorted linked list: 2 -> 4 -> 6
    node* head2 = new node(2);
    head2->next = new node(4);
    head2->next->next = new node(6);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    node* merged = mergeSorted(head1, head2);

    cout << "\nMerged sorted list: ";
    printList(merged);

    return 0;
}