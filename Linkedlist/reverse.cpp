#include<iostream>

using namespace std;

class node{

    public:
    int val;
    node *next;
    node(int val)
    {
      this->val = val;
      this->next = NULL; 
    }
    node(int val,node *next)
    {
      this->val= val;
      this->next=next;
    }

};

void insertAtTail(node *&head,int val){
  
  node *n = new node(val);
  if (head==NULL)
  {
    head = n;
    return;
  }
  node *temp = head;
  while (temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next=n;

}

void display(node *head)
{
  node *n = head;
  while (n!=NULL)
  {
    cout << n->val << "->";
    n = n->next;
  }
  cout << "NULL" << endl;
  
}

void insertAtHead(node *&head,int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
  
}

node* reverseIterative(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *nex;
    while(curr!=NULL)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    } 
    return prev;
}

node* reverseRecursive(node *&head)
{
  if (head == NULL || head->next==NULL)
  {
    return head;
  }
  node *nHead = reverseRecursive(head->next);
  head->next->next = head;
  head->next =  NULL;
  return nHead;
}

int main()
{

node *head = NULL;
insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,4);
insertAtTail(head,5);
insertAtTail(head,6);
display(head);
node *newhead = reverseRecursive(head);
display(newhead);
return 0;
}