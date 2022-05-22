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
class FindElements {
public:
    TreeNode * node;
    FindElements(TreeNode* root) {
        node=root;
        node->val=0;
        recover(node);
    }
    void recover(TreeNode * root){
        if(!root)return;
        if(root->left){
            root->left->val=2*root->val+1;
        }
        if(root->right){
            root->right->val=2*root->val+2;
        }
        recover(root->left);
        recover(root->right);
    }
    bool find(int target) {
        return find_target(node,target);
    }
    bool find_target(TreeNode * root,int x){
        if(!root)return false;
        if(root->val==x)return true;
        return find_target(root->left,x)||find_target(root->right,x);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */