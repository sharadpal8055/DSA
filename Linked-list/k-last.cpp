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

// Function to get k-th node from end using 2 pointers
node* getKthFromEnd(node* head, int k)
{
    if (head == NULL || k <= 0) {
        return NULL;
    }

    node* slow = head;
    node* fast = head;

    // Move fast pointer k steps ahead
    for (int i = 0; i < k; i++)
    {
        if (fast == NULL) {
            return NULL; // k > length of list
        }
        fast = fast->next;
    }

    // Move slow & fast together until fast reaches NULL
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;   // slow is k-th node from end
}

int main()
{
    // Create linked list: 10 -> 20 -> 30 -> 40 -> 50
    node* head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);

    int k = 2;

    node* ans = getKthFromEnd(head, k);

    if (ans != NULL)
        cout << k << "th node from last is: " << ans->val << endl;
    else
        cout << "Invalid k (k is greater than length of list)" << endl;

    return 0;
}