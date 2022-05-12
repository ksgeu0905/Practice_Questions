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
        void inorder(BtNode* root){
            if(!root)return;
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
        int count_nodes_degree_2(BtNode * root){
            if(!root)return 0;
            if(root->left!=NULL && root->right!=NULL)
                return 1+count_nodes_degree_2(root->left)+count_nodes_degree_2(root->right);
            else
                return count_nodes_degree_2(root->left)+count_nodes_degree_2(root->right);
        }
};
int main(){
    BtNode BT,*root;
    root=BT.create(root);
    cout<<"\nInorder: ";
    BT.inorder(root);
    cout<<"\nNumber of nodes with Degree 2 are: "<<BT.count_nodes_degree_2(root);

    return 0;
}