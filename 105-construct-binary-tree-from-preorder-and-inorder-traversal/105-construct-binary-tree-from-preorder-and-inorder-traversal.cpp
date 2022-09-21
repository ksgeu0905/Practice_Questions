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
    TreeNode* func(vector<int>& pre, vector<int>& in,int sin,int ein,int spe,int epe){
        if(sin==ein)return new TreeNode(in[sin]);
        if(sin>ein || spe>epe)return NULL;
        TreeNode* root=new TreeNode(pre[spe]);
        int y=find(in.begin()+sin,in.begin()+ein,pre[spe])-in.begin();
        root->left=func(pre,in,sin,y-1,spe+1,y-sin+spe);
        root->right=func(pre,in,y+1,ein,y-sin+spe+1,epe);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return func(pre,in,0,in.size()-1,0,pre.size()-1);
    }
};