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
    TreeNode* func(vector<int>& inorder, vector<int>& post,int sin,int ein,int spo,int epo){
        if(sin==ein)return new TreeNode(inorder[sin]);
        if(sin>ein || spo>epo)return NULL;
        int x=post[epo];
        TreeNode* temp=new TreeNode(x);
        int y=find(inorder.begin()+sin,inorder.begin()+ein,x)-inorder.begin();
        temp->left=func(inorder,post,sin,y-1,spo,spo+y-sin-1);
        temp->right=func(inorder,post,y+1,ein,spo+y-sin,epo-1);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return func(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};