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

node *recursive_merging(node *&head1, node *&head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    node *result;
    if(head1->val<head2->val)
    {
        result = head1;
        result->next = recursive_merging( head1->next,head2);
    }
    else
    {
        result = head2;
        result->next = recursive_merging(head1,head2->next);
    }
    return result;
}

node *merging_linkedlist(node *head1,node *head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummyNode = new node(-1);
    node *p3 = dummyNode;
    while (p1!=NULL && p2!=NULL)
    {
        if(p1->val<p2->val)
        {
            p3->next = p1;
            p1 = p1->next;
        } 
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
            p3 = p3->next;
    }

    while (p1!=NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2!=NULL)
    {
        p3->next = p1;
        p2 = p2->next;
        p3 = p3->next;
    }
    
    
    return dummyNode->next;
}

int main()
{

node *head = NULL;
node *head1 = NULL;
insertAtTail(head,1);
insertAtTail(head,4);
insertAtTail(head,5);
insertAtTail(head,7);
insertAtTail(head,7);
insertAtTail(head,7);
insertAtTail(head,7);
insertAtTail(head1,2);
insertAtTail(head1,3);
insertAtTail(head1,6);
insertAtTail(head1,6);
insertAtTail(head1,6);
node *newhead = recursive_merging(head,head1);
display(newhead);

return 0;
}
