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
node*rev(node*curr){
  
  node*prev=NULL;
  node*next=curr;
  while(curr!=NULL){
   next=curr->next;
    curr->next=prev;
    
    prev=curr;
    curr=next;
    
  }
  return prev;
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
    root=rev(root);
    temp=root;
while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
       
    }
}
