class Solution {
public:
    // int find(vector<int> & coins,int ind,int tar,vector<vector<int>> & dp){
    //     if(ind==0){
    //         if(tar%coins[0]==0)
    //             return tar/coins[0];
    //         return 1e9;
    //     }
    //     if(dp[ind][tar]!=-1)return dp[ind][tar]; 
    //     int n_pick=find(coins,ind-1,tar,dp);
    //     int pick=INT_MAX;
    //     if(tar>=coins[ind]){
    //         pick=1+find(coins,ind,tar-coins[ind],dp);
    //     }
    //     return dp[ind][tar]=min(n_pick,pick);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)
                dp[0][t]=t/coins[0];
            else
                dp[0][t]=1e9;
        }
        for(int ind = 1 ;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                    int n_pick=dp[ind-1][tar];
                    int pick=INT_MAX;
                    if(tar>=coins[ind]){
                        pick=1+dp[ind][tar-coins[ind]];
                    }
                    dp[ind][tar]=min(pick,n_pick);
            }
        }
        int x=dp[n-1][amount];
        if(x>=1e9)
            return -1;
        else return x;
    } 
};