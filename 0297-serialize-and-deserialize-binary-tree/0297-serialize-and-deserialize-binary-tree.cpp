/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            if(t){
                s+=to_string(t->val)+',';
                if(t->left)q.push(t->left);
                else q.push(NULL);
                if(t->right)q.push(t->right);
                else q.push(NULL);
            }
            else s+="n," ; 
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        int i=0;
        string temp="";
        while(s[i]!=','){
            temp+=s[i];
            i++;
        }
        i++;
        if(temp=="n")
            return NULL;
        TreeNode * root=new TreeNode(stoi(temp));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty() && i<s.length()){
            auto t=q.front();
            q.pop();
            string val1="";
            while(s[i]!=','){
                val1+=s[i];
                i++;
            }
            i++;
            if(val1=="n"){
                t->left=NULL;
            }
            else{
                t->left=new TreeNode(stoi(val1));
                q.push(t->left);
            }
            
            string val2="";
            while(s[i]!=','){
                val2+=s[i];
                i++;
            }
            i++;
            if(val2=="n"){
                t->right=NULL;
            }
            else{
                t->right=new TreeNode(stoi(val2));
                q.push(t->right);
            }
            
        }
        return root;
        
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));