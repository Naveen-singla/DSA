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

int length(node *head)
{
    node* temp = head;
    int count = 1;
    while (temp->next!=null)
    {
        temp = temp->next;
        count++;
    }
    
    return count;
}

void intersect(node *head1, node *head2, int val)
{
    node *newtail=head2;
    node *temp1=head1;
    val--;
    while (val--)
    {
        temp1 = temp1->next;
    }
    while (newtail->next!=null)
    {
        newtail = newtail->next;
    }
    newtail->next = temp1; 
}

int intersection_point(node *head1, node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    int d;

    node *ptr1;
    node *ptr2;
    if (l1>l2)
    {
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else 
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d--)
    {
        ptr1 = ptr1->next;
        if (ptr1==null)
        {
            return -1;
        }
        
    }
    while (ptr1!=null && ptr2!=null)
    {
        if(ptr1==ptr2) return ptr1->val;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
       return -1;
}



int main()
{

node *head = NULL;
node *head1 = NULL;
insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,4);
insertAtTail(head,5);
insertAtTail(head,6);
insertAtTail(head1,8);
insertAtTail(head1,10);
intersect(head,head1,4);
display(head);
display(head1);
cout << intersection_point(head,head1);

return 0;
}
