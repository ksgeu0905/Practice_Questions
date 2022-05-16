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
    int depth(TreeNode * root,int x,int d){
        if(!root)return 0;
        if(root->val==x)
            return d;
        int l=depth(root->left,x,d+1);
        if(l==0)
          return depth(root->right,x,d+1);
        return l;
    }
    int parent(TreeNode* root,int x){
        if(!root)return 0;
        if((root->left && root->left->val==x )||(root->right && root->right->val==x))return root->val;
        if(parent(root->left,x)==0)
            return parent(root->right,x);
        return parent(root->left,x);
    
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(depth(root,x,0)!=depth(root,y,0))return false;
        if(parent(root,x)==parent(root,y))return false;
        return true;
    }
};