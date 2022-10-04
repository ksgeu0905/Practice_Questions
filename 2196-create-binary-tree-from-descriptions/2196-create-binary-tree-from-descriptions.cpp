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
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        map<int,pair<int,int>>mp;
        map<int,int>rcheck;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i][2]==1){
                mp[arr[i][0]].first = arr[i][1];
            }
            else{
                mp[arr[i][0]].second=arr[i][1];
            }
            rcheck[arr[i][1]]=1;
            if(rcheck.find(arr[i][0])==rcheck.end()){
                rcheck[arr[i][0]]=0;
            }
        }
        int r,x;
        for(auto i : rcheck){
            if(i.second==0)
            {
                r=i.first;
                break;
            }
        }
        queue<TreeNode*>q;
        TreeNode * root=new TreeNode(r);
        q.push(root);
        while(!q.empty()){
            TreeNode * temp=q.front();
            x=temp->val;
            q.pop();
            if(mp[x].first!=0){
                temp->left = new TreeNode(mp[x].first);
                q.push(temp->left);
            }
            if(mp[x].second!=0){
                temp->right = new TreeNode(mp[x].second);
                q.push(temp->right);
            }            
        }
        
        
        return root;
    }
};