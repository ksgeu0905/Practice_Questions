class Solution {
public:
    int find(int e,int n,vector<vector<int>>&dp){
        if(n==0 || n==1)return n;
        if(e==1)return n;
        if(dp[e][n]!=-1)return dp[e][n];
        int ans=INT_MAX;
        int l=1,r=n,temp=0;
        while(l<=r){
            int k=(l+r)/2;
            int below=find(e-1,k-1,dp);
            int above=find(e,n-k,dp);
            temp=1+max(above,below);
            if(below<above)
                l=k+1;
            else
                r=k-1;
            ans=min(ans,temp);
        }
        return dp[e][n]=ans;
    }
    int superEggDrop(int k, int n) {
         vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return find(k,n,dp);
    }
};