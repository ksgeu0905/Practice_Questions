class Solution {
public:
    bool fun(vector<int> & nums,int ind,int s_take,int sum,vector<int> & dp){
        if(ind<0)
            return s_take==(sum/2);
        if(dp[s_take]!=-1)
        {
            return dp[s_take];
        }
        bool t=fun(nums,ind-1,s_take+nums[ind],sum,dp);
        bool nt=fun(nums,ind-1,s_take,sum,dp);
        return dp[s_take] = t || nt;

    }
    bool canPartition(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s%2==1)
            return false; 
        vector<int> dp(s,-1);
        return fun(nums,nums.size()-1,0,s,dp);
    }
};