class Solution {
public:
    int find(vector<int>& prices,int ind,int buy,vector<vector<int>>&dp){
        if(ind>=prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        int price=0;
        if(buy){
            price=max(-prices[ind] + find(prices,ind+1,0,dp), find(prices,ind+1,1,dp));
        }
        else{
            price=max(prices[ind] + find(prices,ind+2,1,dp),find(prices,ind+1,0,dp));
        }
        return dp[ind][buy]=price;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return find(prices,0,1,dp);
    }
};