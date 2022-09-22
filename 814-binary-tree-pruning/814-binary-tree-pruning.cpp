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
    TreeNode* find(TreeNode* cur){
        if(!cur)return NULL;
        
        cur->left= find(cur->left);
        cur->right=find(cur->right);
        if(!cur->left && !cur->right && cur->val==0){
            return NULL;
        }
        return cur;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return find(root);
    }
};