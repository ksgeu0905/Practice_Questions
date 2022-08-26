class Solution {
public:
    int find(int i,vector<int>&dp){
        if(i==1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        if(i%2==0){
            ans=1+find(i/2,dp);
        }
        else{
            ans=1+find(3*i+1,dp);
        }
        return dp[i]=ans;
    }
    int getKth(int lo, int hi, int k) {
        vector<vector<int>>sorted(hi-lo+1,vector<int>(2,0));
        vector<int>dp(1e6,-1);
        for(int i=lo;i<=hi;i++){
            sorted[i-lo][0]=find(i,dp);
            sorted[i-lo][1]=i;
        }
        sort(sorted.begin(),sorted.end());
        
        return sorted[k-1][1];
    }
};