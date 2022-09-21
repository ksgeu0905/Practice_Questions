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
    void flatten(TreeNode* root) {
        if(!root)return;
        if(root->left){
            TreeNode* temp=root->right,*t=root;
            root->right=root->left;
            root->left=NULL;
            while(t->right){
                t=t->right;
            }
            t->right=temp;
        }
        flatten(root->right);
    }
};