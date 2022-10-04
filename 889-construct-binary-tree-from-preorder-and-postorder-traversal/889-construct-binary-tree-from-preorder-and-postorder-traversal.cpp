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
    int find_ind(vector<int>& post,int x,int s,int e){
        for(int i=s;i<=e;i++){
            if(x==post[i])return i;
        }
        return -1;
    }
    TreeNode * make_tree(vector<int>& pre, vector<int>& post,int spre,int epre,int spost,int epost){
        if(spre == epre)return new TreeNode(pre[spre]);
        if(spre>epre || spost >epost)return NULL;
        
        TreeNode * root= new TreeNode(pre[spre]);
        int y= find_ind(post,pre[spre+1],spost,epost);
        
        root->left = make_tree(pre,post,spre+1,spre+1+y-spost,spost,y);
        root->right = make_tree(pre,post,spre+2+y-spost,epre,y+1,epost-1);
        return root;
        
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        return make_tree(pre,post,0,n-1,0,n-1);
    }
};