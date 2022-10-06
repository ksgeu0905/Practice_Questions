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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        TreeNode * parent=NULL,*curr=root;
        while(curr  && curr->val>val){
            parent=curr;
            curr=curr->right;
        }
        if(parent==NULL){
            newnode->left=root;
            root=newnode;
            return root;
        }
        else if(curr==NULL){
            parent->right=newnode;
        }
        else{
            newnode->left=curr;
            parent->right=newnode;
        }
        return root;
    }
};