class Solution {
public:
    int find(vector<int> & prices,int ind,int buy, int trans, vector<vector<vector<int>>>& dp){
        if(trans==0)return 0;
        if(ind==prices.size())return 0;
        if(dp[ind][buy][trans]!=-1)return dp[ind][buy][trans];
        int price=0;
        
        if(buy){
            price=max((-prices[ind] + find(prices,ind+1,0,trans,dp)),                                                  (find(prices,ind+1,1,trans,dp)));
        }
        else{
            price=max((prices[ind] + find(prices,ind+1,1,trans-1,dp)),                                                  (find(prices,ind+1,0,trans,dp)));
        }
        return dp[ind][buy][trans]=price;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return find(prices,0,1,2,dp);
    }
};