#include <bits/stdc++.h>
using namespace std;
class Btnode{
    Btnode* left;
    int data;
    Btnode* right;
    public:
        Btnode* create(Btnode* root){
            int x;
            cout<<"Enter value: ";
            cin>>x;
            char c;
            Btnode* newnode=new Btnode();
            newnode->data=x;
            cout<<"Do you want to Enter its child (y/n): ";
            cin>>c;
            if(c=='n')
                newnode->right=newnode->left=NULL;
            else{
                cout<<"Enter left of "<<x<<" : ";
                newnode->left=create(newnode->left);
                cout<<"Enter right of "<<x<<" : ";
                newnode->right=create(newnode->right);
            }
            return newnode;
        }
        void inorder(Btnode* root){
            if(!root)return;
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
        int count_nodes(Btnode* root){
            if(!root)
                return 0;
            return 1+count_nodes(root->left)+count_nodes(root->right);
        }
};
int main(){
    Btnode * root,Bt;
    root=Bt.create(root);
    cout<<"Inorder: ";
    Bt.inorder(root);
    cout<<"\nTotal no of nodes in the BT is : "<<Bt.count_nodes(root);
    return 0;
}