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
    void inorder(TreeNode* root,vector<int> & a1){
        if(!root)
            return;
        if(root->left==NULL && root->right==NULL)
            a1.push_back(root->val);
        inorder(root->left,a1);
        inorder(root->right,a1);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a1;
        vector<int>a2;
        inorder(root1,a1);
        inorder(root2,a2);
        if(a1==a2)
            return true;
        return false;
    }
};