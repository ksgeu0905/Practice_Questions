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
    vector<double> averageOfLevels(TreeNode* root) {
            double sum=0;
            int c=0;
            queue<TreeNode*> q;
            vector<double> ans;
             if(!root)return ans;

            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                TreeNode* temp=q.front();
                q.pop();
                if(temp==NULL){
                    ans.push_back(sum/c);
                    sum=0;
                    c=0;
                    if(q.empty())
                        return ans;
                    q.push(NULL);
                }
                else{
                    sum+=temp->val;
                    c++;
                    if(temp->left)q.push(temp->left);
                    if(temp->right)q.push(temp->right);
                }
            }
            return ans;
    }
};