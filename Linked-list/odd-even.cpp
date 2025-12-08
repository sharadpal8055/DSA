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

// Rearrange list: odd-valued nodes first, then even-valued nodes
node* oddEvenValue(node* head)
{
    if (!head) return head;

    node *oddHead = NULL, *oddTail = NULL;
    node *evenHead = NULL, *evenTail = NULL;

    node* curr = head;

    while (curr != NULL)
    {
        if (curr->data % 2 != 0)   // ODD VALUE
        {
            if (oddHead == NULL)
                oddHead = oddTail = curr;
            else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        else                      // EVEN VALUE
        {
            if (evenHead == NULL)
                evenHead = evenTail = curr;
            else {
                evenTail->next = curr;
                evenTail = curr;
            }
        }

        curr = curr->next;
    }

    // If no odd values exist
    if (oddHead == NULL)
    {
        evenTail->next = NULL;
        return evenHead;
    }

    // Join odd list + even list
    oddTail->next = evenHead;

    // Terminate even list
    if (evenTail != NULL)
        evenTail->next = NULL;

    return oddHead;
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
    node* head = new node(1);
    head->next = new node(4);
    head->next->next = new node(3);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(8);

    cout << "Original List:\n";
    printList(head);

    head = oddEvenValue(head);

    cout << "\nAfter Odd-Even (Value Based) Rearrangement:\n";
    printList(head);

    return 0;
}