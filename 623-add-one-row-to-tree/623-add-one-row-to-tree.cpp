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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode * > q;
        q.push(root);
        int d=1;
        if(depth==1){
            TreeNode * r=new TreeNode(val);
            r->left=root;
            return r;
        }
        while(d<depth-1){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto t = q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            d++;
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode * l= new TreeNode(val);
            TreeNode * r=new TreeNode(val);
            l->left=it->left;
            r->right=it->right;
            it->left=l;
            it->right=r;
            
        }
        return root;
    }
};