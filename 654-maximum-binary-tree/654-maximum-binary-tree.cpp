/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr; right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        if(a.size()==0)
            return NULL;
        int i=*max_element(a.begin(), a.end());
        TreeNode* temp=new TreeNode(i);
        vector<int> v1,v2;
        int it;
        for(it=0;it<a.size();it++){
            if(a[it]==i)break;
            v1.push_back(a[it]);
        }
        it++;
        while(it<a.size())
            v2.push_back(a[it++]);
        temp->left=constructMaximumBinaryTree(v1);
        temp->right=constructMaximumBinaryTree(v2);
        return temp;
    }
};