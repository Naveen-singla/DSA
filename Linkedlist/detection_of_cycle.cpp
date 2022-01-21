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

void makecycle(node *head, int pos)
{
    node *temp = head;
    node *start;
    int count = 1;
    while (temp->next!=NULL)
    {
       if(count == pos) start = temp;
       temp = temp->next;
       count++; 
    }
    temp->next = start;
}

bool detection_of_cycle(node *head)
{
    node *slow = head;
    node *fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow)
        {
            return true;
        }
    }
    return false;
}

void remove_cycle(node *head)
{
        node *slow = head;
    node *fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow)
        {
            fast = head;
            while (fast->next!=slow->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = NULL;
            return;
        }
    }
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
makecycle(head,4); 
cout << detection_of_cycle(head) << endl;
remove_cycle(head);
display(head);

return 0;
}
