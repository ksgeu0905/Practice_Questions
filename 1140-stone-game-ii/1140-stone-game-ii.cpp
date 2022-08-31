class Solution {
public:
    int find(int i,int m,vector<int>&piles,vector<vector<int>>&dp){
        if(i>=piles.size()){
            return 0;
        }
        if(dp[i][m]!=-1)return dp[i][m];
        int alice=0,bob=0;
        int ans=INT_MIN;
        for(int j=0;j<2*m;j++){
            if(i+j<piles.size())alice+=piles[i+j];
            bob=find(i+j+1,max(m,j+1),piles,dp);
            ans=max(ans,alice-bob);
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int sum=accumulate(piles.begin(),piles.end(),0);
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size()*2,-1));
        int diff=find(0,1,piles,dp);
        return (sum+diff)/2;
    }
};