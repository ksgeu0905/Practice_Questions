class Solution {
public:
    void find(int n,string s,vector<string> & ans,int sum){
        if(sum==0 && n==0){
            ans.push_back(s);
            return;
        }
        if(n>0)
        find(n-1,s+"(",ans,sum+1);
        if(sum>0)
        find(n,s+")",ans,sum-1);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        find(n,"",ans,0);
        return ans;
    }
};