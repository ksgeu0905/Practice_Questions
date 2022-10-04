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
    int ans;
    map<int,int>mp;
    int odd;
    void find(TreeNode * root){
        if(!root)return ;
        mp[root->val]++;
        if(mp[root->val]%2)odd++;
        else odd--;
        if(!root->left && !root->right){
            if(odd<2)
                ans++;            
        }
        find(root->left);
        find(root->right);
        mp[root->val]--;
        if(mp[root->val]%2)odd++;
        else odd--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        find(root);
        return ans;
    }
};