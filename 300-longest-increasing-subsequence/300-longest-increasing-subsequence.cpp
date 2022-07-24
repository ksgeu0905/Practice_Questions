class Solution {
public:
    int find(vector<int>& nums,int ind,int last,vector<vector<int>> &dp){
        if(ind==nums.size())return 0;
        if(dp[ind][last+1]!=-1)return dp[ind][last+1];
        int pick=INT_MIN,n_pick=INT_MIN;
        
        n_pick=find(nums,ind+1,last,dp);
        if(last==-1 || nums[ind]>nums[last]){
            pick=1+find(nums,ind+1,ind,dp);
        }
        return dp[ind][last+1]=max(pick,n_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return find(nums,0,-1,dp);
    }
};