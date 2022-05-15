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
    string convert(vector<int> s){
        int l=s.size();
        string str="";
        for(int i=0;i<l-1;i++){
            str=str+to_string(s[i])+"->";
        }
        str+=to_string(s[l-1]);
        return str;
    }
    void find_path(TreeNode* root,vector<int> &s,vector<string>& ans){
        if(!root)return;
        s.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            string str=convert(s);
            ans.push_back(str);
            return;
        }
        if(root->left){
            find_path(root->left,s,ans);
            s.pop_back();
        }
        if(root->right){
            find_path(root->right,s,ans);
            s.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        vector<int> s;
        find_path(root,s,ans);
        return ans;
    }
};