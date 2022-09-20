/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root || q==root)return root;
        map<TreeNode*,TreeNode*>m;
        queue<TreeNode*>qu;
        vector<int>temp;
        qu.push(root);
        m[root]=NULL;
        while(!qu.empty()){
            TreeNode*t=qu.front();
            qu.pop();
            if(t->left){
                qu.push(t->left);
                m[t->left]=t;
            }
            if(t->right){
                qu.push(t->right);
                m[t->right]=t;
            }
        }
        temp.push_back(q->val);
        TreeNode*x=m[q];
        while(x){
            temp.push_back(x->val);
            x=m[x];
        }
        x=p;
        while(1){
            if(find(temp.begin(),temp.end(),x->val)!=temp.end())return x;
            x=m[x];
        }
        return NULL;
        
    }
};