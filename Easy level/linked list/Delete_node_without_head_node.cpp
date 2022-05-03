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
        void deleteNode(Node* node) {
            Node* temp=node->next,*temp2=node;
            while(temp){
                node->data=temp->data;
                node=temp;
                temp=temp->next;
            }
            while(temp2->next->next){
                temp2=temp2->next;
            }
            temp2->next=NULL;
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
    list.display(head);
    cout<<"\nWhich node you want to delete? : ";
    cin>>x;
    Node* temp=head;
    while(x>1){
        temp=temp->next;x--;
    }
    list.deleteNode(temp);
    list.display(head);
    return 0;
}