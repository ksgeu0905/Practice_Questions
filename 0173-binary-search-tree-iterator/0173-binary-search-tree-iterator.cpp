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
class BSTIterator {
public:
    vector<int>in;
    TreeNode * temp;
    int i=0;
    BSTIterator(TreeNode* root) {
        temp=root;
        inorder(temp);
    }
    void inorder(TreeNode * root){
        if(!root)return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    int next() {
        return in[i++];
    }
    
    bool hasNext() {
        if(i<in.size())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */