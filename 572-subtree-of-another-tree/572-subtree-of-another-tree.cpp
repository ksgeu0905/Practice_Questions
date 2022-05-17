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
    bool ans=false;
    bool match(TreeNode * root,TreeNode * subRoot){
        if(root && subRoot){
            bool a=match(root->left,subRoot->left);
            bool b=match(root->right,subRoot->right);
            
            if((root->val==subRoot->val) && a&& b)return true;
            else return false;
        }
        else if(!root && !subRoot)return true;
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return ans;
        if(root->val==subRoot->val){
            if(match(root,subRoot)){
                ans=true;
                return ans;
            }
        }
        isSubtree(root->left,subRoot);
        isSubtree(root->right,subRoot);
        return ans;
    }
};