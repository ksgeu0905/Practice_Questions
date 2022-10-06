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
    map<int,int>mp;
    int postorder(TreeNode * root){
        if(!root)return 0;
        int l=postorder(root->left);
        int r=postorder(root->right);
        int s=l+r+root->val;
        mp[s]++;
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        postorder(root);
        int maxi=0;
        vector<int>ans;
        for(auto i : mp)maxi=max(maxi,i.second);
        
        for(auto i :mp){
            if(i.second == maxi)ans.push_back(i.first);
        }
        return ans;
    }
};