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

void deletion(node *&head, int val)
{
    if(head==NULL) return;
    if(head->val==val)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
    node *temp = head;
    while (temp->next->val!=val)
    {
        temp = temp->next;
    }
    node *del = temp->next;
    temp->next = temp->next->next;
    delete del;
    }
    
}

int main()
{

node *head = NULL;
insertAtTail(head,1);
display(head);
deletion(head,1);
display(head);


return 0;
}
