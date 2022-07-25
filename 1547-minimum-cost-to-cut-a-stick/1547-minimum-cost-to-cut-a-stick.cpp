class Solution {
public:
    int func(vector<int>&cuts,int i,int j,vector<vector<int>>&dp){
        if(i>j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int mini=INT_MAX,steps;
        for(int ind=i;ind<=j;ind++){
            steps=cuts[j+1]-cuts[i-1] + func(cuts,i,ind-1,dp) +func(cuts,ind+1,j,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return func(cuts,1,c,dp);
    }
};