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
    int lheight(TreeNode * root){
        int c=0;
        while(root){
            c++;
            root=root->left;
        }
        return c;
    }
    int rheight(TreeNode* root){
        int c=0;
        while(root){
            c++;
            root=root->right;
        }
        return c;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int l=lheight(root),r=rheight(root);
        if(l==r){
            return pow(2,l)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};