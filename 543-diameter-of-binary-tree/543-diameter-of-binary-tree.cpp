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
    int dep(TreeNode*root){
        if(!root)return 0;
        return max(dep(root->left),dep(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int l=dep(root->left);
        int r=dep(root->right);
        return max(l+r,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};