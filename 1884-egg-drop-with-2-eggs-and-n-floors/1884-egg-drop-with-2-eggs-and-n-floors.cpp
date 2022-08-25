class Solution {
public:
    int find(int e,int n,vector<vector<int>>&dp){
        if(n==0 || n==1)return n;
        if(e==1)return n;
        if(dp[e][n]!=-1)return dp[e][n];
        int ans=INT_MAX;
        for(int k=1;k<=n;k++){
            ans=min(ans,1+max(find(e-1,k-1,dp),find(e,n-k,dp)));
        }
        return dp[e][n]=ans;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        return find(2,n,dp);
    }
};