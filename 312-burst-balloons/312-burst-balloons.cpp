class Solution {
public:
    int find(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=INT_MIN,steps;
        for(int ind=i;ind<=j;ind++){
            steps =  ((i-1)<0 ? 1:nums[i-1]) * nums[ind] * ((j+1)>=nums.size() ? 1:nums[j+1])
                +find(nums,i,ind-1,dp) + find(nums,ind+1,j,dp);
            maxi=max(maxi,steps);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return find(nums,0,n-1,dp);
    }
};