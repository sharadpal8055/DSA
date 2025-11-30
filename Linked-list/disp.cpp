#include <iostream>
using namespace std;
class node
{
public:
  int val;
  node *next;
};

int main()
{
int size=0;
  node *root = new node();
  node *second = new node();
  node *third = new node();
  node *fourth = new node();
  node *last = new node();
  root->val = 10;
  root->next = second;
  second->val = 20;
  second->next = third;
  third->val = 30;
  third->next = fourth;
  fourth->val = 40;
  fourth->next = last;
  last->val = 50;
  last->next = NULL;
  node *temp = new node();
  temp = root;
  while (temp!=NULL)
  {
    /* code */
    cout<<temp->val<<"->";
    temp=temp->next;
    size++;
  }
  cout<<"total size"<<size;
}
