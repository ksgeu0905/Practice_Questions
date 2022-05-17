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
    set<int> ans;
    void inorder(TreeNode * root){
        if(!root)return;
        inorder(root->left);
        ans.insert(root->val);
        if(ans.size()>2)
            ans.erase(--ans.end());
        inorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)return -1;
        inorder(root);
        if(ans.size()<2)return -1;
        return *(--ans.end());
    }
};