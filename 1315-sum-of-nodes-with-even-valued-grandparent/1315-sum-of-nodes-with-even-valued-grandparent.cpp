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
    int s;
    void find_sum(TreeNode * root){
        if(root==NULL)return;
        if((root->val) % 2==0 ){
            
            if(root->left && root->left->left)s+=root->left->left->val;
            if(root->left && root->left->right)s+=root->left->right->val;
            if(root->right && root->right->left)s+=root->right->left->val;
            if(root->right && root->right->right)s+=root->right->right->val;
        }
        find_sum(root->left);
        find_sum(root->right);
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        find_sum(root);
        return s;
    }
};