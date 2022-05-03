#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        void Insert(Node** head,Node** tail,int x){
            Node* p=NULL;
            p=new Node;
            p->data=x;
            p->next=NULL;
            if(*head==NULL)
                *head=*tail=p;
            else{
                (*tail)->next=p;
                *tail=p;
            }
        }
        void display(Node *head){
            while(head){
                cout<<head->data<<" ";
                head=head->next;
            }
        }
        void reverse(Node** head,Node** tail){
            Node* p=NULL,*q=*head,*r=(*head)->next;
            while(q){
                q->next=p;
                p=q;
                q=r;
                r=r?r->next:NULL;
            }
            p=(*head);
            *head=*tail;
            *tail=p;
        }
};
int main(){
    Node* head=NULL,*tail=NULL;
    Node list;
    int x;
    do{
        cout<<"Enter Value: ";
        cin>>x;
        list.Insert(&head,&tail,x);
        cout<<"Want to insert more?\n1: yes\n2: no\n";
        cin>>x;
    }while(x==1);
    cout<<"Before reversing the list is: \n";
    list.display(head);
    list.reverse(&head,&tail);
    cout<<"\nAfter reversing the list is: \n";
    list.display(head);
    return 0;
}