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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int>t;
        if(!root)return ans;
        queue<TreeNode *>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(t);
                t.clear();
                if(q.empty()){
                    reverse(ans.begin(),ans.end());
                    return ans;
                }
                q.push(NULL);
            }
            else{
                t.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};