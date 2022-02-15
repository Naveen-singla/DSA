#include<iostream>

using namespace std;

#include<iostream>

using namespace std;

class node{

    public:
    int val;
    node *next;
    node *prev;
    node(int val)
    {
      this->val = val;
      this->next = NULL; 
      this->prev = NULL;
    }
    node(int val,node *next, node *prev)
    {
      this->val= val;
      this->next=next;
      this->prev= prev;
    }

};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;

    head = n;
}

void insertAtTail(node *&head,int val){
  
  if (head==NULL)
  {
    insertAtHead(head,val);
    return;
  }

  node *n = new node(val);
  node *temp = head;
  while (temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next=n;
  n->prev = temp;

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

void deletion_At_Head(node *&head)
{
    node *n = head;
    head = head->next;
    head->prev = NULL;
    delete n;
}


void deletion(node *&head,int pos)
{
    if(pos==1)
    {
    deletion_At_Head(head);
    return;
    } 
    node *temp = head;
    int count = 1;
    while (temp!=NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL) temp->next->prev = temp->prev;

    delete temp;
    
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
deletion(head,3);
display(head);
deletion(head,1);
display(head);

return 0;
}