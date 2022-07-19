class Solution {
public:
    int find(vector<int>& coins,int tar,int ind,vector<vector<int>> & dp){
        if(tar==0)
            return 1;
        if(tar<0)
            return 0;
        if(ind==coins.size()-1){
            if(tar%coins[ind]==0)
                return 1;
            return 0;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        int n_pick=find(coins,tar,ind+1,dp);
        int pick=0;
        if(coins[ind]<=tar)
            pick=find(coins,tar-coins[ind],ind,dp);
        return dp[ind][tar]=n_pick+pick;
            
    
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
       return find(coins,amount,0,dp); 
    }
};