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

    void find_path(TreeNode* root,vector<int> &s,vector<vector<int>>& ans,int sum){
        if(!root)return;
        s.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(accumulate(s.begin(),s.end(),0)==sum)
                ans.push_back(s);
            return;
        }
        if(root->left){
            find_path(root->left,s,ans,sum);
            s.pop_back();
        }
        if(root->right){
            find_path(root->right,s,ans,sum);
            s.pop_back();
        }
    }
 
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>>ans;
        vector<int> s;
        find_path(root,s,ans,targetSum);
        return ans;
    }
};