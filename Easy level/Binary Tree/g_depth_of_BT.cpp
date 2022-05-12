#include <bits/stdc++.h>
using namespace std;
class BtNode{
        BtNode *left;
        int data;
        BtNode *right;
    public:
        BtNode(){
            left=right=NULL;
            data=-1;
        }
        BtNode* create(BtNode* root){
            int x;
            cout<<"Enter value to insert: ";
            cin>>x;
            BtNode* newnode=new BtNode();
            newnode->data=x;
            if(x==-1)
                return NULL;
            cout<<"Enter left child of "<<x<<" : \n";
            (newnode->left)=create(newnode->left);
            cout<<"Enter right child of "<<x<<" : \n";
            (newnode->right)=create(newnode->right);
            return newnode;
        }
        void inorder(BtNode* root){
            if(!root)return;
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
        int depth(BtNode * root){
            if(!root)return 0;
            int left=1+depth(root->left);
            int right=1+depth(root->right);
            return max(left,right);
        }
};
int main(){
    BtNode BT,*root;
    root=BT.create(root);
    cout<<"\nInorder: ";
    BT.inorder(root);
    cout<<"\nDepth of BT : "<<BT.depth(root);

    return 0;
}