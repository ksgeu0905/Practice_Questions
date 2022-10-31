#define mod 1000000007
class Solution {
public:
    int func(int i,int n,int k,int t,vector<vector<int>>&dp){
        if(i>n){
            if(t==0)return 1;
            return 0;
        }
        if(t<=0)return 0;
        if(dp[i][t]!=-1)return dp[i][t];
        long long ans =0;
        for(int x=1;x<=k;x++){
            ans = (ans%mod + func(i+1,n,k,t-x,dp)%mod)%mod;
        }
        return dp[i][t]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return func(1,n,k,target,dp);
    }
};