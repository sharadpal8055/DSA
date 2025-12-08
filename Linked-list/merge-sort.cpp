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

// -------- FIND MIDDLE OF LINKED LIST --------
node* getMid(node* head) 
{
    node* slow = head;
    node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;  // middle node
}

// -------- MERGE TWO SORTED LINKED LISTS --------
node* mergeList(node* left, node* right) 
{
    if (left == NULL) return right;
    if (right == NULL) return left;

    node* dummy = new node(-1);
    node* tail = dummy;

    while (left != NULL && right != NULL) 
    {
        if (left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (left != NULL) tail->next = left;
    if (right != NULL) tail->next = right;

    node* head = dummy->next;
    delete dummy;
    return head;
}

// -------- MERGE SORT FUNCTION --------
node* mergeSort(node* head) 
{
    // Base case: 0 or 1 node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Step 1: Find middle & split list
    node* mid = getMid(head);
    node* rightHead = mid->next;
    mid->next = NULL;  // Split into two lists

    // Step 2: Recursively sort both halves
    node* left = mergeSort(head);
    node* right = mergeSort(rightHead);

    // Step 3: Merge sorted halves
    return mergeList(left, right);
}

// -------- PRINT LIST --------
void printList(node* head) 
{
    while (head != NULL) 
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// -------- MAIN --------
int main() 
{
    node* root = new node(40);
    root->next = new node(10);
    root->next->next = new node(30);
    root->next->next->next = new node(20);
    root->next->next->next->next = new node(50);

    cout << "Original List:\n";
    printList(root);

    root = mergeSort(root);

    cout << "\nSorted List:\n";
    printList(root);

    return 0;
}
