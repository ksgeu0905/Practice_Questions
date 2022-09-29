/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode * root,vector<int>&in){
        if(!root)return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* find(vector<int>&in,int s,int e){
        if(s==e)return new TreeNode(in[s]);
        if(s>e)return NULL;
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=find(in,s,mid-1);
        root->right=find(in,mid+1,e);
        return root;        
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        return find(in,0,in.size()-1);
    }
};