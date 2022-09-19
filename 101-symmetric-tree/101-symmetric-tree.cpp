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
    bool find(TreeNode* r1,TreeNode* r2){
        if(!r1 && !r2)return true;
        if(!r1 || !r2)return false;
        if(r1->val != r2->val)return false;
        return find(r1->left,r2->right) && find(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return find(root->left,root->right);
    }
};