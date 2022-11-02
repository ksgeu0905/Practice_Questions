class Solution {
public:
    int find(int i,vector<int>&cost,vector<int>&dp){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int a = cost[i]+find(i+1,cost,dp);
        int b = cost[i]+find(i+2,cost,dp);
        return dp[i]=min(a,b);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp1(cost.size(),-1),dp2(cost.size(),-1);
        int x = find(0,cost,dp1);
        int y = find(1,cost,dp2);
        return min(x,y);
    }
};