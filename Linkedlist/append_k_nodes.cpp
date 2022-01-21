#include<iostream>
#define null NULL

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

node* append_k_nodes(node *&head,int val)
{
    node *newhead;
    node *newtail;
    node *tail = head;
    int count=1;
    while (tail->next!=null)
    {
        if(count==val) newtail = tail;
        tail = tail->next;
        count++;
    }
    newhead = newtail->next;
    newtail->next = null;
    tail->next = head;
    
    return newhead;
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
node *newhead = append_k_nodes(head,3);
display(newhead);


return 0;
}
