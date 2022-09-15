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
    int maxi=-1e9;
    int find(TreeNode * root){
        if(!root)return 0;
        int l=max(0,find(root->left));
        int r=max(0,find(root->right));
        maxi=max(maxi,l+r+root->val);
        
        return max(l,r)+root->val;
    }    
    
    int maxPathSum(TreeNode* root) {
        find(root);
        return maxi;
    }
};