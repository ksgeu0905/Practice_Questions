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
    TreeNode * LCA(TreeNode * root,TreeNode * p,TreeNode * q){
        if(!root)return NULL;
        if(root==p || root==q)return root;
        
        TreeNode * l=LCA(root->left,p,q);
        TreeNode * r=LCA(root->right,p,q);
        
        if(!l)return r;
        if(!r)return l;
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        vector<TreeNode*>v;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto t=q.front();
                v.push_back(t);
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            if(!q.empty())v.clear();
        }
        if(v.size()==1)return v[0];
        
        return LCA(root,v[0],v[v.size()-1]);
    }
};