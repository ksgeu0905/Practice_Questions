class Solution {
public:
    int fun(int ind , vector<int> nums,vector<int>&dp){
        if(ind==0)return nums[0];
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int pick=nums[ind]+fun(ind-2,nums,dp);
        int not_pick=0+fun(ind-1,nums,dp);
        
        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return fun(nums.size()-1,nums,dp);
    }
};