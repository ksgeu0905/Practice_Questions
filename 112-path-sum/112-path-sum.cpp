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
     void find_path(TreeNode* root,vector<int> &s,int sum,bool & a){
        if(!root)return;
        s.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(accumulate(s.begin(),s.end(),0)==sum)
                a=true;
            return;
        }
        if(root->left){
            find_path(root->left,s,sum,a);
            s.pop_back();
        }
        if(root->right){
            find_path(root->right,s,sum,a);
            s.pop_back();
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        bool ans=false;
        vector<int> s;
        find_path(root,s,targetSum,ans);
        return ans;
    }
};