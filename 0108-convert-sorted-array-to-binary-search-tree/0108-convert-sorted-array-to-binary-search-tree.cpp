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
   TreeNode * bst(vector<int>&nums, int left, int right){
        if(left <= right){
            int mid = (left + right)/2;
            TreeNode * node = new TreeNode(nums[mid]);
            node -> left = bst(nums, left, mid - 1);
            node -> right = bst(nums, mid + 1, right);
            return node;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return bst(nums, 0, n - 1);
    }
};