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
    vector<pair<int,pair<int,int>>>temp;
    void inorder(TreeNode* root,int x,int r){
        if(!root)return;
        temp.push_back({x,{r,root->val}});
        inorder(root->left,x-1,r+1);
        inorder(root->right,x+1,r+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorder(root,0,0);
        sort(temp.begin(),temp.end());
        vector<vector<int>>ans;
        vector<int>l;
        l.push_back(temp[0].second.second);
        for(int i=1;i<temp.size();i++){
            if(temp[i].first == temp[i-1].first){
                l.push_back(temp[i].second.second);
            }
            else{
                ans.push_back(l);
                l.clear();
                l.push_back(temp[i].second.second);
            }
        }
        ans.push_back(l);
        return ans;    
    }
};