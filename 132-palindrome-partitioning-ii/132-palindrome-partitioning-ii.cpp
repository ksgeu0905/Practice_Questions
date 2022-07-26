class Solution {
public:
    bool ispalin(string &s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    int find(string &s,int i,vector<int> &dp){
        if(i==s.length())return 0;
        
        if(dp[i]!=-1)return dp[i];
        int mini=INT_MAX;
        string temp="";
        for(int ind=i;ind<s.length();ind++){
            temp+=s[ind];
            if(ispalin(temp)){
                int ans=1+find(s,ind+1,dp);
                mini=min(mini,ans);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        vector<int>dp(s.length(),-1);
        return find(s,0,dp)-1;
    }
};