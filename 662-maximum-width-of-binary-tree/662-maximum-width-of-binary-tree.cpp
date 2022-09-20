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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            int min=q.front().second;
            long long f,l;
            for(int i=0;i<size;i++){
                auto t=q.front();
                q.pop();
                if(i==0)f=t.second-min;
                if(i==size-1)l=t.second-min;
                if(t.first->left)q.push({t.first->left,(t.second-min)*2+1});
                if(t.first->right)q.push({t.first->right,(t.second-min)*2+2});
            }
            if(ans < l-f+1)ans=l-f+1;
            
        }
        return ans;
    }
};