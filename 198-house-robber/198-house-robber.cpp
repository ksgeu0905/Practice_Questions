class Solution {
public:
    int find(vector<int>&nums, int ind,vector<int> & dp){
        if(ind==0)return nums[0];
        if(ind<0)return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        
        int pick= nums[ind] + find(nums,ind-2,dp);
        int n_pick = 0 + find(nums,ind-1,dp);
        return dp[ind] = max(pick,n_pick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return find(nums,nums.size()-1,dp);
    }
};