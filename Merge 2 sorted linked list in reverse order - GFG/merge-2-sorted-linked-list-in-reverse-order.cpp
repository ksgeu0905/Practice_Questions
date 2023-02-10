//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

struct Node * mergeResult(Node *node1,Node *node2)
{
    vector<int>temp;
    Node*p1=node1,*p2=node2;
    while(p1 && p2){
        if(p1->data < p2->data){
            temp.push_back(p1->data);
            p1=p1->next;
        }
        else{
            temp.push_back(p2->data);
            p2=p2->next;
        }
    }
    while(p1){
            temp.push_back(p1->data);
            p1=p1->next;
    }
    while(p2){
            temp.push_back(p2->data);
            p2=p2->next;
    }
    p1=node1;
    while(p1->next)p1=p1->next;
    p1->next=node2;
    p1=node1;
    int i=temp.size()-1;
    while(i>=0){
        p1->data=temp[i];
        i--;
        p1=p1->next;
    }
    return node1;
}