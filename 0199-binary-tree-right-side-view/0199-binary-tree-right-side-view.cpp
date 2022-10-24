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
    vector<int> rightSideView(TreeNode*root){
        vector<int>ans;
        if(!root)return ans;
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            mp[t.second]=t.first->val;
            if(t.first->left)q.push({t.first->left,t.second+1});
            if(t.first->right)q.push({t.first->right,t.second+1});
        }
        for(auto i :mp)ans.push_back(i.second);
        return ans;
    }
};