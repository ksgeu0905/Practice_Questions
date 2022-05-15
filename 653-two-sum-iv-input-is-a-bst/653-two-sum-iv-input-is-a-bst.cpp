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
    bool search(TreeNode*root,int k,TreeNode* temp){
        if(!root)return false;
        if(root->val==k && root!=temp)return true;
        if(k<root->val)return search(root->left,k,temp);
        if(k>root->val)return search(root->right,k,temp);
        return false;
    }
    bool find(TreeNode* root,int k,TreeNode* temp){
         if(!root)return false;
        if(search(temp,k-root->val,root))
            return true;
        return find(root->left,k,temp) || find(root->right,k,temp);
    }
    bool findTarget(TreeNode* root, int k) {
       if(!root)return false;
        return find(root,k,root);
        
    }
};