class Solution {
public:
    int find(int n,vector<int> &dp){
        if(n == 0)
            return 1;
        if(dp[n]!=-1)return dp[n];
        int x=0,y=0;
        x = find(n-1,dp);
        if(n>=2)
            y = find(n-2,dp);
        return dp[n]=x+y;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
       return find(n,dp); 
    }
};