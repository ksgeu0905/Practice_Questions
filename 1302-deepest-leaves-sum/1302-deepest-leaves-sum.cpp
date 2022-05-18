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
    int s=0;
    int depth(TreeNode * root){
        if(!root)return 0;
        int l=1+depth(root->left);
        int r=1+depth(root->right);
        return max(l,r);
    }
    void find_sum(TreeNode*root,int d){
        if(!root)return;
        if(d==1){
            s+=root->val;
            return;
        }
        find_sum(root->left,d-1);
        find_sum(root->right,d-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int c=depth(root);
        find_sum(root,c);
        return s;
    }
};