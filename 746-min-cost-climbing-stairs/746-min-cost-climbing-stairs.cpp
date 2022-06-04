class Solution {
public:
    int fun(vector<int>&cost,int ind, vector<int>&dp)
    {
        if(ind==cost.size()-1)return cost[ind];
        if(ind>cost.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
      
        int first = cost[ind] + fun(cost,ind+1,dp);
        
        int second = cost[ind] + fun(cost,ind+2,dp);
        return dp[ind] = min(first,second);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp1(cost.size(),-1);
        int ans1 = fun(cost,0,dp1);
        auto it = cost.begin();
        cost.erase(it);
        vector<int>dp2(cost.size(),-1);
        int ans2 = fun(cost,0,dp2);
        return min(ans1, ans2);   
    }
};