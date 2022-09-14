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
    int dep(TreeNode * temp){
        if(!temp)return 0;
        return max(1+dep(temp->left),1+dep(temp->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int x=abs(dep(root->left)-dep(root->right));
        return x<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};