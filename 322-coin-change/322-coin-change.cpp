class Solution {
public:
    int find(vector<int> & coins,int ind,int tar,vector<vector<int>> & dp){
        if(ind==0){
            if(tar%coins[0]==0)
                return tar/coins[0];
            return 1e9;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar]; 
        int n_pick=find(coins,ind-1,tar,dp);
        int pick=INT_MAX;
        if(tar>=coins[ind]){
            pick=1+find(coins,ind,tar-coins[ind],dp);
        }
        return dp[ind][tar]=min(n_pick,pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int x=find(coins,coins.size()-1,amount,dp);
        if(x==1e9)
            return -1;
        else return x;
    }
};