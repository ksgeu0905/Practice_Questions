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
    TreeNode * isuc(TreeNode * root){
        root=root->right;
        while(root && root->left){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode * is=NULL;
        if(!root)return NULL;
        if(!root->left && !root->right && root->val==key){
            delete(root);
            return NULL;
        }
        if(key<root->val)root->left= deleteNode(root->left,key);
        else if(key>root->val)root->right=deleteNode(root->right,key);
        else{
            is=isuc(root);
            if(is==NULL){
                return root->left;
            }
            else{
                root->val=is->val;
                root->right=deleteNode(root->right,is->val);
            }
        }
        return root;
    }
};