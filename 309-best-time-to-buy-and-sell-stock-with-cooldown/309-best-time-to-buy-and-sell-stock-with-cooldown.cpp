class Solution {
public:
//     int find(vector<int>& prices,int ind,int buy,vector<vector<int>>&dp){
//         if(ind>=prices.size())return 0;
//         if(dp[ind][buy]!=-1)return dp[ind][buy];
        
//         int price=0;
//         if(buy){
//             price=max(-prices[ind] + find(prices,ind+1,0,dp), find(prices,ind+1,1,dp));
//         }
//         else{
//             price=max(prices[ind] + find(prices,ind+2,1,dp),find(prices,ind+1,0,dp));
//         }
//         return dp[ind][buy]=price;
//     }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        for(int ind= n-1;ind>=0;ind--){
            for(int buy=1;buy>=0 ; buy--){
                int price=0;
                if(buy){
                    price=max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                }
                else{
                    price=max(prices[ind] + dp[ind+2][1],dp[ind+1][0]);
                }
                dp[ind][buy]=price;
            }
        }
        return dp[0][1];
    }
};