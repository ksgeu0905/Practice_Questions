/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;
        find_postorder(root,ans);
        return ans;
    }
    void find_postorder(Node *root,vector<int> & ans){
        if(!root)return;
        for(auto c:root->children)
            find_postorder(c,ans);
        ans.push_back(root->val);
    }
};