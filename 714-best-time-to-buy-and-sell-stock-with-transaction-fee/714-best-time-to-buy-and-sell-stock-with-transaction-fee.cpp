class Solution {
public:
     int find(vector<int>& prices,int ind,int buy,int &fee,vector<vector<int>> &dp){
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        int price=0;
        if(buy==1){
            price=max(-prices[ind]+find(prices,ind+1,0,fee,dp), find(prices,ind+1,1,fee,dp));
        }
        else{
            price=max(prices[ind]-fee+find(prices,ind+1,1,fee,dp), find(prices,ind+1,0,fee,dp));
        }
        return dp[ind][buy]=price;
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return find(prices,0,1,fee,dp);
    
    }
};