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
    int find(TreeNode* root,int max){
        if(!root)return 0;
        if(root->val >= max){
            return 1+find(root->left,root->val)+find(root->right,root->val);
        }
        return find(root->left,max)+find(root->right,max);
    }
    int goodNodes(TreeNode* root) {
        return find(root,INT_MIN);
    }
};