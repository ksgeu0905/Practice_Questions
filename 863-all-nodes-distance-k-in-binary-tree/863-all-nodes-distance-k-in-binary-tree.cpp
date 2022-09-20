/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>m;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            if(t->left){
                m[t->left]=t;
                q.push(t->left);
            }
            if(t->right){
                m[t->right]=t;
                q.push(t->right);
            }
        }
        vector<int>visited(500,0);
        int dis=0;
        q.push(target);
        visited[target->val]=1;
        while(dis!=k){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto t =q.front();
                q.pop();
                if(m.find(t)!=m.end() && visited[m[t]->val]==0){
                    q.push(m[t]);
                    visited[m[t]->val]=1;
                }
                if(t->left && visited[t->left->val]==0){
                    q.push(t->left);
                    visited[t->left->val]=1;
                }
                if(t->right && visited[t->right->val]==0){
                    q.push(t->right);
                    visited[t->right->val]=1;
                }
            }
            dis++;
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};