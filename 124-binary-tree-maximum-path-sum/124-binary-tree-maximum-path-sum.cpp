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
    int find(TreeNode * root){
        if(!root)return 0;
        int l=root->val+find(root->left);
        int r=root->val+find(root->right);
        int x=root->val;
        
        return max(max(l,r),x);
    }    
    
    int maxPathSum(TreeNode* root) {
        if(!root)return -1e9;
        int p1=find(root->left);
        int p2=find(root->right);
        int x=max(max(root->val,root->val+p1+p2),max(root->val+p1,root->val+p2));
        int l=maxPathSum(root->left);
        int r=maxPathSum(root->right);
        return max(x,max(l,r));
    }
};