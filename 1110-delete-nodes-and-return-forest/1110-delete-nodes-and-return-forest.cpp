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
    vector<TreeNode*> ans;
    TreeNode * find(TreeNode* root, vector<int>& to_delete){
        if(!root)return NULL;
        root->left = find(root->left,to_delete);
        root->right = find(root->right,to_delete);
        if(binary_search(to_delete.begin(), to_delete.end(), root->val)){
            if(root->left)ans.push_back(root->left);
            if(root->right)ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*>delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.begin(),to_delete.end());
        auto x= find(root,to_delete);
        if(x){
            ans.push_back(root);
        }
        
        return ans;
    }
};