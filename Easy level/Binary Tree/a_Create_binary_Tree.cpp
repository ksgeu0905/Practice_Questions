#include <bits/stdc++.h>
using namespace std;
class BtNode{
        BtNode *left;
        int data;
        BtNode *right;
        BtNode *root;
    public:
        BtNode(){
            root=left=right=NULL;
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
        void preorder(BtNode* root){
            if(!root)return;
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
        void postorder(BtNode* root){
            if(!root)return;
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
        void inorder(BtNode* root){
            if(!root)return;
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
};
int main(){
    BtNode BT,*root;
    root=BT.create();
    cout<<"Preorder: ";
    BT.preorder(root);
    cout<<"\nPostorder: ";
    BT.postorder(root);
    cout<<"\nInorder: ";
    BT.inorder(root);

    return 0;
}