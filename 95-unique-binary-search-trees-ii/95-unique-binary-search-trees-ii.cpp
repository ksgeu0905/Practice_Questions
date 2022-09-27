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
    TreeNode * insert(TreeNode * root,int x){
        if(!root)return new TreeNode(x);
        if(root->val < x)root->right=insert(root->right,x);
        else if(root->val > x)root->left=insert(root->left,x);
        return root;
    }
    TreeNode* create(vector<int>v){
        TreeNode * root=NULL;
        for(int i=0;i<v.size();i++){
            root=insert(root,v[i]);
        }
        return root;        
    }
    bool is_similar(TreeNode * r1,TreeNode *r2){
        if(!r1 && !r2)return true;
        if(r1==NULL || r2==NULL)return false;
        return (r1->val == r2->val) && is_similar(r1->left,r2->left)&&is_similar(r1->right,r2->right);
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        vector<TreeNode*>ans;
        
        do{
            TreeNode*r=NULL;
            r=create(v);
            int f=0;
            for(int i=0;i<ans.size();i++){
                if(is_similar(ans[i],r)==true)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                ans.push_back(r);
        }while(next_permutation(v.begin(),v.end()));
        
        return ans;
    }
};