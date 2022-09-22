class Solution {
public:
    int find(TreeNode* root,int maxi,int min){
        if(!root)return abs(maxi-min);
        int l=0,r=0;
        if(root->val > maxi){
            l=find(root->left,root->val,min);
            r=find(root->right,root->val,min);
        }
        else if(root->val < min){
             l=find(root->left,maxi,root->val);
             r=find(root->right,maxi,root->val);
        }
        else{
             l=find(root->left,maxi,min);
             r=find(root->right,maxi,min);
        }
        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return find(root,root->val,root->val);
    }
};