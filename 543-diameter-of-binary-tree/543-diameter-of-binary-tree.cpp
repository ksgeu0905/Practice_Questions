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
    int depth(TreeNode * root){
        if(!root)return 0;
        int l=1+depth(root->left);
        int r=1+depth(root->right);
        return max(l,r);
    }
    void func(TreeNode* root,int & max){
        if(!root)return;
        int x=depth(root->left)+depth(root->right);
        if(x>max){
            max=x;
        }
        func(root->left,max);
        func(root->right,max);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int max1=-1;
        func(root,max1);
        return max1;
    }
};