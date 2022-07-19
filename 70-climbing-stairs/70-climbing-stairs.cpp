class Solution {
public:
    int find(int n,vector<int> &dp){
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int step_1=find(n-1,dp);
        int step_2=find(n-2,dp);
        return dp[n]=step_1+step_2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return find(n,dp);
    }
};