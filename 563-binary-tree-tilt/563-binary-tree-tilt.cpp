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
    int sum(TreeNode * root){
        if(!root)return 0;
        return root->val+sum(root->left)+sum(root->right);
    }
    void cal(TreeNode* root,int &s){
        if(!root)return;
        s+=abs(sum(root->left)-sum(root->right));
        cal(root->left,s);
        cal(root->right,s);
    }
    int findTilt(TreeNode* root) {
        if(!root)return 0;
        int s=0;
        cal(root,s);
        return s;
    }
};