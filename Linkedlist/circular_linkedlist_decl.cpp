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
    n->next = n;
    head = n;
    return;
  }
  
  node *temp = head;
  while (temp->next!=head)
  {
    temp = temp->next;
  }
  n->next = head;
  temp->next=n;

}

void display(node *head)
{
  node *n = head;
  while (n->next!=head)
  {
    cout << n->val << "->";
    n = n->next;
  }
  cout << "NULL" << endl;
  
}

void insertAtHead(node *&head,int val)
{
  node *temp = head;
  while (temp->next!=head)
  {
    temp = temp->next;
  }
  
    node *n = new node(val);
    temp->next = n;
    n->next = head;
    head = n;
  
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
insertAtTail(head,7);
display(head);

return 0;
}
