#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    void insert(Node **head,Node **tail, int k)
    {
       
         if(*head == NULL)
         {
              *head = new Node();
             (*head)->data = k;
             (*head)->next = NULL;
             *tail = *head;
         }
         else
         {
             Node *ptr = new Node();
             ptr->data = k;
             ptr->next = NULL;

             (*tail)->next = ptr;
             (*tail)= (*tail)->next;
         }
    }
    void display(Node *head)
    {
        Node *ptr = head;
        while(ptr)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
    Node* removeNthFromEnd(Node* head, int n) {
        int count=0;
        Node* ptr = head,*ptr2 = NULL;
        while(ptr)
        {
            count++;
            ptr=ptr->next;
        }
        count = count-n;
        if(count==0)
        {
            head = head->next;
                return head;
        }
        ptr = head;
        while(count>1)
        {
            ptr=ptr->next;
            count--;
        }
        ptr2 = ptr->next;
        ptr->next = ptr2->next;
        delete(ptr2);
        return head;
        
    }
};
int main()
{
    Node list;
   Node *head = NULL;
   Node *tail = NULL;
   while(1)
   {
   cout<<"1. To insert more"<<endl;
   cout<<"2. To display"<<endl;
   cout<<"3. To Stop"<<endl;
   cout<<"4. To remove Nth Node from end"<<endl;
   cout<<"Press any choice"<<endl;
  
   int a;
   cin>>a;
   int k;
   int node;
   switch (a)
   {
   case 1:
       cout<<"Enter number to insert"<<endl;
        cin>>k;
       list.insert(&head,&tail,k);
       break;
   case 2:
        list.display(head);
        break;
    case 3:
         exit(0);
         break;
    case 4:
         cout<<"Enter the node to be deleted"<<endl;
         cin>>node;
         head = list.removeNthFromEnd(head,node);
         list.display(head);
         break;

   default:
      cout<<"Invalid choice!!"<<endl;
       break;
   }
   }
   
}