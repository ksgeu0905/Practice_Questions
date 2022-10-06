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
class CBTInserter {
public:
    TreeNode * r;
    queue<TreeNode*>q;
    CBTInserter(TreeNode* root) {
        r=root;
        q.push(root);
        while(1){
            auto t=q.front();
            int f=0;
            if(t->left){
                q.push(t->left);
                f++;
            }
            if(t->right){
                q.push(t->right);
                f++;
            }
            if(f==2)q.pop();
            else break;
        }
    }
    
    int insert(int val) {
        TreeNode * node = new TreeNode(val);
        q.push(node);
        auto t=q.front();
        if(t->left==NULL){
            t->left=node;
            return t->val;
        }
        else if(t->right ==NULL){
            t->right=node;
            q.pop();
        }
        
        return t->val;
        
    }
    
    TreeNode* get_root() {
        return r;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */