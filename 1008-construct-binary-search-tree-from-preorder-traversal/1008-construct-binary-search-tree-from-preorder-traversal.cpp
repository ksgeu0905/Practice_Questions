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
    TreeNode* func(vector<int>& preorder,int s,int e){
        if(s>e)return NULL;
        TreeNode * temp=new TreeNode(preorder[s]);
        int x=lower_bound(preorder.begin()+s+1,preorder.begin()+e+1,preorder[s])-preorder.begin();
       
        temp->left=func(preorder,s+1,x-1);
        temp->right=func(preorder,x,e);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return func(preorder,0,preorder.size()-1);
    }
};