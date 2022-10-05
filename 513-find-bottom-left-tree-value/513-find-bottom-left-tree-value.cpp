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
    int maxi=0;
    int ans=0;
    void find(TreeNode* root,int d){
        if(!root)return;
        if(d>maxi){
            maxi=d;
            ans=root->val;
        }
        find(root->left,d+1);
        find(root->right,d+1);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        find(root,1);
        return ans;
    }
};